
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 7405; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��Ʒ���ϰ�");
	set_real_name("�缧");
        set_city_name("κ��");

        set_2( "good", ([
                "01" : "/item/88/7020",
                "02" : "/item/88/7030",
                "03" : "/item/88/7040",
                "06" : "/item/87/7020",
                "07" : "/item/87/7030",
                "08" : "/item/87/7040",
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
	"/quest/help"->send_help_tips(who, 51);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "�������ʺ��ҵ�װ����\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
}

void do_welcome( string arg )
{
        object me = this_object();
        "/npc/base/0005"->do_welcome2(me, "99");
}
