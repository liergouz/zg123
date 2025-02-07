
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;


// ��������ȡ��������
int get_char_picid() { return 0252; }

// ���������촦��
void create()
{
        set_name("Ǯ����");

        set_level(27);
	set_max_hp(600);
	set_ap(200);
	set_dp(145);
	set_cp(140);
	set_pp(130);
	set_sp(100);
	set_walk_speed(3);
	set_attack_speed(15);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_06, 1)&&!who->get_legend(TASK_06, 2) )
        {
		who->set_legend(TASK_06, 2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,19,"������ԩ��(���)" );
		send_user(who, "%c%s",'!', "Ǯ���� 1/1");
	}	
}