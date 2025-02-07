
// 召唤技能  TIPS:[PF_CALL]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0413
#define THIS_PERFORM    04132
#define PF_START       "04132"
#define PF_NAME        "天兵召唤"

#define SKILL_LEVEL     15
#define SUB_MP          ( 55 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 25 )
#define TIME_INTERVAL 	2

#define INIT_HP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 264, 4)    // 警告：me 得准备好
#define INIT_AP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 60, 20)    // 警告：me 得准备好
#define INIT_DP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 45, 30)    // 警告：me 得准备好
#define INIT_PP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 40, 30)    // 警告：me 得准备好
#define INIT_SP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 72, 50)    // 警告：me 得准备好

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取符法效果
int get_cast_seal() { return 9103; }    // 符纸逆旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：15级\n消耗道具：符纸3张\n    召唤天兵协助战斗。天兵攻击时一定几率使敌人陷入负伤状态。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n消耗道具：符纸3张\n法力消耗：%d点\n冷却时间：%d秒\n    召唤天兵协助战斗。天兵攻击时一定几率使敌人陷入负伤状态。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    提升天兵500点气血；\n    提升天兵55点物理攻击力；\n    提升天兵150点物理防御力\n    提升天兵150点法术防御力；\n    提升天兵40点躲闪。",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, 2, cur_level*10+SKILL_LEVEL );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( me->get_perform(PF_START) == time() ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( objectp( me->get("soldier") ) ) 
        {
                printf( ECHO "您已经召唤了其它的僵尸／天兵／鬼卒。" );
                return 1;
        }

        if( !objectp( item = present("符纸", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有符纸才能使用“" PF_NAME "”。" );
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
        item->add_amount(-3);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->add_2("go_count.count2",9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );

        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object npc;
        string arg;
        int z, x, y, x0, y0, p;
        int level, cp, pp, i, size;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        me->set_perform( PF_START, time() );
        level = to_int(arg);
        send_user(me, "%c%c%w%s", 0x5a, 0, 6, "召唤天兵中……");	                
        me->set_2("conjure.type", 4132);
        me->set_2("conjure.level", level);
        set_effect(me, EFFECT_CONJURE, 6);        
/*
        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0 + random(3) - 1, y0 + random(3) - 1, IS_CHAR_BLOCK) )
        {
                npc = new( "/npc/std/4132" );
                npc->set_name( sprintf( "天兵(%s)", me->get_name() ) );
                npc->set_max_hp( INIT_HP );    // 小心准备 me
                npc->set_ap( INIT_AP );
                npc->set_dp( INIT_DP );
                npc->set_pp( INIT_PP );
                npc->set_sp( INIT_SP );
                npc->upgrade_level(1);
                cp = me->get_cp();
                pp = me->get_pp();
                npc->add_max_hp( (cp + pp) / 2 );
                npc->add_ap( cp  * 8 / 10 );
                npc->add_dp( pp * 60 / 100 );
                npc->add_pp( pp * 2 / 100 );
                npc->add_sp( cp * 3 / 10 );

                npc->set_owner(me);
                npc->set_level_0(level);    // 道法神通
//              npc->set_action(1);

                npc->set_city_name( me->get_city_name() );    // 用于战场
                npc->set_manager( me->get_manager() );
                npc->set_org_name( me->get_org_name() );

                x = p / 1000;  y = p % 1000;
                npc->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41321, 1, OVER_BODY, 41322, 1, OVER_BODY, 41323, 1, UNDER_FOOT, PF_ONCE );
                me->set("soldier", npc);

                NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
        }
*/
        return 2;    // 执行成功
}

// 函数：命令处理
int perform_action_npc( object me, object who )
{
        object *user;

        if( objectp( me->get("soldier") ) ) return 0;

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", me->get_skill(THIS_SKILL) ) );

        return 1;
}

// 函数：法术处理
int cast_done_npc( object me )
{
        object npc;
        string arg;
        int z, x, y, x0, y0, p;
        int level, cp, pp, i, size;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        level = to_int(arg);

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0 + random(3) - 1, y0 + random(3) - 1, IS_CHAR_BLOCK) )
        {
                npc = new( "/npc/std/4132" );
//              npc->set_name( sprintf( "天兵(%d)", me->get_number() ) );
//              npc->set_level(1);
                npc->set_max_hp( INIT_HP );    // 小心准备 me
                npc->set_ap( INIT_AP );
                npc->set_dp( INIT_DP );
                npc->set_pp( INIT_PP );
                npc->set_sp( INIT_SP );
                npc->upgrade_level(1);
                cp = me->get_cp();
                pp = me->get_pp();
                npc->add_max_hp( (cp + pp) * 7 / 10 );
                npc->add_ap( cp * 12 / 100 );
                npc->add_dp( pp * 32 / 100 );
                npc->add_sp( cp / 10 );

                npc->set_owner(me);
                npc->set_level_0(level);    // 道法神通
//              npc->set_action(1);

                npc->set_city_name( me->get_city_name() );    // 用于战场
                npc->set_manager( me->get_manager() );
                npc->set_org_name( me->get_org_name() );

                x = p / 1000;  y = p % 1000;
                npc->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41321, 1, OVER_BODY, 41322, 1, OVER_BODY, 41323, 1, UNDER_FOOT, PF_ONCE );
                me->set("soldier", npc);

                NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
        }

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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = 2 - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 9, "符纸");
}
