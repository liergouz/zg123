
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0501
#define THIS_PERFORM    05016
#define PF_START       "05016"
#define PF_TIME        "05016#"
#define PF_NAME        "斗转星移"

#define SKILL_LEVEL     50
#define TIME_INTERVAL   15
#define SUB_MP          300 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/15*100
#define ADD_INTERVAL    300
#define ADD_EFFECT	150 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/15*50


// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：50级\n消耗道具：阵旗5个\n    命转易理，斗转星移，增强自身150点法术攻击力，减少20％自身所受到的伤害，且无法使用任何医疗系的技能。\n    再次使用可中止斗转星移的效果。\n";
        cur_level = (level - SKILL_LEVEL)/15 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n消耗道具：阵旗5个\n冷却时间：%d秒\n    命转易理，斗转星移，增强自身%d点法术攻击力，减少20％自身所受到的伤害，且无法使用任何医疗系的技能。\n    再次使用可中止斗转星移的效果。\n\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    增强自身%d点法术攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*15+SKILL_LEVEL, ADD_EFFECT + 50 );
        return result;	
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        return sprintf( PF_NAME "\n    增强自身法术攻击力，减少20％自身受到的所有伤害。但处于该状态下，无法使用任何医疗系的技能\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int level, mp, interval;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;
        
	if ( me->get_perform(PF_TIME))
	{
		me->set_perform(PF_START, time());
		me->set_perform(PF_TIME, 0);
		send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        	send_user( me, "%c%w%w%c", 0x81, 5016, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 5016, 0, EFFECT_GOOD );				
		printf( ECHO "您取消了“" PF_NAME "”。" );
		USER_ENERGY_D->count_cp(me);
		return 1;		
	}	
        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;        
        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }	
        if( !objectp( item = present("阵旗", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有阵旗才能使用“" PF_NAME "”。" );
                return 1;
        }   	
        interval = TIME_INTERVAL;
        user = get_scene_object_2(me, USER_TYPE);
        me->add_mp(-mp);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
      	item->add_amount(-5);        
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );      	
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, ADD_EFFECT );
        send_user( me, "%c%w%w%c", 0x81, 5016, 30000, EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 5016, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 
                2214, 1, OVER_BODY, PF_ONCE );
	USER_ENERGY_D->count_cp(me);	
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/15+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP,1, 1, MAGIC_ACT_BEGIN, 0, 5, "阵旗");
}
