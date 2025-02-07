
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <action.h>

inherit SLAVE;

int get_max_level0() { return 3;}

// ��������ȡ�ٻ�������
int get_zombie_type() { return SOLDIER_TYPE_2; }     // �ж�����

// ���������촦��
void create()
{
        set_name("���");
        set_char_picid(4132);

        setup();
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// --------------------------------------------------------------- Զ�̵��� ----

// ��������������
void upgrade_level( int level ) { __FILE__ ->upgrade_level_callout( this_object(), level ); }

// ��������������(���߸���)
void upgrade_level_callout( object me, int level )
{
        switch( level )
        {
      default : me->set_char_type(SLAVE_TYPE_1);
                break;
       case 2 : me->set_char_type(SLAVE_TYPE_2);
                break;
       case 3 : me->set_char_type(SLAVE_TYPE_3);
                break;
       case 4 : me->set_char_type(SLAVE_TYPE_4);
                break;
       case 5 : me->set_char_type(SLAVE_TYPE_5);
                break;
        }
        me->set_attack_speed(20);
        me->set_walk_step(2);
        me->set_walk_speed(3);
}

// ��������������
void upgrade_level_2( int level ) { __FILE__ ->upgrade_level_2_callout( this_object(), level ); }

// ��������������(���߸���)
void upgrade_level_2_callout( object me, int level )
{
        object owner;
        int hp, cp, pp, level0;

        if( level > 1 ) if( objectp( owner = me->get_owner() ) && owner->is_user() )
        {
        	level0 = me->get_level_0();
                cp = owner->get_cp();
                pp = owner->get_pp();
                me->add_max_hp( 60 );  
                me->set_hp(me->get_max_hp());
                me->set_mp(me->get_max_mp());
                me->add_ap( 10 );
                me->add_dp( 60 );
                me->add_pp( 10 );
        }
}

void do_after_attack(object who)
{
	object me = this_object();
	object * user;
	int level, level0, rate;
	level = me->get_level_2();
	level0 = me->get_level_0();
	rate = level0/20+5*level;
	if (random(100)<rate && !get_effect(who, EFFECT_CHAR_WOUND_0) )
	{
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_WOUND, 10);
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
	if (time() -me->get("pf")>15)
	{
		me->set("pf", time());
		who->set_enemy(me);
		who->set("2122", time());
		who->init_enemy_damage(me, 1); 	
	}
}