
// �Զ����ɣ�/make/npc/make0010

#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );

// ��������ȡ��������
int get_char_picid() { return 5410; }

// ���������촦��
void create()
{
        set_name("��վ�ϰ�");
	set_real_name("�ɺ�");
        set_city_name("�ܹ�");

        set_2( "talk", ([
                "goto"    : (: do_goto :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	"/sys/task/travel"->do_look(this_object(), who);        
}

// �������ƶ�����
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto(this_object(), this_player(), arg);     
}