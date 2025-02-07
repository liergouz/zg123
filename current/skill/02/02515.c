
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0251
#define THIS_PERFORM    02515
#define PF_START       "02515"
#define PF_NAME        "狂涛怒浪"

#define SKILL_LEVEL     33
#define TIME_INTERVAL   20 - (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/8
#define SUB_MP          0
#define SUB_YUAN        4
#define ADD_DAMAGE      25 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/8*5

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
        	return HIR + PF_NAME +"\n技能需求：33级\n    棍法终结技，攻击时追加25点伤害，并造成100％几率的爆击效果。";
        cur_level = (level - SKILL_LEVEL)/8 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d\n冷却时间：%d秒\n    棍法终结技，攻击时追加%d点伤害，并造成100％几率的爆击效果。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    攻击时追加%d点伤害，技能的使用冷却时间减少至%d秒。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_DAMAGE, cur_level*8+SKILL_LEVEL, ADD_DAMAGE + 5, TIME_INTERVAL - 1 );
        return result;	
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp, rate;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备棍。" );
                return 1;
        }
	if( !CHAR_FIGHT_D->attack_action(me, who, 2050, 1) ) return 1;    
        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
        
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        
        rate = me->get_double_rate();
        me->set_double_rate(10000);    
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2515, 1, OVER_BODY, PF_ONCE );
        me->set("add_damage", ADD_DAMAGE);
        CHAR_FIGHT_D->attack_done(me, who);
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,120);	

        me->set("add_damage", 0);
        me->set_double_rate(rate);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);  
         me->add_2("go_count_count2",9);      
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );                      
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
				send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 2, 50, 9, 0);
}
