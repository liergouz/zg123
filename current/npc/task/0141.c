
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 1001; }

// ���������촦��
void create()
{
        set_name("ɽ�����ϸ");

        set_level(37);
	set_max_hp(700);
	set_ap(290);
	set_dp(280);
	set_cp(100);
	set_pp(180);
	set_sp(120);
	set_walk_speed(3);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_13, 16) && !who->get_legend(TASK_13, 17) )
        {
		who->set_legend(TASK_13, 17);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,6,"ɽ�����ϸ��1��(���)" );
		send_user(who, "%c%s",'!', "ɽ�����ϸ 1/1");
	}
}
