
// �Զ����ɣ�/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// ��������ȡ��������
int get_char_picid() { return 0750; }

// ���������촦��
void create()
{
        set_name("����ħ");

        set_level(62);
	set_max_hp(1600);
	set_ap(410);
	set_dp(420);
	set_cp(100);
	set_pp(240);
	set_sp(180);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_17, 4) && !who->get_legend(TASK_17, 5) )
        {
		who->set_legend(TASK_17, 5);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,21,"ҹ���е�����(���)" );
		send_user(who, "%c%s",'!', "����ħ 1/1");
	}
}
   