#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 2113; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	int iTime=time();

	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("һƬ�Ӳݴ���������һֻ�����ʯͷʨ�ӡ�ʯͷʨ�ӵĻ���������͸���������磬�ƺ�����������һ�����ص�ͨ������ȷ��Ҫ�ƿ�ʨ�ӣ����������ͨ����\n"ESC"����ͨ��\ntalk %x# welcome.1\n"ESC"�뿪",id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,iTime,i,size;
       	object who, item;
       	string name,*nTmp,tmp;
	mixed *mxTime;  
	  

        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
   		who->add_to_scene(804,32,44,get_d(who), 40971, 0, 40971, 0 );
        	break;

	}

}

