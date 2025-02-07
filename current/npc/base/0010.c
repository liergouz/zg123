
// �Զ����ɣ�/make/npc/make0010

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );
void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5410; }

// ���������촦��
void create()
{
        set_name("��վ�ϰ�");
        set_city_name("���ִ�");

        set_2( "talk", ([
                "goto"    : (: do_goto :),
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 2);
//        set("legend", ({ 44 }));
//	set("mpLegend",([0:({32*48+12, 32*1+12,}),]));
	set("mpLegend2",([0:({32*48+12,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp;
//	if ( who->get_legend(TASK_NEWBIE_01, 10)&&!who->get_legend(TASK_NEWBIE_01, 11) )
	if ( who->get_legend(TASK_48, 11) && !who->get_legend(TASK_48, 12) )
	{
		tmp = get_name() + "��\n    "+"/quest/word"->get_normal_word(this_object()) + "\n"+
               		sprintf(ESC  +HIY+ "������Ϣ\ntalk %x# welcome.1\n",getoid(this_object())) ;	
	}
//	if ( !who->get_legend(TASK_NEWBIE_01, 12) )
	if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
	{
		if ( !stringp(tmp) )
			tmp = get_name() + "��\n    "+"/quest/word"->get_normal_word(this_object()) + "\n"+
               			sprintf(ESC  +HIY+ "�ɸ봫��\ntalk %x# welcome.3\n",getoid(this_object())) ;	
			
		else
			tmp +=	 sprintf(ESC  +HIY+ "�ɸ봫��\ntalk %x# welcome.3\n",getoid(this_object())) ;	
	}
	if ( stringp(tmp) )
	{
		tmp += ESC"�뿪";
		send_user( who, "%c%s", ':',tmp);
	}	
	else
		"/sys/task/travel"->do_look(this_object(), who);        
}

// �������ƶ�����
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto(this_object(), this_player(), arg);     
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who, item;     
        string result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:	
//		if ( !who->get_legend(TASK_NEWBIE_01, 10)||who->get_legend(TASK_NEWBIE_01, 11) )
//			return;
		if ( who->get_legend(TASK_48, 11) && !who->get_legend(TASK_48, 12) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��ҩ���ϰ廹���Ǿ��ľ������¾ͽ������ˣ�����İɣ����Ҵ�����������Ϣ���һ����˰ѿ��Ŵ���ҩ���ϰ�ģ������պ���ı��꣬æȥ�ɣ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
			
		break;        	
	case 2:	
//		if ( !who->get_legend(TASK_NEWBIE_01, 10)||who->get_legend(TASK_NEWBIE_01, 11) )
//			return;
//		item = new("/item/91/9110");
//		if ( !item )
//			return ;
//		item->set_amount(10);
//                p =item->move(who, -1);
//                if ( p == 0 )
//                {
//                	destruct(item); 
//                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
//                	return ;
//                }
//                item->add_to_user(p);

		if ( who->get_legend(TASK_48, 11) && ! who->get_legend(TASK_48, 12))
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 12);
			who->add_exp(290);
			who->add_potential(20);
			who->add_cash(500);
			send_user(who,"%c%s",';',"̽������ ���� 290 Ǳ�� 20 ��Ǯ 500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,105,"" );		
		me->do_welcome(3);
		}
		break;
	case 3:	
//		if ( who->get_legend(TASK_NEWBIE_01, 12)&&who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
//		if ( !who->get_legend(TASK_NEWBIE_01, 12) )
		if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���������ˣ��ҵ��˺þã�����������һ��ɸ봫�飬�Ǹ��ӻ����ϰ�ĳ���������һֱ�Ҳ����������͹�ȥ���㿴�������æ�ø�ʲô�Ƶģ���Ը��������æ���ӻ����ϰ�����ҵ����������������Ұ�ȫ�͵����ɸ봫��Ļ������ά����ġ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
//		else if ( !who->get_legend(TASK_NEWBIE_01, 13) ) 
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���͵������ǳ�����Ŷ��Ӧ�ñȽϼ��ģ���ɵþ��죬�����˱��˷���������ɾͲ����ˡ�\n"ESC"�뿪",me->get_name()));
		break;     
	case 4 :
//		if ( who->get_legend(TASK_NEWBIE_01, 12)&&who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			item = new("/item/98/9881");
			if ( !item )
				return ;
	                p =item->move(who, -1);
	                if ( p == 0 )
	                {
	                	destruct(item); 
	                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
	                	return ;
	                }
	                item->add_to_user(p);
			who->set_legend(TASK_48, 13);	
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,106,"�ɸ봫��" );
			send_user(who,"%c%s",';',"��õ�"HIY"������");
			send_user( who, "%c%s", '!', "�������"HIY"�ɸ봫��"NOR"����");
		}
		break;
	}		
}
