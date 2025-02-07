
// 暗器技能  TIPS:[PF_THROWING]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0222
#define THIS_PERFORM    02222
#define PF_START       "02222"
#define PF_NAME        "清醒术"

#define SKILL_LEVEL     15
#define TIME_INTERVAL   10
#define SUB_MP          80

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：15级\n    蜀山特有的免疫法术，可保护自己不会陷入眩晕状态，在此效果下无法更换武器。\n    再次使用清醒术可解除该效果。\n";
        result = sprintf(HIC"%s\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    蜀山特有的免疫法术，可保护自己不会陷入眩晕状态，在此效果下无法更换武器。\n    再次使用清醒术可解除该效果。\n", 
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL);
        return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me
	
	if ( me->get_perform("02222#"))
	{		
		me->set_perform(PF_START, time() );
		send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
		me->set_perform("02222#", 0);
        	send_user( me, "%c%w%w%c", 0x81, 2222, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2222, 0, EFFECT_GOOD );				
		printf( ECHO "您取消了“" PF_NAME "”。" );
		return 1;		
	}
        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }


//        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->add_mp(-mp);
        set_effect(me, EFFECT_PROGRESS2, 4);
        me->set_progress_file(__FILE__);
        me->set_enemy(0);
        send_user(me, "%c", 0x01);
	send_user(me, "%c%c%w%s", 0x5a, 0, 3, "清醒术施放中……");
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数：法术处理
int into_effect( object me , string arg)
{
        int z, x, y, pf, act;
        int level, rate;
        int interval, sub_effect;
	//取消稳定心神
        if ( me->get_perform("02221#"))
	{
		me->set_perform("02221#", 0);
        	send_user( me, "%c%w%w%c", 0x81, 2221, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2221, 0, EFFECT_GOOD );
	}
	send_user(me, "%c%c%c", 0x5a, 1, 1);        
	me->set_perform("02222#", time() );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me),
                3292, 1, OVER_BODY, PF_ONCE );        
        send_user( me, "%c%w%w%c", 0x81, 2222, 30000, EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2222, 1, EFFECT_GOOD);	
        return 2;    // 执行成功
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        return PF_NAME "：\n　　保护自己不会陷入眩晕状态。\n";
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
	name = PF_NAME;
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}

void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}
