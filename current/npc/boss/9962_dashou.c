/*----------------------------------------------------------------------*\	
	��cjxx ����
	��NPC 98%���� npc/task/8211.c ��д
\*----------------------------------------------------------------------*/
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
void create() {
        set_name( "����" );
        set_char_picid(8000);    // ������	
        setup();
        set( "birthday", time() );
}

void win_bonus( object who ) {
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
	who->add_log("&robber", exp);
	who->add_log("*robber",1);
	tell_user( who, "������%s������ %+d, Ǳ�� %+d��", get_name(), exp, 1 );		
}

void heart_beat_walk() {
	string robber;
	object *member,who,enemy;

	if ( (iWalk++)%3 ) {
		::heart_beat_walk();
		return;
	}
	if ( iWalk>2&&!objectp(get_owner() ) ) {
		remove_from_scene(FALL_ACT);
		destruct(this_object());
		return ;
	}
}

// ���������Խ���ս��
int can_be_fighted( object who ) { 
        object owner;
        string leader, id;

        if( who->get_enemy() == this_object() ) {
        	return 1;
        }
        if( owner = who->get_owner() ) {
        	who = owner;
        }
        if( who->is_npc() ) {
        	return 0;
        }
        return 1;
}

int can_fight( object who ) { 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) {
		who = owner;
	}
	if( who->is_npc() ) {
		set_enemy(0);
		return 0;
	}
        if( who->get_enemy() == this_object() ) {
        	return 1;
        }
	return 1;
}