
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0200; }

// ���������촦��
void create()
{
        set_name("������");

        set_level(100);
	set_max_hp(3600);
	set_ap(620);
	set_dp(575);
	set_cp(340);
	set_pp(250);
	set_sp(120);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);
        
        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_34, 1) && !who->get_legend(TASK_34, 2) )
        {
		who->set_legend(TASK_34, 2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,39,"��������(���)" );
		send_user(who, "%c%s",'!', "������ 1/1");
	}
}
