#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
object npc;
int iStart,iFinish;
// ��������ȡ��������
int get_char_picid() { return 6009; }
void do_welcome(string arg);
// ���������촦��
void create()
{
        set_name("ս���ʹ��");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
	iStart = mktime(2007,3,21,10,0,0);
	iFinish = mktime(2007,3,21,22,0,0);
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object()),iTime=time();
	if ( iTime > iFinish )
	{
		this_object()->remove_from_scene();
		destruct(this_object());
		return ;	
	}
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    �װ���%s��ã��������������ս���ʹ�ߡ�������321���������գ����ԣ��ڽ����10�㡫22���ڼ�����ս������Ҷ����Դ���������ȡһ��4Сʱ��"HIR"321����������˫������ʱ��"NOR"�����ǹ��˽���22���û�л�����ȡ�ˣ��Ͽ���ȡ�ɣ�\n"ESC"��ȡ��321����������˫������ʱ�䡱\ntalk %x# welcome.0\n"ESC"��ϸ����\ntalk %x# welcome.5\n"ESC"�뿪",who->get_name(),id,id));
}


void do_welcome( string arg )
{
        object me = this_object();
        if ( time() > iFinish )
	{
		me->remove_from_scene();
		destruct(me);
		return ;	
	}
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id;
       	object who;   
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 0:
        	i = 4-who->get_save("double321");
//        	if ( i > 3 )
//			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    321����������˫������ʱ��һ��������ȡ4��Сʱ��������ȡʱ������ڽ����10�㡫22�㡣�㻹��%dСʱ˫������ʱ�������ȡ����Ҫ��ȡ�೤ʱ���321����������˫������ʱ�䣿\n"ESC"һСʱ\ntalk %x# welcome.1\n"ESC"��Сʱ\ntalk %x# welcome.2\n"ESC"��Сʱ\ntalk %x# welcome.3\n"ESC"��Сʱ\ntalk %x# welcome.4\n"ESC"�뿪",i,id,id,id,id));
//		else if ( i > 2 )
//			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    321����������˫������ʱ��һ��������ȡ4��Сʱ��������ȡʱ������ڽ����10�㡫22�㡣�㻹��%dСʱ˫������ʱ�������ȡ����Ҫ��ȡ�೤ʱ���321����������˫������ʱ�䣿\n"ESC"һСʱ\ntalk %x# welcome.1\n"ESC"��Сʱ\ntalk %x# welcome.2\n"ESC"��Сʱ\ntalk %x# welcome.3\n"ESC"�뿪",i,id,id,id));
		if ( i > 1 )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    321����������˫������ʱ��һ��������ȡ4��Сʱ��������ȡʱ������ڽ����10�㡫22�㡣�㻹��%dСʱ˫������ʱ�������ȡ����Ҫ��ȡ�೤ʱ���321����������˫������ʱ�䣿\n"ESC"һСʱ\ntalk %x# welcome.1\n"ESC"��Сʱ\ntalk %x# welcome.2\n"ESC"�뿪",i,id,id,));
		else if ( i == 1 )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    321����������˫������ʱ��һ��������ȡ4��Сʱ��������ȡʱ������ڽ����10�㡫22�㡣�㻹��%dСʱ˫������ʱ�������ȡ����Ҫ��ȡ�೤ʱ���321����������˫������ʱ�䣿\n"ESC"һСʱ\ntalk %x# welcome.1\n"ESC"�뿪",i,id,));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"ս���ʹ�ߣ�\n    ���Ѿ�û��˫������ʱ�������ȡ�ˣ�");
		break;
	case 1..2:
        	if ( who->get_save("double321") >= 4 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"ս���ʹ�ߣ�\n    ���Ѿ�û��˫������ʱ���ˣ�");
        		return ;	
        	}
        	if ( who->get_save("double321") + flag > 4 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"ս���ʹ�ߣ�\n    ��������ȡ��ô��˫������ʱ�䣡");
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
		
        	who->add_save("double321",flag);
		who->set_double_time(i+ who->get_game_time()+3600*flag);
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "" ); 
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" ); 

		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    ����ȡ��%d��Сʱ˫������ʱ�䣬ף����Ϸ��죡",flag));
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("ս���ʹ�ߣ�\n    "HIR"321����������˫������ʱ��"NOR"���ڽ���"HIR"10ʱ��22ʱ"NOR"���ر𿪷ŵĻ���ڻ�ڼ䣬�������ȡ����������ԭ��˫������ʱ����ر�˫������ʱ�䡣����321����������˫������ʱ��"HIR"�����Ը�����˫������ʱ�����"NOR"������������Ѿ���˫������ʱ�䣬�����������е�˫������ʱ��������ſ�������ȡ��˫������ʱ�䡣\n"ESC"�뿪",));
		break; 
        }
        
}

void set_open(object who)
{
	if ( time() >= iFinish )
	{
		send_user(who,"%c%s",'!',"�ʱ���ѹ������ܿ���");
		return ;
	}
	if ( objectp(npc) )
		return ;
	npc = new("npc/party/0026");
	npc->add_to_scene(80,285,177,4);
	call_out("gonggao",5);
	send_user(who,"%c%s",'!',"�����");
}

void set_close(object who)
{
	remove_call_out("gonggao");
	if ( objectp(npc) )
	{
		npc->remove_from_scene();
		destruct(npc);	
	}
	send_user(who,"%c%s",'!',"��ر�");
}

void gonggao()
{
	remove_call_out("gonggao");
	if ( time() > iFinish )
	{
		if ( objectp(npc) )
		{
			npc->remove_from_scene();
			destruct(npc);	
		}
		return ;
	}
	call_out("gonggao",900);
	CHAT_D->sys_channel(0,HIR"321����������˫������ʱ��"NOR"��������Ƚ����У���������ڽ����10ʱ��22ʱ�ڼ���Ե��ܹ���ս���ʹ����ȡ"HIR"321����������˫������ʱ��"NOR"������ʲô���Ͽ��ж��ɣ�");
}