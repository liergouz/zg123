
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0231
#define THIS_PERFORM    02313
#define PF_START       "02313"
#define PF_NAME        "漫天缤纷"

#define SKILL_LEVEL     26
#define TIME_INTERVAL   15
#define SUB_MP          40 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 7
#define ADD_CP		45 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 10

// 函数：获取法力
int get_sub_mp( object me ) 
{ 
        int level = me->get_skill(THIS_SKILL);
        return SUB_MP; 
}

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：26级\n    释放剑气，提升45点法术攻击力，并使攻击目标陷入6秒的冰冻状态。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    释放剑气，提升%d点法术攻击力，并使攻击目标陷入6秒的冰冻状态。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    攻击时提升%d点法术攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_CP, cur_level*10+SKILL_LEVEL, ADD_CP + 10 );
        return result;	
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( time() - me->get_perform(PF_START) < TIME_INTERVAL  ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }
        if( me->get_weapon_code() != SWORD ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备剑。" );
                return 1;
        }        
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) 
        {
        	notify( "你处于封印状态中。" );
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
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 30, get_d(me), 0 );
//                      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);
//                      item->add_amount(-1);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 6);
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
        if (me->get_gender()==2) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 30, get_d(me), 0 );
        else send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 30, get_d(me), 0 );


        me->add_mp(-mp);
//      item->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 6);
        me->add_2("go_count.count2",6);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object who;
        string arg;
        int z, x, y;
        int level, ret;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                return 1;    // 打到空地
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 23131, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->cast_done(me, who, ADD_CP);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);
        if (!who) return 2;
        if (who->is_anti_effect()) return 2;
        if ( ret>0 )
        {
	        if(     get_effect(who, EFFECT_CHAR_LAZY)
	        ||      get_effect(who, EFFECT_CHAR_LAZY_0) ) return 2;    // 执行成功
                set_effect(who, EFFECT_CHAR_LAZY, 6);
                send_user( who, "%c%w%w%c", 0x81, 9013, get_effect_3(who, EFFECT_CHAR_LAZY), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9013, 1, EFFECT_BAD );
                send_user(who, "%c%c%c", 0x3d, 241, 1);    // 更改走路步数
        }

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
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
				if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 10, 2, 30, 6, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 10, 1, 30, 6, 0);
}
