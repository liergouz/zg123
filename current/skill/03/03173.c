
// 开关技能  TIPS:[PF_SWITCH]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <action.h>

#define THIS_SKILL      0317
#define THIS_PERFORM    03173
#define PF_FLAG        "03173"
#define PF_TIME        "03173#"
#define PF_NAME        "护体金罡"

#define SKILL_LEVEL     20
#define TIME_INTERVAL   2
#define SUB_MP		0
#define SUB_YUAN        1
#define ADD_AP		( 3 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*15/10 )    // 警告：level 得准备好

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：20级\n    给予队友或自己金罡保护，每次受到近身的物理攻击，反弹伤害给予攻击者。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        if (cur_level % 2 ==0)
	        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d点\n冷却时间：%d秒\n    给予队友或自己保护，每次受到近身攻击，反弹%d点伤害给予攻击者。效果持续10分钟。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    每次受到近身攻击，反弹%d点伤害给予攻击者。",
	        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 2);
	else
	        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d点\n冷却时间：%d秒\n    给予队友或自己保护，每次受到近身攻击，反弹%d点伤害给予攻击者。效果持续10分钟。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    每次受到近身攻击，反弹%d点伤害给予攻击者。",
	        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 1);		      
        return result;
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_save(PF_TIME) )
                return sprintf( PF_NAME "：\n　　每次受到近身的物理攻击，反弹 %d 点伤害给予攻击者。\n",
                        me->get_save(PF_TIME) );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp, i, size, z;
        object *user, *team, *all, owner;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_FLAG) ) < interval ) return 1;    // 小心准备 level

        if (who!=me)
        {
        	if (who->is_user())
        	{
	        	if (!me->get_leader()||me->get_leader()!=who->get_leader())
		        {
		                printf( ECHO "只能对自己或者队友使用" PF_NAME );
		                return 1;
		        }
		}
		else
		{
			owner  = who->get_owner();
			if (owner!=me)
			{
		        	if (!owner || !me->get_leader()||me->get_leader()!=owner->get_leader())
			        {
			                printf( ECHO "只能对自己或者队友使用" PF_NAME );
			                return 1;
			        }
			}
		}
		if ("/sys/user/attack"->can_use_help(me, who)==0)
		{				
			printf( ECHO "你无法对对方使用" PF_NAME );
			return 1;				
		}		
        }

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN );
                return 1;
        }
	if (who->is_anti_effect()) return 1;
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
         me->add_2("go_count.count2",9);
        interval = 600;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_FLAG, time() );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 31731, 1, OVER_BODY, PF_ONCE );
	user = get_scene_object_2(who, USER_TYPE);
	set_effect(who, EFFECT_REBOUND, interval);
	send_user( who, "%c%w%w%c", 0x81, 3173, get_effect_3(who, EFFECT_REBOUND), EFFECT_GOOD );
	send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3173, 1, EFFECT_GOOD );
	send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 32511, 1, OVER_BODY, PF_ONCE );
	if (who->is_user()) who->set_save(PF_TIME, ADD_AP);
	else who->set(PF_TIME, ADD_AP);
	CHAR_FIGHT_D->set_enmity2(me,who, 330 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*70);
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;
        string name;
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL )
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_FLAG) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, MAGIC_ACT_BEGIN, 0, 9, 0);
}

void effect_done(object me)
{
        send_user( me, "%c%w%w%c", 0x81, 3173, 0, EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3173, 0, EFFECT_GOOD );
	if (me->is_user()) me->set_save(PF_TIME, 0);
	else me->set(PF_TIME, 0);
}