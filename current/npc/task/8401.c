//ʦ����������NPC
#include <ansi.h>
#include <npc.h>
#include <equip.h>
#include <action.h>

inherit SLAVE;
int iWalk;
// ��������ȡ�ٻ�������
int get_zombie_type() { return 99; }     // �ж�����
int is_master_hide_task() { return 1; }
// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }

// ���������촦��
void create()
{
        set_name( "����" );
        set_char_picid(8000);    // ������
	
        setup();

        set( "birthday", time() );
}

void win_bonus( object who ) 
{
	int exp,level1,level2;
	object owner;

	owner = get_owner();
	if ( !objectp(owner) )
		return ;

	owner->add("robber.slave",-1);

	level1 = get_level();
	level2 = who->get_level();
	exp = correct_exp_bonus(level1,level1-level2,50);
	who->add_exp(exp);
	who->add_potential(1);	
	tell_user( who, "������%s������ %+d, Ǳ�� %+d��", get_name(), exp, 1 );		
}

void heart_beat_walk()
{
	string robber;
	object *member,who,enemy,owner,me;
	
	me = this_object();
	if ( get("hide1") && !objectp(get_owner() ) )
	{
		remove_from_scene(FALL_ACT);
		destruct(this_object());
		return ;
	}
	member = get_range_object_2(me, me->get_max_seek(), CHAR_TYPE)+get_range_object_2(me, me->get_max_seek(), USER_TYPE)-({me});
	if ( sizeof(member) != 0 )
	{
		foreach(who in member)
		{
			if ( who->is_die() ) 
				continue;
			if ( me->can_fight(who) != 1 )
				continue;			
			me->set_main_enemy(who);
			::heart_beat_walk();
			return;
		}		
	}
	set_enemy(0);
}

// ���������Խ���ս��
int can_be_fighted( object who ) 
{ 
        object owner;

	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() ) return 0;
        if( who->get_enemy() == this_object() ) return 1;

        if( get("hide1") == who->get_number() || get("hide2") == who->get_number() ) return 1;


        send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),  get_name() + ":\n    �������������£�" );
        return 0;
}
int can_fight( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
        if( get("hide1") == who->get_number() || get("hide2") == who->get_number() ) return 1;
	set_enemy(0);
        return 0;
}