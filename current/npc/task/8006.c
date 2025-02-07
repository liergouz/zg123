#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit SLAVE;
// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 0101; }
// ��������ȡ�ٻ�������
int get_zombie_type() { return 99; }     // �ж�����
//int is_general_slave() { return 1; }

int is_zombie() { return 0; }  

// ���������촦��
void create()
{
        set_name("��Ȯ");
        setup();
        set_walk_speed(2);
        set_attack_speed(10);
        set_walk_step(2);        
        set_char_type(FIGHTER_TYPE);  
}

// �������ؼ���������
int perform_action( object who ) 
{
	return "skill/11/11007"->perform_action_npc(this_object(),who);
}
// �������жϿ���ս��
int can_fight( object who ) 
{
	object owner;
	if( objectp(owner=who->get_owner()) && owner->is_npc() ) return 0;
	return ::can_fight(who);	
}