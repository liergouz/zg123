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

	owner = get_owner();
	if ( !objectp(owner) )
		return ;

	owner->add("chain.slave",-1);

}

void heart_beat_walk()
{
	string robber;
	object *member,who,enemy,me=this_object();

	if ( !objectp(get_owner() ) )
	{
		remove_from_scene(FALL_ACT);
		destruct(me);
		return ;
	}
	enemy = get_enemy();
	if ( !enemy || distance_between(me, enemy) > get_max_seek() )
	{
		member = get_range_object_2(this_object(),get_max_seek(), USER_TYPE);
		if ( sizeof(member) != 0 )
		{
			foreach(who in member)
			{
				if ( who->is_die() ) 
					continue;
				if ( can_fight(who) != 1 )
					continue;
				set_main_enemy(who);
			}		
		}
	}
	::heart_beat_walk();
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

//�����������
int get_enemy_die_process() { return 1; }

void on_enemy_die(object who)
{
	object owner;
	
	owner = get_owner();
	if ( owner )
		owner->on_enemy_die(who);
}