
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 1051; }

// ���������촦��
void create()
{
        set_name("Ф��");

        set_level(40);
	set_max_hp(940);
	set_ap(320);
	set_dp(390);
	set_cp(320);
	set_pp(195);
	set_sp(135);
	set_walk_speed(3);
	set_attack_speed(13);
        set_max_seek(4);
        
        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_40, 7) && !who->get_legend(TASK_40, 8) )
        {
		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
			return ;        		
		TASK_LEGEND_D->give_item(who,"item/98/0194",1); 
		who->set_legend(TASK_40, 8);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,11,"��ʧ�����(���)" );
		send_user(who, "%c%s",'!', "Ф�� 1/1");
		USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,11);
	}
}
