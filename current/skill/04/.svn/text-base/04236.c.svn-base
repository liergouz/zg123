
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0423
#define THIS_PERFORM    04236
#define PF_START       "04236"
#define PF_NAME        "寒冰法阵"

#define SKILL_LEVEL     35
#define TIME_INTERVAL   10
#define SUB_MP          ( 50 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 19 * 16 )
#define ADD_AP          ( 150 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 19 * 40 )
#define ADD_INTERVAL    6


// 函数：获取符法效果
int get_cast_seal() { return 42100; }    // 符纸顺旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：35级\n消耗道具：符纸5张\n    瞬间施放一个寒冰保护圈，使以自己为中心7×7范围内的所有敌人陷入6秒的冻结状态。并造成法术攻击力为150的法术伤害。";
        cur_level = (level - SKILL_LEVEL)/19 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n消耗道具：符纸5张\n法力消耗：%d点\n冷却时间：%d秒\n    瞬间施放一个寒冰保护圈，使以自己为中心7×7范围内的所有敌人陷入6秒的冻结状态。并造成法术攻击力为%d的法术伤害。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    寒冰法阵可造成法术攻击力为%d点的法术伤害。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level*19+SKILL_LEVEL, ADD_AP + 40 );     	
        return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int level, mp, interval;
        int z, i, size;
        int ret, cp;
	object *char;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( !objectp( item = present("符纸", me, 1, MAX_CARRY*4) ) )    // || item->get_amount() < 3
        {
                printf( ECHO "您得有符纸才能使用“" PF_NAME "”。" );    // "使用“" PF_NAME "”得准备三张符纸。"
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        me->add_mp(-mp);
        item->add_amount(-5);

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
	z = get_z(me), x = get_x(me), y=get_y(me);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                4236, 1, UNDER_FOOT, 4236, 1, UNDER_FOOT, PF_ONCE );
	char = get_range_object(z, x, y, 3, USER_TYPE) + get_range_object(z, x, y, 3, CHAR_TYPE) - ({ me });
	cp = me->get_cp();
	me->set_cp(ADD_AP);
	for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] )
	{		
		if ( who->get("anti_no_move") )	//抗冻结
		{
	                continue;		
		}
	        if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;   // 执行成功	        
	        if( get_effect(who, EFFECT_CHAR_NO_MOVE) ) continue;    // 执行成功
	        if (who->is_anti_effect()) continue;
                send_user(who, "%c%c%c", 0x3d, 241, 1);    // 更改走路步数
                set_effect(who, EFFECT_CHAR_NO_MOVE, ADD_INTERVAL);    // 小心准备 me
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_NO_MOVE), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
	        CHAR_FIGHT_D->cast_done(me, who);
	        if ( who && !who->is_die() )
	        	CHAR_FIGHT_D->set_enmity(me,who,90);
	        if (who ) send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9012, 1, OVER_BODY, PF_LOOP );
	        if (who) CHAR_CHAR_D->init_loop_perform(who);
	}	       
	me->set_cp(cp);
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{	
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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/19+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}
