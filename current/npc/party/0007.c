#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 6010; }
void do_welcome(string arg);
// ���������촦��
void create()
{
        set_name("����ʹ��");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );

        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("����ʹ�ߣ�\n    ���ڱ��ο����ӳ٣�������б�Ǹ��������ڱ������в�����ÿλ��ҿ����ڴ���ȡ����10��Сʱ��˫��ʱ�䡣ף����Ϸ��죡\n"ESC"��ȡ����\ntalk %x# welcome.1\n"ESC"�뿪",id));
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i;
       	object who;   
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_save("bucang920") )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ʹ�ߣ�\n    ���Ѿ���ȡ�������ˣ�");
        		return ;	
        	}
        	i = gone_time( who->get_login_time() );
		if ( i+ who->get_game_time()<who->get_double_time())
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s��\n     ����˫������ʱ�仹ʣ %d �룬������ȡ\n"
		                ESC "�ر�\nCLOSE\n", me->get_name(), who->get_double_time() - i - who->get_game_time() ) );			
			return;		               
		}
        	who->set_save("bucang920",1);
		who->set_double_time(i+ who->get_game_time()+36000);

		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"����ʹ�ߣ�\n    ����ȡ��10��Сʱ˫��ʱ��Ĳ�����ף����Ϸ��죡");
        	break;
 
        }
        
}