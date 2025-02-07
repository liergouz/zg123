
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*33+26,32*33+29,32*34+3,32*37+22,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	int id;
	string tmp="";

	id = getoid(this_object());
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_33,25) && !who->get_legend(TASK_33,26) ) 
		tmp += sprintf(ESC HIY "��̽��Ϣ\ntalk %x# welcome.1\n",id); 
        if ( ( who->get_legend(TASK_33,26) && !who->get_legend(TASK_33,27) ) || ( who->get_legend(TASK_33,27) && !who->get_legend(TASK_33,29) ) )
		tmp += sprintf(ESC HIY "֤��ʵ��\ntalk %x# welcome.1\n",id); 
        if ( ( who->get_legend(TASK_33,29) && !who->get_legend(TASK_34,1) ) || ( who->get_legend(TASK_34,1) && !who->get_legend(TASK_34,3) ) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",id); 
        if ( who->get_legend(TASK_34,3) && !who->get_legend(TASK_34,4) )
		tmp += sprintf(ESC HIY "Ѱ������\ntalk %x# welcome.1\n",id); 
        if ( who->get_level() >= 25 && who->get_legend(TASK_37,21) && !who->get_legend(TASK_37,22) )
		tmp += sprintf(ESC HIY "��ͥ�ۻ�\ntalk %x# welcome.8\n",id); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0011))
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
        	if ( who->get_legend(TASK_33,25) && !who->get_legend(TASK_33,26) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǣ���Ҳ�������о������������ʱ�������飿\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_33,26) && !who->get_legend(TASK_33,27) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������̰��֮�Թ�Ȼǿ�ڰ�Σ������Ҳ����˵�ˣ��Ǳ����������ͽ𾫵��ػ�֮�����ȡ�ã�����ȡ����ʮ����������ʮ���𾫵Ļ����������Ի��������һ���������\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_33,27) && !who->get_legend(TASK_33,28) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҿ��㻹�Ǵ���ȡ������ͷ�ɣ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_33,28) && !who->get_legend(TASK_33,29) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������̰����̰�����������������ˢ����!\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_33,29) && !who->get_legend(TASK_34,1) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ų�֪���δ�ϰ���޵�֮��������������궴������Щ����Ϊ�����Ա��ﾫ����Ϊ����ϰ�����������Ͼͳ������������н����Ƕ�°��һ����֪���ĵط���������������������������֮����Щ�˵�����һ�ղ���һ�գ��·�������ʧ��һ�㣬���Ѿ�����°ȥ�����ˣ���֪��������μ�����û�����ڣ����Ȼ�ܹ�սʤΪ�������ľ��飬һ���а취�����������������궴�����Ͻǡ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_34,1) && !who->get_legend(TASK_34,2) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����´��������͸�����ʬ�ɡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_34,2) && !who->get_legend(TASK_34,3) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ڿ��Բ������������ˣ�����������ӣ���֪�������ҽ�Ρ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_34,3) && !who->get_legend(TASK_34,4) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ɵ������Ŵ���ע�⵽���Աߵı����𣿾������궴���ϴ��ı��䣬������������ƶ����̺��˾���֮���ľ����飬���ҵ�֮���κ��������������ɣ����������������������������ı���ġ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));

	    	break;
        case 2:
        	if ( who->get_legend(TASK_33,25) && !who->get_legend(TASK_33,26) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_33,26);
			who->add_exp(70000);
			who->add_potential(880);
			who->add_cash(58000);
			send_user(who,"%c%s",';',"��̽��Ϣ ���� 70000 Ǳ�� 880 ��Ǯ 58000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,37,"" );
			me->do_welcome(1);
        	}
        	break;   
	case 3:
        	if ( who->get_legend(TASK_33,26) && !who->get_legend(TASK_33,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_33,27);
        		who->delete_save("lidetujing");
        		who->delete_save("lidejinjing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,38,"֤��ʵ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"֤��ʵ��");
        	}
        	break;  
        case 4:
        	if ( who->get_legend(TASK_33,28) && !who->get_legend(TASK_33,29) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_33,29);
        		who->delete_save("lidetujing");
        		who->delete_save("lidejinjing");
			who->add_exp(71000);
			who->add_potential(890);
			who->add_cash(60000);
			send_user(who,"%c%s",';',"֤��ʵ�� ���� 71000 Ǳ�� 890 ��Ǯ 60000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,38,"" );
			me->do_welcome(1);
        	}
        	break;
	case 5:
        	if ( who->get_legend(TASK_33,29) && !who->get_legend(TASK_34,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;	
        		who->set_legend(TASK_34,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,39,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;  
        case 6:
        	if ( who->get_legend(TASK_34,2) && !who->get_legend(TASK_34,3) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_34,3);
			who->add_exp(72000);
			who->add_potential(900);
			who->add_cash(61000);
			send_user(who,"%c%s",';',"�������� ���� 72000 Ǳ�� 900 ��Ǯ 61000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,39,"" );
			me->do_welcome(1);
        	}
        	break;
	case 7:
        	if ( who->get_legend(TASK_34,3) && !who->get_legend(TASK_34,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_34,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,40,"Ѱ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ѱ������");
        	}
        	break;  
        case 8:
        	if( who->get_level() >= 25 && who->get_legend(TASK_37,21) && !who->get_legend(TASK_37,22) ) 
        		send_user(who,"%c%s",':',sprintf("%s:\n    ����һ�����Ҳ�Ǹþ۾��ˣ��һᾡ���ȥ�ģ�лл��������š�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;  
        case 9:
        	if ( who->get_level() >= 25 && who->get_legend(TASK_37,21) && !who->get_legend(TASK_37,22) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_37,22);
			who->add_exp(1400);
			who->add_potential(70);
			who->add_cash(1400);
			send_user(who,"%c%s",';',"��ͥ�ۻ� ���� 1400 Ǳ�� 70 ��Ǯ 1400");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,65,"" );
        	}
        	break;    
        }
}