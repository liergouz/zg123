#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <effect.h>
inherit OFFICER;
inherit "/inh/std/invite";

// ��������ȡ��������
int get_char_picid() { return 5313; }

string get_fam_name() { return "����"; }

// ���������촦��
void create()
{	
	object me = this_object();
        set_name("������ļԱ||||"+me->get_fam_name());
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));   
        setup();
}

