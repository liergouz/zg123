#include <npc.h>
#include <ansi.h>
#define MARRY_D  "sys/user/marry"
inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 9409; }

// ���������촦��
void create()
{
        set_name( "����" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	MARRY_D->do_look1(this_object(),who);
}

void do_welcome(string arg) {MARRY_D->do_welcome1(this_object(),this_player(),arg);}
