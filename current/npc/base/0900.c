
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>

inherit OFFICER;

void do_goto( string arg );
void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5205; }

// ���������촦��
void create()
{
        set_name("���޵�������");
        set_city_name("�ܹ�");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me=this_object();
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��˵��ңԶ�Ķ���������һ������������㣬������һƬ�����½�أ������кܶ���Ϊ��֪�����ܣ�����ȥ����̽����\n"ESC"ȥ���޵�̽��\ntalk %x# welcome.23\n"ESC"�뿪",me->get_name(),getoid(me)));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who, item;     
        string result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 23:
		p = 166148;
        	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "�����С���");	                
                who->set_2("travel.z", 549);
                who->set_2("travel.p", p);
                who->set_2("travel.money", 0);
                set_effect(who, EFFECT_TRAVEL, 3);
		break;
	}		
}
