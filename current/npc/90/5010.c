
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );

// ��������ȡ��������
int get_char_picid() { return 1051; }

// ��������ȡ��������
string get_fam_name() { return "éɽ"; }

// ��������ȡ����˳��
int get_fam_order() { return 6; }


// ���������촦��
void create()
{
        set_name("��ͯ");
        set_real_name("������");

        set_2( "talk", ([
                "go"   : (: do_goto :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	"/sys/task/travel"->do_look2(this_object(), who);        
}

// �������ƶ�����
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto2(this_object(), this_player(), arg);     
}