
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
        set_name("����Ҷ��");

        set_level(73);
	set_max_hp(1900);
	set_ap(480);
	set_dp(500);
	set_cp(100);
	set_pp(280);
	set_sp(200);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_21, 28) && !who->get_legend(TASK_21, 29) )
        {
		who->set_legend(TASK_21, 29);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,39,"�̰�����(���)" );
		send_user(who, "%c%s",'!', "����Ҷ�� 1/1");
	}
}
   