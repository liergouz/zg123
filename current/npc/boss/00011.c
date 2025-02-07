
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit SLAVE;
// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 0502; }
// ��������ȡ�ٻ�������
int get_zombie_type() { return 99; }     // �ж�����
int is_tigerking_slave() { return 1; }

int is_zombie() { return 0; }  

// ���������촦��
void create()
{
        set_name("��������");

        set_level(90);
	set_max_hp(38000);
	set_ap(1050);
	set_dp(760);
	set_cp(100);
	set_pp(700);
	set_sp(600);
	set_walk_speed(3);
	set_attack_speed(15);
        set_max_seek(8);
        set_head_color(0x20ad);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )
{
	int p,size,i;
	object owner,*team;
	
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return ;

	who->add_exp(5000);

        if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else    size = 1;
        	
        if ( size == 1 )
     		who->add_potential(50);
	else
	{
		for( i = 0; i < size; i ++ ) if( team[i] )
                	team[i]->add_potential(50);	
		
	}
        	
}
