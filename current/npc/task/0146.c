
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0201; }

// ���������촦��
void create()
{
        set_name("��Ʀʯ��");

        set_level(61);
	set_max_hp(1500);
	set_ap(400);
	set_dp(410);
	set_cp(100);
	set_pp(230);
	set_sp(170);
	set_walk_speed(3);
	set_attack_speed(12);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_16, 14) && !who->get_legend(TASK_16, 15) )
        {
		who->set_legend(TASK_16, 15);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,15,"�����ϵĿ���(���)" );
		send_user(who, "%c%s",'!', "��Ʀʯ�� 1/1");
	}
}
   