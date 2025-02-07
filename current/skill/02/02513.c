
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0251
#define THIS_PERFORM    02513
#define PF_START       "02513"
#define PF_NAME        "千钧一击"

#define SKILL_LEVEL     12
#define TIME_INTERVAL   40 - (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 
#define SUB_MP          0
#define SUB_YUAN        4
#define SUB_EFFECT	(30 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*20)

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
        	return HIR + PF_NAME +"\n技能需求：12级\n    如同千钧之重的猛力一击，命中的同时震落对手武器，使其8秒内武器无效。对怪物使用能减弱其30点物理攻击力。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d\n冷却时间：%d秒\n    如同千钧之重的猛力一击，命中的同时震落对手武器，使其8秒内武器无效。对怪物使用能减弱其%d点物理攻击力。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    技能的使用冷却时间减少至%d秒。对怪物使用能减弱其%d点物理攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, SUB_EFFECT, cur_level*10+SKILL_LEVEL, TIME_INTERVAL - 1, SUB_EFFECT + 20 );
        return result;		
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

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
	if( !CHAR_FIGHT_D->attack_action(me, who, 1030) ) return 1;
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
        int level, mp;

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

        if( !CHAR_FIGHT_D->attack_action(me, who, 1030) ) return 1;

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 2;    // 执行成功
}

// 函数：特殊技处理
int perform_done( object me, object who )
{
        object item;
        int level, mp, ret, time;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

/*      if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }       */

/*      if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN );
                return 1;
        }       */

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备棍。" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 35139, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 25131, 1, OVER_BODY, 25132, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_STICK );    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,100);	
        
        if( !who ) return 2;    // 执行成功
	if (who->is_anti_effect()) return 2;              
        if( get_effect(who, EFFECT_NO_WEAPON_0) ) return 2;                   
        if ( who->get_2("suit_effect.no_drop") ) return 2;  //套装           

        if( ret > 0 )    // rate - who->get_immunity()
        {                
                send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                time = 8;
                set_effect(who, EFFECT_NO_WEAPON, time);  
                set_effect(who, EFFECT_NO_WEAPON_0, time+2);  
                send_user( who, "%c%w%w%c", 0x81, 2114, time, EFFECT_BAD );
                if (who->is_user())
                {
                	USER_ENERGY_D->count_all_prop(who);
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
                }
                else
                {
                	who->set("02114", SUB_EFFECT);
                	who->add_ap(-SUB_EFFECT);
                }
	}
        return 2;    // 执行成功
}

// 函数：特殊技处理
int cast_done( object me )
{
        object item;
        int level, mp, ret, time;        
        string arg;     
        object who;

	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // 删除聚气
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 35139, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 25131, 1, OVER_BODY, 25132, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_STICK );    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,100);	
        
        if( !who ) return 2;    // 执行成功
	if (who->is_anti_effect()) return 2;              
        if( get_effect(who, EFFECT_NO_WEAPON_0) ) return 2;                   
        if ( who->get_2("suit_effect.no_drop") ) return 2;  //套装           

        if( ret > 0 )    // rate - who->get_immunity()
        {                
                send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                time = 8;
                set_effect(who, EFFECT_NO_WEAPON, time);  
                set_effect(who, EFFECT_NO_WEAPON_0, time+2);  
                send_user( who, "%c%w%w%c", 0x81, 2114, time, EFFECT_BAD );
                if (who->is_user())
                {
                	USER_ENERGY_D->count_all_prop(who);
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
                }
                else
                {
                	who->set("02114", SUB_EFFECT);
                	who->add_ap(-SUB_EFFECT);
                }
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
				send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 30, 5, 0);
}
