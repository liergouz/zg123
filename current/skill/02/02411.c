
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0241
#define THIS_PERFORM    02411
#define PF_START       "02411"
#define PF_NAME        "蛟龙入海"

#define SKILL_LEVEL     6
#define TIME_INTERVAL   2
#define SUB_MP          0
#define SUB_YUAN        1
#define ADD_RATE        8 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*2

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取法力
int get_sub_mp( object me ) { return SUB_MP; }

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：6级\n    枪如蛟龙入海，迅捷锋锐，可提升8％的攻击命中率。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d点\n冷却时间：%d秒\n    枪如蛟龙入海，迅捷锋锐，可提升%d％的攻击命中率。\n" HIC"下一级：\n"NOR"技能需求："HIR"%d级\n" NOR "    可提升%d％的攻击命中率。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_RATE, cur_level*10+SKILL_LEVEL, ADD_RATE + 2);
        return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN);
                return 1;
        }        
        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备枪。" );
                return 1;
        }
	if( !CHAR_FIGHT_D->attack_action(me, who, 1010, 1) ) return 1;        
	me->add_yuan( -SUB_YUAN );
	set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
         me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s", who->get_char_id() ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP );

        return 1;
}

// 函数：特殊技处理(动作)
int perform_action( object me, object who )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN);
                return 1;
        }
        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备枪。" );
                return 1;
        }

        if( !CHAR_FIGHT_D->attack_action(me, who, 1010, 1) ) return 1;        

        me->add_mp( -SUB_MP );
	me->add_yuan( -SUB_YUAN );
	me->set_perform( PF_START, time() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        return 2;    // 执行成功
}

// 函数：特殊技处理
int perform_done( object me, object who )
{
        int level;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

/*      if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", SUB_MP );
                return 1;
        }       */

        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备枪。" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气

        CHAR_FIGHT_D->attack_done(me, who, HIT_SPEAR, 0, ADD_RATE);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,50);	               

        return 2;    // 执行成功
}

// 函数：特殊技处理
int cast_done( object me )
{
        int level;        
        object who;
        string arg;     

	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气

        CHAR_FIGHT_D->attack_done(me, who, HIT_SPEAR, 0, ADD_RATE);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,50);	               

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
				send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 10, 5, 0);
}
