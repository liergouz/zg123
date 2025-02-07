
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0424
#define THIS_PERFORM    04241
#define PF_START       "04241"
#define PF_NAME        "困魔术"

#define SKILL_LEVEL     10
#define TIME_INTERVAL   12
#define SUB_MP          20
#define ADD_AP          0
#define ADD_INTERVAL    6


// 函数：获取符法效果
int get_cast_seal() { return 9102; }    // 符纸顺旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：10级\n消耗道具：符纸1张\n    封锁一个敌人的行动，使其6秒内无法移动。该技能对玩家无效。";
        result = sprintf(HIC"%s\n" NOR "技能需求：%d级\n消耗道具：符纸1张\n法力消耗：%d点\n冷却时间：%d秒\n    封锁一个敌人的行动，使其6秒内无法移动。该技能对玩家无效。",
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL );
        return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp, interval, ret;

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

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                x = get_x(who);  y = get_y(who);
        }
        else if( objectp( who = me->get_enemy_2() ) && inside_screen_2(me, who) )
        {
                x = get_x(who);  y = get_y(who);
        }
        else
        {
                z = get_z(me);

                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) )
                {
                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
                        me->set_time( "pf", time() );

                        me->to_front_xy(x, y);
                        user = get_scene_object_2(me, USER_TYPE);
                        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);
                        item->add_amount(-3);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->add_2("go_count.count2",9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_ONCE );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        me->add_mp(-mp);
        set_heart_count_2(me, 9);
        me->add_2("go_count.count2",9);
        item->add_amount(-1);

        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who),
                34829, 2, OVER_BODY, 34829, 2, OVER_BODY, PF_ONCE );        
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 1;    // 执行成功
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        if( get_effect(who, EFFECT_CHAR_9145) ) return 2;    // 执行成功
        ret = CHAR_FIGHT_D->cast_done(me, who, 0, -100);
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,110);
        if( ret > 0  )
        {
        	if (!who) return 1;
        	if (who->is_anti_effect()) return 2;
        	if (who->is_user()) return 1;
	        if( get_effect(who, EFFECT_CHAR_NO_MOVE) ) return 1;    // 执行成功
	        if (who->get_perform("02222#")) return 1;
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_NO_MOVE, ADD_INTERVAL);    // 小心准备 me
                if( get_heart_state(who) == MAGIC_STAT ) send_user( user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
                send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_NO_MOVE), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 34821, 10, UNDER_FOOT, PF_LOOP );	        
                CHAR_CHAR_D->init_loop_perform(who);
        }        
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
	name = PF_NAME;
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP, 1, 10, MAGIC_ACT_BEGIN, 0, 9, "符纸");
}
