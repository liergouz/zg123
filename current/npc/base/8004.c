
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 3; }

// ��������ȡ��������
int get_char_picid() { return 5404; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�������ϰ�");
        set_city_name("�ܹ�");

        set_2( "good", ([
                "01" : "/item/74/1020",
                "02" : "/item/74/1030",
                "03" : "/item/74/1040",
                "06" : "/item/75/1020",
                "07" : "/item/75/1030",
                "08" : "/item/75/1040",

        ]) );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 39);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "�������ʺ��ҵ�������\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
}

void do_welcome( string arg )
{
        object me = this_object();
        "/npc/base/0004"->do_welcome2(me, "99");
}