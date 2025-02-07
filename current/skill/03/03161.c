
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0316
#define THIS_PERFORM    03161
#define PF_START       "03161"
#define PF_TIME        "03161#"
#define PF_NAME        "金钟罩"

#define SKILL_LEVEL     5
#define TIME_INTERVAL   2
#define SUB_MP          0
#define SUB_YUAN        1
#define ADD_AP		10 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/11*2

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level, interval;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：5级\n    持续一段时间内，可提升自身的物理防御力。";
        cur_level = (level - SKILL_LEVEL)/11 + 1;
        interval = 30 + (level-SKILL_LEVEL)/11*3;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n元气消耗：%d点\n冷却时间：%d秒\n    持续%d秒内，可提升自身%d％的物理防御力。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    可提升自身%d％的物理防御力，且持续时间延长至%d秒。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, interval, ADD_AP, cur_level*11+SKILL_LEVEL, ADD_AP+2, interval+3 );
	return result;   
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "：\n　　增加自身 %d％ 的物理防御力。\n", ADD_AP );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval =TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // 小心准备 level

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN );
                return 1;
        }
	if (me->get_fam_name()=="桃花源" && me->get_perform("03191"))
	{
		notify( "狂暴状态下不能使用“" PF_NAME "”。" );
		return 1;
	} 
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
          me->add_2("go_count.count2",9);
        interval = 30 + (level-SKILL_LEVEL)/11*3;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect(me, EFFECT_CHAR_ADD_DP, interval);
        send_user( me, "%c%w%w%c", 0x81, 3161, get_effect_3(me, EFFECT_CHAR_ADD_DP), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3161, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 3251, 1, OVER_BODY, PF_ONCE );

        USER_ENERGY_D->count_dp(me);
	
	CHAR_FIGHT_D->set_enmity1(me,240 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*50 );
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object *user;
        int level, interval;
/*
        level = me->get_skill(THIS_SKILL);
        interval = 10 + level;

        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );
        me->set_perform( PF_START, time() );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect(me, EFFECT_CHAR_ADD_DP, interval);
        send_user( me, "%c%w%w%c", 0x81, 3251, get_effect_3(me, EFFECT_CHAR_ADD_DP), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3251, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32511, 1, OVER_BODY, PF_ONCE );

//      USER_ENERGY_D->count_pp(me);    // cp/pp 影响 ap/dp, 所以放前
        USER_ENERGY_D->count_dp(me);

        // 效果见 energy_d.c
*/
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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/11+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
        send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, MAGIC_ACT_BEGIN, 0, 9, 0);
}