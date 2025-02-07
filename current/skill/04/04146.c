
// 单体＋多体远程技能  TIPS:[PF_CAST_2]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0414
#define THIS_PERFORM    04146
#define PF_START       "04146"
#define PF_NAME        "天雷破"

#define SKILL_LEVEL     35
#define TIME_INTERVAL   me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 20, 4000)    // 警告：me 得准备好
#define SUB_MP          me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 80, 120)    // 警告：me 得准备好
#define ADD_SIZE        me->get_pf_value_2(THIS_SKILL, SKILL_LEVEL_SQUARE, 4, 800)    // 警告：me 得准备好

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取符法效果
int get_cast_seal() { return 41100; }    // 符纸逆旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］多体远程法术攻击，连锁攻击多个目标。消耗法力：%d，再次使用需间隔 %d 秒，%s%d 级可用\n",
                SUB_MP, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( !objectp( item = present("符纸", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有符纸才能使用“" PF_NAME "”。" );
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
                        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
                        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);
                        item->add_amount(-1);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d,%d", z, x, y, level ) );
			send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        		me->set_perform( PF_START, time() );
                        return 1;
                }
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
        item->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object *char, who;
        string arg;
        int z, x, y;
        int level, i, size;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d,%d", z, x, y, level) != 4 )    // 支持坐标，找人两种方法
        {
                if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
                if( !objectp( who = find_char(arg) ) ) return 1;

                z = get_z(who);  x = get_x(who);  y = get_y(who);
        }
        else    who = 0;

        level = ADD_SIZE;    // 小心准备 me

        char = get_range_object(z, x, y, 10, CHAR_TYPE) + get_range_object(z, x, y, 10, USER_TYPE) - ({ me });
//      char = get_range_object(z, x, y, 10, CHAR_TYPE);

        size = sizeof(char) - level;
        for( i = 0; i < size; i ++ ) char -= ({ char[ random( sizeof(char) ) ] });

        if( objectp(who) ) char = char - ({ who }) + ({ who });    // 加入首选对象(可是玩家)

        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] )
        {
                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                        41461, 1, OVER_BODY, 41462, 1, OVER_BODY, 41463, 1, OVER_BODY, PF_ONCE );

//              if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;

                CHAR_FIGHT_D->cast_done(me, who);
        }

        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数：能否使用特技
void can_perform( object me )
{
        int level, interval, interval2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL;    // 小心准备 me
        interval2 = interval - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
}
