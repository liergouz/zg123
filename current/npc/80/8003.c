
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 0250; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����ͷ");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
//	set("level",38);
//	set("legend",({32*10+3}));
 	set("mpLegend",([35:({32*10+3}),]));
 	set("mpLegend2",([35:({32*37+28,32*10+5,}),]));
        setup();
}

// �������Ի�����
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
	if ( ( who->get_level() >= 35 && !who->get_legend(TASK_10,3) ) || ( who->get_legend(TASK_10,3) && !who->get_legend(TASK_10,5) ) )
		tmp += sprintf(ESC HIY "��ȡ����\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_level() >= 35 && who->get_legend(TASK_37,27) && !who->get_legend(TASK_37,28) )
		tmp += sprintf(ESC HIY "��ׯ�ڵĳ�ͷ\ntalk %x# welcome.4\n",getoid(me));

	send_user(who,"%c%s",':',sprintf( "%s��\n    �����ЩҰ��Խ��Խ���񣬿��������ҼҲ�԰��ץ���ģ���������ׯ�ڳ��ò���ô��ѽ�����������Ӳ��аɣ��ҵ�ȥ�ҵ����������\n", get_name(),  ) 
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
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_10,3)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �׻�˵���ɸ���Ϊ����֮�������Ӳ��ã���ôʩ�ʶ��������õ�ׯ�ڣ��ҿ��ǳԾ����⻵���ӵĿ�ͷ��һ�����ൽͷ���ճ�ȴ���ã���һ�Ҽ��ڶ����ż�һ�ٱ�һ�ٵ����ӡ�\n    ����˵�и���������һֱ���о����ӣ�������������кõ�����ӣ��������Ұ����ô�����Ҹ������Ѳ�����������ȥ����������Ҫ���������ɡ�\n    �����������Ҳ��Զ�������Ҷ��Ϸ������ʯ��\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_10,3) && !who->get_legend(TASK_10,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ϊ�����˰ɣ���й��������ȥ����Ҫ����һ�������ģ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_10,4) && !who->get_legend(TASK_10,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����̫���ˣ���������ׯ�ڵĺ��ճ������ˣ�̫��л���ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_10,3)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_10,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,9,"��ȡ���֣�1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ȡ���֣�1��");
        	}
        	break;
       case 3:
        	if ( who->get_legend(TASK_10,4) && !who->get_legend(TASK_10,5) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_10,5);
			who->add_exp(3000);
			who->add_potential(70);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"��ȡ���֣�1�� ���� 3000 Ǳ�� 70 ��Ǯ 2000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,9,"" );
        	}
        	break;     
        case 4:
        	if ( who->get_level() >= 35 && who->get_legend(TASK_37,27) && !who->get_legend(TASK_37,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���˺ü��죬�����͹����ˣ������ҿ������ͷ���ò����á�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 5:
        	if ( who->get_level() >= 35 && who->get_legend(TASK_37,27) && !who->get_legend(TASK_37,28) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��ׯ�ڵĳ�ͷ",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_37,28);
			who->add_exp(2500);
			who->add_potential(65);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"��ׯ�ڵĳ�ͷ ���� 2500 Ǳ�� 65 ��Ǯ 2000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,72,"" );
        	}
        	break;   
        }
}