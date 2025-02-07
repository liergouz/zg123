
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0271
#define THIS_PERFORM    02711
#define PF_START       "02711"
#define PF_NAME        "伏魔诀"

#define SKILL_LEVEL     3
#define TIME_INTERVAL   1
#define SUB_MP          ( 10 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 4 )
#define ADD_AP		( 35 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 15 )


// 函数：获取法力
int get_sub_mp( object me ) 
{ 
        int level = me->get_skill(THIS_SKILL);
        return SUB_MP;    // 小心准备 level
}

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：3级\n    伏魔之术，提升35点法术攻击力，对一个视线范围内一个目标造成伤害。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    伏魔之术，提升%d点法术攻击力，对一个视线范围内一个目标造成伤害。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    施放时提升%d点法术攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 15 );
	return result;   
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;
        object * user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 level

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }
        if (!who) return 1;
        me->to_front_xy(get_x(who), get_y(who)); //设置me的面向坐标.
        user = get_scene_object_2(me, USER_TYPE);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        me->add_mp(-mp);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
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
        int level;        
        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                return 1;    // 打到空地
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 27112, 1, OVER_BODY, PF_ONCE );
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功
        CHAR_FIGHT_D->cast_done(me, who, ADD_AP);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,40);	

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
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 5, 0);

}

int perform_action_npc(object me, object who)
{
	int level;
	object *user;
	
        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if (!who) return 1;
        me->to_front_xy(get_x(who), get_y(who));
        user = get_scene_object_2(me, USER_TYPE);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
        return 1;
}

// 函数：法术处理
int cast_done_npc( object me )
{
        object who;
        string arg;
        int z, x, y;
        int level;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 27112, 1, OVER_BODY, PF_ONCE );
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功
        CHAR_FIGHT_D->cast_done(me, who, ADD_AP);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,40);	

        return 2;    // 执行成功
}