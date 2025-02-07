
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
int get_char_picid() { return 1001; }

// ���������촦��
void create()
{
        set_name("�ɵ�������");

        set_level(20);
	set_max_hp(300);
	set_ap(150);
	set_dp(145);
	set_cp(140);
	set_pp(130);
	set_sp(90);
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
        if ( objectp(who) && who->get_legend(TASK_04, 1)&&!who->get_legend(TASK_04, 2) )
        {
		item = new("item/98/0009");
        	if ( !item )
        		return ;
        	p = item->move(who,-1);
        	if ( !p )
        		return;
        	item->add_to_user(p);
		who->set_legend(TASK_04, 2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,1,"ʧ�ԵĿ���(���)" );
		send_user(who, "%c%s",'!', "һ��ƽ� 1/1");
	}	
}