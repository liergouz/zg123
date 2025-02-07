#include <ansi.h>
#include <npc.h>
#include <equip.h>
#include <action.h>

inherit SLAVE;
int iWalk;
// ��������ȡ�ٻ�������
int get_zombie_type() { return 99; }     // �ж�����
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

	if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
        	
	owner = get_owner();
	if ( !objectp(owner) )
		return ;

	owner->add("dodolook.slave",-1);

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
	object *member,who,enemy;

	if ( (iWalk++)%3 )
	{
		::heart_beat_walk();
		return;
	}
	if ( iWalk>2&&!objectp(get_owner() ) )
	{
		remove_from_scene(FALL_ACT);
		destruct(this_object());
		return ;
	}
	member = get_range_object_2(this_object(),get_max_seek(), USER_TYPE);
	member -= ({ 0 });
	if ( sizeof(member) != 0 )
	{
		foreach(who in member)
		{
			if ( can_fight(who) != 1 )
				continue;
			set_main_enemy(who);
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

	owner = get_owner();
	if ( !owner )
		return 0;
	return owner->can_be_fighted(who);
}

int can_fight( object who ) 
{ 
        object owner;

	owner = get_owner();
	if ( !owner )
		return 0;
	return owner->can_fight(who);
}