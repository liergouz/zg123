
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <action.h>

#define THIS_SKILL      0424
#define THIS_PERFORM    04244
#define PF_START       "04244"
#define PF_NAME        "雷龙诀"

#define SKILL_LEVEL     44
#define TIME_INTERVAL   4
#define SUB_MP          ( 250 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 30 )
#define ADD_CP          ( 150 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 50 )


// 函数：获取符法效果
int get_cast_seal() { return 9102; }    // 符纸顺旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：44级\n消耗道具：符纸6张\n    召唤雷龙打击敌人。提升150点法术攻击力。持续6秒不断对以自己为中心9×9范围内的所有敌人造成伤害。并有30％的几率使被攻击目标陷入1秒的眩晕状态。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n消耗道具：符纸6张\n法力消耗：%d点\n冷却时间：%d秒\n    召唤雷龙打击敌人。提升%d点法术攻击力。持续6秒不断对以自己为中心9×9范围内的所有敌人造成伤害。并有30％的几率使被攻击目标陷入1秒的眩晕状态。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    施放时提升%d点法术攻击力。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_CP, cur_level*10+SKILL_LEVEL, ADD_CP + 50 );
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
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_ONCE );
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
			send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        me->add_mp(-mp);
        item->add_amount(-6);
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 2);
        me->add_2("go_count.count2",2);        
        me->set_perform( PF_START, time() );
        set_effect_2(me, EFFECT_PROGRESS, 3, 2);
        me->set_progress_file(__FILE__);
        me->set_enemy(0);
        send_user(me, "%c", 0x01);
        send_user(me, "%c%c%w%s", 0x5a, 0, 8, "雷龙诀施放中……");
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        return 2;    // 执行成功
}


void into_effect(object me, string arg)
{
        object *user, *char, who;
        int z, x, y;
        int level, mp, rate, i, size, count, ret;
	int add, cp;
	add = ADD_CP;
	cp = me->get_cp();
	me->set_cp(add+cp*10/12);
        z = get_z(me);  x = get_x(me);  y = get_y(me);
        char = get_range_object(z, x, y, 4, USER_TYPE) + get_range_object(z, x, y, 4, CHAR_TYPE) - ({ me });
        count = 0;
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
                if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
		count ++;
		if (count<=3)
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                        	42361, 2, OVER_BODY, 42362, 2, OVER_BODY, 42363, 2, OVER_BODY, PF_ONCE );
                ret = CHAR_FIGHT_D->cast_done(me, who);
	        if ( who && !who->is_die() )
	        	CHAR_FIGHT_D->set_enmity(me,who,90);
	        if (ret>0 && who && random100()<30)
	        {	        	
		        if (who->is_anti_effect())continue;
        		if (who->get("anti_faint")) continue;
			if(     get_effect(who, EFFECT_CHAR_FAINT)
			||      get_effect(who, EFFECT_CHAR_FAINT_0) ) continue;    // 执行成功
			if (who->get_perform("02222#")) continue;
		        user = get_scene_object_2(who, USER_TYPE);
		        set_effect(who, EFFECT_CHAR_FAINT, 1);    // 小心准备 me
		        CHAR_CHAR_D->init_loop_perform(who);
		        if( get_heart_state(who) == MAGIC_STAT ) send_user( user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
		        send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD );
		        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
		        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP );	        
	        	
	        }
        }	
	me->set_cp(cp);
	if( !get_effect_3(me, EFFECT_PROGRESS) ) 
	{
		send_user(me, "%c%c%c", 0x5a, 1, 1);
	}
}

void effect_break(object me, string arg)
{
	object who, owner;
	int add, time;
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect_2(me, EFFECT_PROGRESS, 0, 0);	
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
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 2, "符纸");
}


int perform_action_npc( object me, object who )
{
        object *user, item;
        int x,y,z;
        int level, mp;


        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_ONCE );
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
			send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 2);        
        me->set_perform( PF_START, time() );
        set_effect_2(me, EFFECT_PROGRESS, 3, 2);
        me->set_progress_file(__FILE__);        
        me->set_enemy(0);
        send_user(me, "%c%c%w%s", 0x5a, 0, 8, "雷龙诀施放中……");
        return 1;
}