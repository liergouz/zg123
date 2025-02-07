
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0052; }

// ���������촦��
void create()
{
        set_name("��ͷ��ɽ");

        set_level(50);
	set_max_hp(1000);
	set_ap(360);
	set_dp(400);
	set_cp(100);
	set_pp(260);
	set_sp(160);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_12, 4) && !who->get_legend(TASK_12, 5) )
        {
		who->set_legend(TASK_12, 5);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,2,"��������(���)" );
		send_user(who, "%c%s",'!', "��ͷ��ɽ 1/1");
	}
}
