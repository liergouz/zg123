#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 853; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("��˫������");
//        set_2( "talk", ([
//                 "welcome"         : (: do_welcome :),
//        ]) );
        setup();
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	string org_name;
	
	org_name = WUSHUANG->get_occupy_org();
	
	if ( !sizeof(org_name) )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������˫������������ռ���״̬��\n"ESC"�뿪",me->get_name()));
		return ;		
	}
	if ( WUSHUANG->check_war_time() == 1 )
	{
		if ( org_name == who->get_org_name() )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������ǹ���ʱ�䣬��úñ��������Ҫ���а��������ˣ�\n"ESC"�뿪",me->get_name()));
		else 
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ߺ��ˣ�����Ҫ�������ˣ�\n"ESC"�뿪",me->get_name()));
	}
	else 
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��˫��Ϊ"HIR"%s"NOR"���أ��Ǳ���������˵�һ�ɽ�ֹ���룡��\n"ESC"�뿪",me->get_name(),org_name));
}

