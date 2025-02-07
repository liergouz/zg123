
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0363
#define THIS_PERFORM    03632
#define PF_START       "03632"
#define PF_TIME        "03632#"
#define PF_NAME        "护身毒环"

#define SKILL_LEVEL     32
#define TIME_INTERVAL   5
#define SUB_MP          3
#define SUB_MP_2        3
#define ADD_INTERVAL    me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 30, 200)    // 警告：me 得准备好
#define ADD_DAMAGE      me->get_pf_value_2(THIS_SKILL, SKILL_LEVEL_SQUARE, 10, 560)    // 警告：me 得准备好
#define ADD_RATE        me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 5, 500)    // 警告：me 得准备好

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］在持续时间内，对接近的目标造成伤害，有可能使对方中毒。消耗法力：%d，再次使用需间隔 %d 秒，%s%d 级可用\n",
                SUB_MP, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "：\n　　每秒对接近的目标造成 %d 点伤害，有 %d％ 的几率使其中毒。\n", 
                        me->get_save("pf.hurt"), me->get_save("pf.hurt_rate") );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：获取描述(持续)
string get_loop_desc2( object me )
{
        return sprintf( "中毒\n定时减少气血。" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = me->get_perform(PF_TIME) + TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }

//        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
//      me->set_cast_arg( sprintf( "%d", level ) );

        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object *user;
        int level, interval;

        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // 小心准备 me

        me->set_save("pf.hurt", ADD_DAMAGE);    // 小心准备 me
        me->set_save("pf.hurt_rate", ADD_RATE);    // 小心准备 me

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2(me, EFFECT_USER_HURT, interval, 1);
        send_user( me, "%c%w%w%c", 0x81, 3632, get_effect_3(me, EFFECT_USER_HURT), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3632, 1, EFFECT_GOOD );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 36321, 3, UNDER_FOOT, PF_LOOP );

        return 2;    // 执行成功
}

int cast_done_npc( object me )
{
        object *user;
        int level, interval;

        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // 小心准备 me

        me->set_save("pf.hurt", ADD_DAMAGE);    // 小心准备 me
        me->set_save("pf.hurt_rate", ADD_RATE);    // 小心准备 me

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2(me, EFFECT_USER_HURT, interval, 1);
        send_user( me, "%c%w%w%c", 0x81, 3632, get_effect_3(me, EFFECT_USER_HURT), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3632, 1, EFFECT_GOOD );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 36321, 3, UNDER_FOOT, PF_LOOP );

        return 2;    // 执行成功
}

// 函数：法术处理
void effect_hurt_done( object me )
{
        object *user, *char, who, owner;
        int z, x, y;
        int level, mp, ap, damage, damage2, rate, i, size, p;

        if( !get_effect(me, EFFECT_USER_HURT) )    // 循环征状 set_effect_2
        {
                user = get_scene_object_2(me, USER_TYPE);
                send_user( me, "%c%w%w%c", 0x81, 3632, 0, EFFECT_GOOD );
                send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3632, 0, EFFECT_GOOD );
                CHAR_CHAR_D->init_loop_perform(me);
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 36321, 3, UNDER_FOOT, PF_STOP );
        }

        level = me->get_skill(THIS_SKILL);

        mp = SUB_MP_2;

        if( me->get_mp() < mp ) return;

        me->add_mp(-mp);

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        char = get_range_object(z, x, y, 1, USER_TYPE) + get_range_object(z, x, y, 1, CHAR_TYPE) - ({ me });

        ap = me->get_ap();  damage = me->get_save("pf.hurt");
        rate = me->get_save("pf.hurt_rate");

        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
                if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
                if ( random(100) < who->get_anti_poison() ) continue;
//              send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 36321, 3, UNDER_FOOT, PF_ONCE );

		if (p = me->get_skill(0430)) damage = damage * (100+p*2)/100+7*p;		// 帮派的伤害强化
                damage2 = CHAR_FIGHT_D->correct_damage(me, who, damage, ap);
		if (p = who->get_skill(0431)) damage2 = damage2 * (100 - p*2)/100 - 7*p;		// 帮派的抵抗强化
                if (damage2<1) damage2 = 1;
		if (who->is_nianshou())
		{
	                send_user( me, "%c%s", '!', "你的伎俩对年兽是不起作用的。");
			damage2 =0;
		}
                if( who->is_npc() )    // 抄自 /sys/user/fight
                {
                        if( who->get_enemy_4() == me ) 
                                who->set_attack_time( time() );    // 同一个人：更新持续时间
                        else if( gone_time( who->get_attack_time() ) > 5 )
                        {
                                who->set_enemy_4(me);
                                who->set_attack_time( time() );    // 不同的人：更新持续敌手
                        }
//                      if( !who->get_max_damage() ) who->init_enemy_damage(me, 0);    // 记录最强伤害(NPC)
                        if( damage >= who->get_max_damage() ) who->init_enemy_damage(me, damage);    // 记录最强伤害(NPC)
                        owner = who->get_owner();
                }
                else
                	owner = who;

                if (owner) send_user( owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage2, get_d(who), 0, 0, 0 );
                send_user( me, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage2, get_d(who), 0, 0, 0 );
                CHAR_DIE_D->is_enemy_die(me, who, damage2);
                if( !who ) continue;    // 执行成功

                if( get_effect(who, EFFECT_CHAR_POISON_2) ) continue;    // 执行成功    // 牵机毒
                if( get_effect(who, EFFECT_CHAR_9140) ) continue;    // 执行成功    // 辟毒散

                if( random(100) < rate ) 
                {
                        who->set_poison_2( (level + 10) / 3 );
                        set_effect_2(who, EFFECT_CHAR_POISON_2, 3, 2);
                        send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON_2), EFFECT_BAD );
                        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
                }
        }
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
