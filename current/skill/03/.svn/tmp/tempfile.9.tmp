
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0325
#define THIS_PERFORM    03254
#define PF_START       "03254"
#define PF_TIME        "03254#"
#define PF_NAME        "不死之身"

#define SKILL_LEVEL     30
#define TIME_INTERVAL   60 - ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 3
#define SUB_MP          100 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 20
#define ADD_INTERVAL    12 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 3


// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：30级\n    天神护身，持续一段时间内，所有会使你的气血值降至1以下的伤害，均改为将你的气血值下降为1。";
        cur_level = (level - SKILL_LEVEL)/15 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    天神护身，持续%d秒内，所有会使你的气血值降至1以下的伤害，均改为将你的气血值下降为1。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    不死之身的持续效果延长至%d秒，使用冷却时间减少至%d秒。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_INTERVAL, cur_level*15+SKILL_LEVEL, ADD_INTERVAL + 3, TIME_INTERVAL - 3 );
        return result;    
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "：\n　　受到的所有伤害均不会使气血低于1。\n" );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) 
        {
        	notify( "你处于封印状态中。" );
        	return 1;
        }
        me->add_mp(-mp);
        CHAR_FIGHT_D->set_enmity1(me,20);
        
        interval = ADD_INTERVAL;    // 小心准备 me

        me->set_perform( PF_START, time() );
        me->set_perform( "03254#",interval);
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2(me, EFFECT_CHAR_IMMORTAL, 1, interval);
        send_user( me, "%c%w%w%c", 0x81, 3254, get_effect_3(me, EFFECT_CHAR_IMMORTAL), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3254, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32549, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32540, 1, OVER_BODY, PF_LOOP );

        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object *user;
        int level, interval;
/*
        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // 小心准备 me

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect(me, EFFECT_CHAR_IMMORTAL, interval);
        send_user( me, "%c%w%w%c", 0x81, 3254, get_effect_3(me, EFFECT_CHAR_IMMORTAL), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3254, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32549, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32540, 1, OVER_BODY, PF_LOOP );

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
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/15+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}
