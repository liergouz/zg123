
// 多体远程技能  TIPS:[PF_CAST_AREA]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0424
#define THIS_PERFORM    04242
#define PF_START       "04242"
#define PF_NAME        "金光法阵"

#define SKILL_LEVEL     20
#define TIME_INTERVAL   4
#define SUB_MP          ( 35 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 20 )
#define ADD_AP          ( 130 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 60 )

// 函数：获取符法效果
int get_cast_seal() { return 9102; }    // 符纸顺旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：20级\n消耗道具：符纸3张\n    金光法术，提升130点法术攻击力，同时对目标5×5范围内所有敌人造成法术伤害。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n消耗道具：符纸3张\n法力消耗：%d点\n冷却时间：%d秒\n    金光法术，提升%d点法术攻击力，同时对目标5×5范围内所有敌人造成法术伤害。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    施放时提升%d点法术攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 60 );
        return result;	        
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

        if( !objectp( item = present("符纸", me, 1, MAX_CARRY*4) ) )    // || item->get_amount() < 2
        {
                printf( ECHO "您得有符纸才能使用“" PF_NAME "”。" );    // "使用“" PF_NAME "”得准备两张符纸。"
                return 1;
        }

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                z = get_z(who);  x = get_x(who);  y = get_y(who);
        }
        else
        {
                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;

                z = get_z(me);
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
        item->add_amount(-3);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d,%d,%d,%d", level, z, x, y ) );
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
        int level, i, size, cp;        

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%d,%d,%d,%d", level, z, x, y) != 4 ) return 1;

        char = get_scene_object(z, x, y, USER_TYPE);
        send_user( char, "%c%w%w%w%c%c%w%c%c%w%c%c%c", 0x4f, x, y, 
                42421, 1, OVER_BODY, 42422, 1, OVER_BODY, 42423, 1, OVER_BODY, PF_ONCE );

//      if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功

        char = get_range_object(z, x, y, 2, CHAR_TYPE) + get_range_object(z, x, y, 2, USER_TYPE) - ({ me });
	cp = me->get_cp();
	me->set_cp(cp*10/12+ADD_AP);
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
        	if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
        	CHAR_FIGHT_D->cast_done(me, who);
	        if ( who && !who->is_die() )
	        	CHAR_FIGHT_D->set_enmity(me,who,90);
        }
	me->set_cp(cp);
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
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 5, "符纸");
}

// 函数：命令处理
int perform_action_npc( object me, object who)
{
        object *user, item;
        int x,y,z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                z = get_z(who);  x = get_x(who);  y = get_y(who);
        }
 	else
 		return 0;

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d,%d,%d,%d", level, z, x, y ) );

        return 1;
}

// 函数：法术处理
int cast_done_npc( object me )
{
        object *char, who;
        string arg;
        int z, x, y;
        int level, i, size, cp;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%d,%d,%d,%d", level, z, x, y) != 4 ) return 1;

        char = get_scene_object(z, x, y, USER_TYPE);
        send_user( char, "%c%w%w%w%c%c%w%c%c%w%c%c%c", 0x4f, x, y, 
                42421, 1, OVER_BODY, 42422, 1, OVER_BODY, 42423, 1, OVER_BODY, PF_ONCE );

        char = get_range_object(z, x, y, 2, CHAR_TYPE) + get_range_object(z, x, y, 2, USER_TYPE) - ({ me });
	cp = me->get_cp();
	me->set_cp(cp/2+ADD_AP);
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
        	if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
        	CHAR_FIGHT_D->cast_done(me, who);
	        if ( who && !who->is_die() )
	        	CHAR_FIGHT_D->set_enmity(me,who,90);
        }
	me->set_cp(cp);
        return 2;    // 执行成功
}