
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0251; }

// ���������촦��
void create()
{
        set_name("������֮��");

        set_level(81);
	set_max_hp(2300);
	set_ap(530);
	set_dp(520);
	set_cp(100);
	set_pp(290);
	set_sp(210);
	set_walk_speed(3);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_25, 22) && !who->get_legend(TASK_25, 23) )
        {
		who->set_legend(TASK_25, 23);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,23,"�������(���)" );
		send_user(who, "%c%s",'!', "������֮�� 1/1");
		USER_TASK_D->send_task_intro(who,2,TID_HANGUO,23);
		
	}
}
   