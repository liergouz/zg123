
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5601; }

// ���������촦��
void create()
{
        set_name("�ʿ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));          
	set("mpLegend2",([0:({32*26+6,32*26+9,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
        tmp += CHAIN_D->get_chain_menu(who,me);
        if ( who->get_legend(TASK_26,5) && !who->get_legend(TASK_26,6) ) 
		tmp += sprintf(ESC HIY "ָ������\ntalk %x# welcome.1\n",getoid(me)); 
        if ( (who->get_legend(TASK_26,6) && !who->get_legend(TASK_26,7)) || (who->get_legend(TASK_26,7) && !who->get_legend(TASK_26,9)) ) 
		tmp += sprintf(ESC HIY "���Ŀ���\ntalk %x# welcome.1\n",getoid(me)); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0301))
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
	       	if ( who->get_legend(TASK_26,5) && !who->get_legend(TASK_26,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ˣ����ص��ģ���ʵʦ����ʮ��ǰ���Ѿ��㵽�������н���Ľ�����������������֮ǰ�Ѿ������׽������ķ����̸����ң���������ʩչ������������ʱ���һ���Ҫ��İ�����\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_26,6) && !who->get_legend(TASK_26,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ʵ���ˮ�������Դͷ����ȶ�����Ľ�ʬ���߹���������ʩ�������ˮ�������ͬʱ��������һ�����ո�ǿ��������ȥ��ȶ�������ȥɱ����Щ�����ˮ��Դͷ���ҿ����Ǹ����ո�ǿ���ˣ������ھ�Ҫʩ�������ˣ���Ҳ�Ͽ�ȥ��ȶ�������ɱ��30����ʬ��30���߹�����˳��ɱ����Щ�����Դͷ��ʱ���ҵķ���Ӧ��Ҳ�����ˣ���ʱ����ͻ���������ɡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_26,7) && !who->get_legend(TASK_26,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����㻹�ǲ��а���\n    ���Ѿ��������ˣ���Ҳ�Ͽ�ȥɱ����Щ��ʬ���߹�ɣ���Ҫ�����ˮ������û������İ������С�\n"ESC"�뿪", me->get_name()));
	       	else if ( who->get_legend(TASK_26,8) && !who->get_legend(TASK_26,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻ�??????��ɻ����ˣ��㿴����ˮ�Ѿ��ָ���ԭ���������ˣ��������ǵİ�����Ҳ�����ֿ���������һ��ʹ�������ӵĺ�ˮ�ˡ��Ǳ��Ǻ������͸����������Ѿ����������ˡ������ȥ�ɡ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if ( who->get_legend(TASK_26,5) && !who->get_legend(TASK_26,6) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_26,6);
			who->add_exp(37000);
			who->add_potential(550);
			who->add_cash(38000);
			send_user(who,"%c%s",';',"ָ������ ���� 37000 Ǳ�� 550 ��Ǯ 38000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,29,"" );
			me->do_welcome(1);
        	}
        	break;     
	case 3:
        	if( who->get_legend(TASK_26,6) && !who->get_legend(TASK_26,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_26,7);
        		who->delete_save_2("lfsjiangsi");
        		who->delete_save_2("lfsyigui");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,30,"���Ŀ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ŀ���");
        	}
        	break;
	case 4:
        	if ( who->get_legend(TASK_26,8) && !who->get_legend(TASK_26,9) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->task_finish(who);
        		TASK_LEGEND_D->give_item(who,"item/product/61015",1);
        		who->set_legend(TASK_26,9);
        		who->delete_save_2("lfsjiangsi");
        		who->delete_save_2("lfsyigui");
			who->add_exp(38000);
			who->add_potential(550);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"���Ŀ��� ���� 38000 Ǳ�� 550 ��Ǯ 37000 �ſ���ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,30,"" );
        	}
        	break;   
        }
}  