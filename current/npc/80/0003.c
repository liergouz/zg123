#include <npc.h>
#include <ansi.h>
#define MARRY_D  "sys/user/marry"
inherit OFFICER;

void do_welcome(string arg);
void do_qixi(string arg);

// ��������ȡ��������
int get_char_picid() { return 5403; }

// ���������촦��
void create()
{
        set_name( "����" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
		"qixi"             : (: do_qixi :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	MARRY_D->do_look(this_object(),who);
}

void do_welcome(string arg) {MARRY_D->do_welcome(this_object(),this_player(),arg);}
void do_qixi(string arg) {"sys/party/qixi"->do_qixi(this_object(),this_player(),arg);}