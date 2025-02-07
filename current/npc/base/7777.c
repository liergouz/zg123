
#include <npc.h>
#include <ansi.h>
#include <map.h>
#include <task.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 6010; } 

// ���������촦��
void create()
{
        set_name( "PK��������" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
        int status;
        object me = this_object();
        if( is_player(who) ) 
	        send_user( who, "%c%c%w%s", ':', 3, 6010,
        		sprintf("%s��\n    ��Ҫ���������һչ�۷�����������������Ҫ�õ��ٷ��ͳ��ķ����𣿱����μ���������һ�ɣ�ֻҪ����10000��Ϸ�ҵı����ѣ�ֻҪ�����������ĸ���PK����һ�ٶ����һ�н����������룡\n"
                	ESC "���뱨��\ntalk %x# welcome.1\n"
                	ESC "��ֻ��������\nCLOSE\n", me->get_name(), getoid(me) ) );
	else        
	if (me->get("start")==0)
	        send_user( who, "%c%c%w%s", ':', 3, 6010,
        		sprintf("%s��\n    ������ʲô�أ��������showdatָ�����鿴������ҵı�����\n"
                	ESC "���뿪����������\ntalk %x# welcome.2\n"
                	ESC "��ֻ��������\nCLOSE\n", me->get_name(), getoid(me) ) );
	else
	        send_user( who, "%c%c%w%s", ':', 3, 6010,
        		sprintf("%s��\n    ������ʲô�أ��������showdatָ�����鿴������ҵı�����\n"
                	ESC "����رձ�������\ntalk %x# welcome.3\n"
                	ESC "���뱨��\ntalk %x# welcome.1\n"
                	ESC "��ֻ��������\nCLOSE\n", me->get_name(), getoid(me), getoid(me) ) );
	                	
                	
}

void do_welcome( string arg )
{
        object npc, who, me, *inv;
        int i, flag, size;
        me = this_object();
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if (me->get("start")==0)
                {
                	send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    ������δ��ʼ�ء�\n" , me->get_name() ) );
                	return;
                }        	
                if (who->get_save("pk_game")==1)
                {
                	send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    �Բ������ѱ����μӻ�������ظ�������\n" , me->get_name() ) );
                	return;
                }
                if (who->get_cash()<10000)
                {
                	send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    �Բ�����ı����Ѳ�������ʱ���ܱ�����\n" , me->get_name() ) );
                	return;
                }              
                who->add_cash(-10000);  
                who->set_save("pk_game", 1);
                log_file("pkgame.dat", sprintf("%s %s %s(%d)\n", short_time(), who->get_id(), who->get_name(), who->get_number()));
                send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    ��ɹ��ر����μӻ���뾲����ػ֪ͨ��\n" , me->get_name() ) );
                break;
	case 2:
		me->set("start", 1);          
		send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    �������ܿ�����\n" , me->get_name() ) );     
		break;
	case 3:
		me->set("start", 0);          
		send_user( who, "%c%c%w%s", ':', 3, 6010, sprintf("%s��\n    �������ܹرա�\n" , me->get_name() ) );     
		break;		
        }
}