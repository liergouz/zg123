
// 自用技能  TIPS:[PF_SELF]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0511
#define THIS_PERFORM    05111
#define PF_START       "05111"
#define PF_NAME        "自疗"

#define SKILL_LEVEL     1
#define TIME_INTERVAL   2
#define SUB_MP        ( 10 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 7 * 6 )
#define ADD_EFFECT    ( 45 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 7 * 50 )

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：1级\n    医疗系的法术，直接恢复自身45点气血。";
        cur_level = (level - SKILL_LEVEL)/7 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    医疗系的法术，直接恢复自身%d点气血。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    直接恢复自身%d点气血。",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*7+SKILL_LEVEL, ADD_EFFECT+50 );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;
        if ( me->get_perform("05016#"))
	{
                printf( ECHO "使用“斗移星移”后不能使用“"PF_NAME"”。" );
                return 1;		
	}
        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        string arg;
        int level, hp;
        object item;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        level = to_int(arg);

        hp = ADD_EFFECT;    // 小心准备 me, cp
        hp += me->get("add_magic_heal");
	if( objectp(item=me->get_equip(WEAPON_TYPE)) && item->get_name()=="玉晨宝剑" )
		hp += random(51);
        if (random100()<me->get_double_rate_2()/100) 
        {
        	hp *= 2;
        	send_user( me, "%c%d%w%c%d%w%c", 0x4a, getoid(me), -hp, get_d(me), getoid(me), 1 );
        }
        else
        	send_user( me, "%c%d%w", 0x68, getoid(me), -hp );

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 51111, 1, OVER_BODY, PF_ONCE );        

        if (!me->no_recover() && !get_effect_3(me, EFFECT_USER_BURN)) me->add_hp(hp);  
       	CHAR_FIGHT_D->set_enmity1(me,60+hp);
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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/7+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0,1, MAGIC_ACT_BEGIN, 0, 5, 0);
}
