
// 单体远程技能  TIPS:[PF_CAST]  变异

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <action.h>

#define THIS_SKILL      0368
#define THIS_PERFORM    03681
#define PF_START       "03681"
#define PF_NAME        "窥物"

#define SKILL_LEVEL     30
#define TIME_INTERVAL   2
#define SUB_MP          10

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］偷窥目标所携带物品。消耗法力：%d，再次使用需间隔 %d 秒，%s%d 级可用\n",
                SUB_MP, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 level

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                x = get_x(who);  y = get_y(who);
        }
/*      else if( objectp( who = me->get_enemy_2() ) && inside_screen_2(me, who) )
        {
                x = get_x(who);  y = get_y(who);
        }       */
        else
        {
                z = get_z(me);

                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) return 1;

/*              if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) 
                {
                        me->set_perform( PF_START, time() );
                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
                        me->set_time( "pf", time() );

                        me->to_front_xy(x, y);
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 0, get_d(me), 0 );

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }       */
        }

        if( !is_player(who) )
        {
                printf( ECHO "不能对游戏管理员使用“" PF_NAME "”。" );
                return 1;
        }
        if( who->is_store_open() )
        {
                printf( ECHO "不能对摆摊的人使用“" PF_NAME "”。" );
                return 1;
        }
        
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

//      me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        send_user( me, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
//      send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );

        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object who, *inv, *inv2, item;
        string arg;
        int busy, level, rate, i, size, size2;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 36811, 1, OVER_BODY, PF_ONCE );
//      send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 36811, 1, OVER_BODY, PF_ONCE );

        if( !inside_screen_2(me, who) ) return 1;

        rate = 5 + 100 * level / 10 * me->get_level() / range_value( who->get_level(), 1, MAX_NUMBER );
        if( get_effect(me, EFFECT_CHAR_BLIND) ) rate /= 2;    // 失明(命中减半)

        if( random(100) < range_value(rate, 0, 40) )
        {
                send_user( me, "%c%c%d%s", 0x76, 0, who->get_number(), sprintf( "%s(%d)\n%s\n%s\n%s\n%s\n", 
                        who->get_name(), who->get_number(), 
                        who->get_city_name() == "" ? "－－" : who->get_city_name(), 
                        who->get_fam_name() == "" ? "－－" : who->get_fam_name(),
                        who->get_org_name() == "" ? "－－" : who->get_org_name(),
                        who->get_title() ) );
                send_user( me, "%c%c%c%d%d%c%d%w%s", 0x76, 0xff, 
                        who->get_armor_code(), who->get_armor_color_1(), who->get_armor_color_2(), 
                        who->get_head_code(), who->get_head_color(), who->get_weapon_code_2(),
                        USER_RANK_D->get_rank(who) );

                inv = who->get_all_equip();
                for( i = 0, size = sizeof(inv); i < size; i ++ ) if( objectp( item = inv[i] ) )
                        send_user( me, "%c%c%w%w%c%s", 0x76, get_d(item), 
                                item->get_picid_2(), item->get_amount(), item->get_item_type_2(),
                                sprintf( "%-12s%s", item->get_name(), ITEM_ITEM_D->get_look_string(me, item) ) );

                size2 = 2 + random(level / 15);    // 窥看道具数

                size = sizeof( inv = all_inventory(who, 1, MAX_CARRY) );

                if( !size ) inv2 = ({ });
                else if( size < size2 ) inv2 = inv;
                else
                {
                        for( i = 0, inv2 = ({ }); i < size2; i ++ ) inv2 += ({ inv[ random(size) ] });
                }

                me->delete_2(PF_FLAG_03681);

                for( i = 0, size = sizeof(inv2); i < size; i ++ ) 
                        if(     objectp( item = inv2[i] ) 
                        &&     !item->get_no_drop() && !item->get_no_get() && !item->get_no_give()
                        &&     !item->is_locked() )
                {
                        send_user( me, "%c%c%w%w%c%s", 0x76, get_d(item), 
                                item->get_picid_2(), item->get_amount(), item->get_item_type_2(),
                                sprintf( "%-12s%s", item->get_name(), ITEM_ITEM_D->get_look_string(me, item) ) );
                        me->set_2( sprintf( "%s.%d", PF_FLAG_03681, get_d(item) ), 1 );
                }
        }
        else    write_user(who, ECHO "您觉得背后冷飕飕的……");

//      me->to_front_eachother(who);

        busy = get_effect(me, EFFECT_CHAR_BUSY) + 3;
        set_effect(me, EFFECT_CHAR_BUSY, busy);
        send_user(me, "%c%c%c", 0x3d, 9, busy);

        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
}
