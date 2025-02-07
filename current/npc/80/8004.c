
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_10,3) && !who->get_legend(TASK_10,4) )
		tmp += sprintf(ESC HIY "��ȡ����\ntalk %x# welcome.1\n",getoid(me));
	if ( ( who->get_legend(TASK_10,4) && !who->get_legend(TASK_10,6) ) || ( who->get_legend(TASK_10,6) && !who->get_legend(TASK_10,7) ) )
		tmp += sprintf(ESC HIY "�������̷�\ntalk %x# welcome.1\n",getoid(me));
			
	send_user(who,"%c%s",':',sprintf( "%s��\n    �ú�����ȥ�ģ�·�ϼ���ξ������ͷ���и����ڵ����ˣ��ɷ����Ҵߴ�������˵���üӿ��ٶȣ����Ѿ��ȼ��ˣ�վ������ҹ���׵ģ�����\n", get_name(),  ) 
			+ tmp +
			ESC"�뿪"
			);

}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_10,3) && !who->get_legend(TASK_10,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �׻�˵���ɸ���Ϊ����֮����û�кõ�������ô�ֵó��õ�ׯ�ڣ������������һ�������ӣ�����ȥ�ɣ�Ҳ���Ǹ�������ʵ�飬��ȥ��������Ҵߴ��ǳ̷磬���������ҰѶ���������\n"ESC"�õ�����\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_10,4) && !who->get_legend(TASK_10,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰ�������Ѹ������˵㶫������ξ������ͷ���˹�����������˵����ʱ��Ϊ���ֲ��������������˸���������������������ڣ���˵�������ո�ǿ������ξ������ͷ�ĺ����ѣ������ϷŲ�������İ�����ô�������ˣ�Ҳû������������˵�������������������̨��Ҳ��֪��������ʲô�������ȥ�����ɡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_10,6) && !who->get_legend(TASK_10,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ������Сæ�����ϰ����𣿿����Ұ����ķ��ϣ����ȥ�����������ɣ�����Ŀ켱���ˣ�\n"ESC"�뿪", me->get_name()));

        	break;
        case 2:
        	if ( who->get_legend(TASK_10,3) && !who->get_legend(TASK_10,4) )
        	{
        		item = new("item/98/0040");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			return ;
        		}
        		item->add_to_user(p);
        		send_user(who, "%c%s", '!', HIY"���� 1/1");
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_10,4);
        		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,9,"��ȡ���֣�1��(���)" );
        		me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_10,4) && !who->get_legend(TASK_10,6) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_10,6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,10,"�������̷磨2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������̷磨2��");
        	}
        	break;
        }
}