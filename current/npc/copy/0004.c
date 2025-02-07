#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;
int host_type;

// ��������ȡ��������
int get_char_picid() { return 1001; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// ���������촦��
void create()
{
	object me=this_object();
        set_name("�ع���̽");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	object me=this_object();

	id = getoid(me);
	if ( !get("finish") )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�ع���̽��\n    �����ǳ�὾�Ӫ������������ˣ�Ҫ�뿪��\n"ESC"�뿪��὾�Ӫ\ntalk %x# welcome.1\n"ESC"�뿪",id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�ع���̽��\n    ̫���ˡ������ڰ������ع�ƽ���˳����������Ϊ�ع����˴󹦣�����������ع��ɣ�\n"ESC"ȷ��\ntalk %x# welcome.1\n"ESC"�뿪",id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy;
       	object who, item,map;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "�����С���");
	        who->set_2("travel.z", 50);
	        who->set_2("travel.p", 221067);
	        set_effect(who, EFFECT_TRAVEL, 6);
		break;
	}
}


