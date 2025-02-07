
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "����ͷ�������ҵģ����Ҹ����ʵı��ڶ������ס���",
        "���Ҿ����ھֻ���һ��������������˼Ҿ�Ȼû�ա���",
        "���Ҿ����ھֻ������ѷ��磬���������˼Ҿ�Ȼû�ա���",
        "�ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���",
});
void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5801; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("���ë");
        set_city_name("κ��");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
	set("mpLegend2",([0:({32*19+2,32*19+5,}),]));
        setup();
}

// �������Ի�����
void do_look( object who ) 
{
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,this_object());
	if ( who->get_legend(TASK_19,1) && !who->get_legend(TASK_19,2) )
		tmp += sprintf(ESC HIY "Ѱ�Ҵ��«����\ntalk %x# welcome.1\n",getoid(this_object()));
	if ( (who->get_legend(TASK_19,2) && !who->get_legend(TASK_19,3)) || (who->get_legend(TASK_19,3) && !who->get_legend(TASK_19,5)) )
		tmp += sprintf(ESC HIY "������\ntalk %x# welcome.1\n",getoid(this_object()));

	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
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
        	if ( who->get_legend(TASK_19,1) && !who->get_legend(TASK_19,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ӻε�����ҿɲ�Ը�������ˣ�������õ��������Ұ���¡�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,2) && !who->get_legend(TASK_19,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ӿ����������˲��󵽵ģ�����������ǳ�������ҩ�����ϸ���������ˮ�İ��ش������κ����ڣ�ĥ�۷��ÿ��Գ������ϣ�������ܸ��������Ҿ��͸����Ӹ��㡣\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,3) && !who->get_legend(TASK_19,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ò��������ڣ�����«�����ҿɲ����͸��㡣\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_19,4) && !who->get_legend(TASK_19,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������ɵ�ϣ��ÿ��Գ������ϵ����κ����ڻ����ÿ������õĴ��«���ӣ�����ɵ�Ŀɰ�����\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_legend(TASK_19,1) && !who->get_legend(TASK_19,2) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,2);
			who->add_exp(3800);
			who->add_potential(165);
			who->add_cash(3550);
			send_user(who,"%c%s",';',"���«��1�� ���� 3800 Ǳ�� 165 ��Ǯ 3550");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,54,"" );
			me->do_welcome(1);
       		}
        	break;
	case 3:
        	if ( who->get_legend(TASK_19,2) && !who->get_legend(TASK_19,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_19,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,27,"���«��2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���«��2��");
        	}
        	break;      
        case 4:
        	if ( who->get_legend(TASK_19,4) && !who->get_legend(TASK_19,5) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		item = new("item/98/0084");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			send_user(who,"%c%s",'!', "��Я������Ʒ̫����");	
        			destruct(item);
        			return;
        		}
        		item->add_to_user(p);
			who->set_legend(TASK_19,5);
			who->add_exp(3830);
			who->add_potential(165);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"���«��2�� ���� 3830 Ǳ�� 165 ��Ǯ 3500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,27,"" );
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,10,"���«��3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���«��3��");
       		}
        	break;
        }
}