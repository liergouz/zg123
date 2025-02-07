
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0902; }

// ���������촦��
void create()
{
        set_name("Թħ");

        set_level(49);
	set_max_hp(900);
	set_ap(350);
	set_dp(390);
	set_cp(100);
	set_pp(230);
	set_sp(160);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_12, 1) && !who->get_legend(TASK_12, 2) )
        {
		who->set_legend(TASK_12, 2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,1,"֣����������(���)" );
		send_user(who, "%c%s",'!', "Թħ 1/1");
	}
}
