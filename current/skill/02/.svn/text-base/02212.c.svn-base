
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0221
#define THIS_PERFORM    02212
#define PF_START       "02212"
#define PF_NAME        "破空一击"

#define SKILL_LEVEL     9
#define TIME_INTERVAL   2
#define SUB_MP          10 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*5
#define ADD_AP          5 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*2
#define ADD_AP2         (15 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*10)

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

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
        	return HIR + PF_NAME +"\n    凝气一击，斩天破空，追加15点物理攻击力，造成伤害的同时使对手负伤。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    凝气一击，斩天破空，追加%d点物理攻击力，造成伤害的同时使对手负伤%d秒。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    追加%d点物理攻击力，负伤的持续时间延长至%d秒。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP2, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP2+10, ADD_AP + 2 );
        return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, mp, ret;
        object * user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( me->get_weapon_code() != BLADE ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备刀。" );
                return 1;
        }
   	if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 1;
   	me->add_mp(-mp);
        if( me->get_gender()!=1 && !CHAR_FIGHT_D->attack_action(me, who, 2030) ) return 1;
        else
        if( me->get_gender()==1 && !CHAR_FIGHT_D->attack_action(me, who, 1030) ) return 1;
        

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );      
        me->set_perform( PF_START, time() );
        

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2212, 1, OVER_BODY, PF_ONCE );

        ret = CHAR_FIGHT_D->attack_done(me, who,  HIT_BLADE, ADD_AP2);    // 小心准备 me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,80);
        if (!who) return 1;
	if (who->is_anti_effect()) return 2;
        if (who->get("anti_wound")) return 2;
        me->set_enemy_3(who);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 7);
          me->add_2("go_count.count2",7);        
	if (ret>0)
	{
	        if(    !get_effect(who, EFFECT_CHAR_WOUND)
	        &&     !get_effect(who, EFFECT_CHAR_WOUND_0) )
	        {
                        user = get_scene_object_2(who, USER_TYPE);
                        set_effect(who, EFFECT_CHAR_WOUND, ADD_AP);
                        set_effect(who, EFFECT_CHAR_WOUND_0, ADD_AP+2);
                        CHAR_CHAR_D->init_loop_perform(who);
                        send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9020, 1, EFFECT_BAD );
                        CHAR_CHAR_D->init_loop_perform(who);
                        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9020, 1, OVER_BODY, PF_LOOP );
			if (who->is_user())
			{
	                        USER_ENERGY_D->count_ap(who);
        	                USER_ENERGY_D->count_dp(who);
			}        	                	        		
	        }	
	}

        return 1;
}

// 函数：特殊技处理
int cast_done( object me )
{
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
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 1, 30, 7, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 2, 30, 7, 0);
}

