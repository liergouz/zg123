
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0325
#define THIS_PERFORM    03251
#define PF_START       "03251"
#define PF_TIME        "03251#"
#define PF_NAME        "金钟罩"

#define SKILL_LEVEL     25
#define TIME_INTERVAL   2
#define SUB_MP          25
#define SUB_YUAN        2

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］在持续时间内，使自身增加 20％ 物理防御力。消耗法力：%d，消耗元气：%d，再次使用需间隔 %d 秒，%s%d 级可用\n",
                SUB_MP, SUB_YUAN, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "：\n　　增加自身 20％ 的物理防御力。\n" );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = me->get_perform(PF_TIME) + TIME_INTERVAL;

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

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = me->get_perform(PF_TIME) - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
}
