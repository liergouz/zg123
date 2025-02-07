
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0329
#define THIS_PERFORM    03293
#define PF_START       "03293"
#define PF_TIME        "03293#"
#define PF_NAME        "归元术"

#define SKILL_LEVEL     26
#define TIME_INTERVAL   (3600 - (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/9*180)


int if_can_perform(object me)
{
	int level = me->get_skill(THIS_SKILL);
	int interval = TIME_INTERVAL;
	if( gone_time( me->get_perform(PF_START) ) >= interval ) return 1; 
	return 0;
}

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：26级\n物品消耗：回天心法\n    周天法咒，死亡后可得到一次复活机会。";
        cur_level = (level - SKILL_LEVEL)/9 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n冷却时间：%d分钟\n物品消耗：回天心法\n    周天法咒，死亡后可得到一次复活机会。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    复活的使用冷却时间减少至%d分钟。", 
        	PF_NAME, cur_level, SKILL_LEVEL, TIME_INTERVAL/60, cur_level*9+SKILL_LEVEL, TIME_INTERVAL/60-3 );
	return result;  
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp, z, add, level2;
        object *user, item;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // 小心准备 level      
        if (me->is_die()==0) return 1;
        if( !objectp( item = present("回天心法", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有回天心法才能使用“" PF_NAME "”。" );
                return 1;
        }       
        item->add_amount(-1); 
        me->set_die(0);
        set_effect(me, EFFECT_USER_DIE, 0);
        set_effect(me, EFFECT_USER_DIE_5, 0);
        set_effect(me, EFFECT_USER_DIE_9, 0);
        me->set_hp(me->get_max_hp()*3/10);
        me->set_mp(me->get_max_mp()*3/10);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 32930, 1, OVER_BODY, PF_ONCE );
        me->set_perform(PF_START, time());
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );;
	return 1;
}      

// 函数：法术处理
int cast_done( object me )
{  
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME_7; }

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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/9+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}
