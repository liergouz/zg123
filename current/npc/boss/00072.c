#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <action.h>

inherit SLAVE;
int cannot_enter_city() { return 1; }

// ��������ȡ�ٻ�������
int get_zombie_type() { return ZOMBIE_TYPE_1; }     // �ж�����

// ���������촦��
void create()
{
        set_name( "��ʬ" );
        set_char_picid(4134);
	set_attack_speed(10);
        set_walk_speed(2);
        set_walk_step(2);
        set_head_color(0x2);
        setup();
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// --------------------------------------------------------------- Զ�̵��� ----


void do_after_attack(object who)
{
	object me = this_object();
	object * user;
	int level, level0, rate;

	if (random(100)<5)
       	{
                who->set_poison(30);
                set_effect_2(who, EFFECT_CHAR_POISON, 10, 2);
                send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
        }
}

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )
{
	int level,level2,exp=100;
	object owner;
	
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return ;

	level = me->get_level();
	level2 = level - who->get_level();
	exp = me->correct_exp_bonus(level, level2, exp) * who->get_online_rate() / 100;
	who->add_exp(exp);
}
