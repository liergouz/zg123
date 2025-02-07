
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ������Զ�̹����Ĺ�
int is_caster() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 0052; }

// ���������촦��
void create()
{
        set_name("�Ŷ�");

        set_level(116);
	set_max_hp(4954);
	set_ap(700);
	set_dp(633);
	set_cp(843);
	set_pp(368);
	set_sp(270);
	set_walk_speed(4);
	set_attack_speed(15);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

// ��������ȡװ������
int get_weapon_code() { return THROWING; }

// �������ؼ���������
int perform_action( object who ) { return PF_FILE_01611->perform_action_npc( this_object(), who ); }

void check_legend_task( object who )
{
	int p;
	object item;
        if ( objectp(who) && who->get_legend(TASK_44, 7)&&!who->get_legend(TASK_44, 8) )
        {
		item = new("item/98/0218");
        	if ( !item )
        		return ;
        	p = item->move(who,-1);
        	if ( !p )
        		return;
        	item->add_to_user(p);
		who->set_legend(TASK_44, 8);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,63,"Ư���Ĵ���2��(���)" );
		USER_TASK_D->send_task_intro(who,2,TID_WEIGUO,63);
		send_user(who, "%c%s",'!', "�Ŷ� 1/1");
	}	
}