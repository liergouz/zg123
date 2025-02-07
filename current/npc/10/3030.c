
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 5401; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("������");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*28+30,32*29+25,})]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_28,29) && !who->get_legend(TASK_28,30) ) 
		tmp += sprintf(ESC HIY "ѯ��ԭ��\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_28,30) && !who->get_legend(TASK_29,16) ) 
		tmp += sprintf(ESC HIY "������Ϣ\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_29,24) && !who->get_legend(TASK_29,25) ) 
		tmp += sprintf(ESC HIY "Ѱ�ұ���\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0921))
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_28,29) && !who->get_legend(TASK_28,30) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ͷ·��ҵ����������ҿ���Ҳ�������������鰡��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_28,29) && !who->get_legend(TASK_29,16) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��һ�������鱦��������������֪���������Ǵ�˵�е�ϡ��������ȴԵ�һ�棬����һƳ����Ҳ�����ټ�����ֻ��ӵ�����Ҿʹ����޺��ˣ�����ɽ��ãã���ҵ�ϡ�����񵽵ײ���δ����أ���������˵���ܹܼ���ʶ�㣬�������ƺ�ȴ������ͬ����������ֻ�ð��������ˡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_29,24) && !who->get_legend(TASK_29,25) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������������������ˣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));

	    	break;
        case 2:
        	if ( who->get_legend(TASK_28,29) && !who->get_legend(TASK_28,30) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,30);
			who->add_exp(48000);
			who->add_potential(680);
			who->add_cash(50000);
			send_user(who,"%c%s",';',"ѯ��ԭ�� ���� 48000 Ǳ�� 680 ��Ǯ 50000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,25,"" );
			me->do_welcome(1);
        	}
        	break;   
	case 3:
        	if ( who->get_legend(TASK_28,29) && !who->get_legend(TASK_29,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_29,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,26,"������Ϣ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������Ϣ");
        	}
        	break;  
        case 4:
        	if ( who->get_legend(TASK_29,24) && !who->get_legend(TASK_29,25) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ϡ������",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/final/33/1775",5);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_29,25);
			who->add_exp(55000);
			who->add_potential(730);
			who->add_cash(52000);
			send_user(who,"%c%s",';',"Ѱ�ұ��� ���� 55000 Ǳ�� 730 ��Ǯ 52000 �����ϻ��� 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,29,"" );
        	}
        	break; 
        }
}