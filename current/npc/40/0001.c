#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 7302; }

// ���������촦��
void create()
{
        set_name("Ѱ��");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*23+29,32*24+3,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_23,28)&&!who->get_legend(TASK_23,29) ) 
		tmp += sprintf(ESC HIY "�ɷ����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_23,29)&&!who->get_legend(TASK_24,1)) || (who->get_legend(TASK_24,1)&&!who->get_legend(TASK_24,3)) ) 
		tmp += sprintf(ESC HIY "������˼��\ntalk %x# welcome.1\n",getoid(this_object())); 
		
        send_user( who, "%c%s", ':', sprintf( "%s��\n    �����������»�֮ҹ��ץ�ߵģ�����10�꣬����û���ټ�һ�棬��֪������һֱ�ڵ�������ֱ����������\n", get_name())
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
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
       		if (who->get_legend(TASK_23,28)&&!who->get_legend(TASK_23,29))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    10���ˣ�������������Ϣ�ˣ���ǰ��Ȼһֱû�����κ���Ϣ������������������һ����ٹ��������ž۵ġ���Щ������Ѷ�Ƕ���Ƶ�����Ͷ��·���Ҷ��Ѿ���Ѱ�������ˣ��Һ��������ҳ����������������ҿ��԰����������壬һ��Ҫ�ȵ��ҵ��๫������һ�졣\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_23,29)&&!who->get_legend(TASK_24,1))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Щ���������Ӻ����ر�����˵����˼���ȣ��ټ�����Ѷ�ĸ�����ƺ��������ɼ���Ҫ��������ȥ�Ļ������Ȳ������๫�������ҵ������Ҫ����ȥ�����и��ҿ��˸�ҩ��������˵Ҫ��������ҵ�����������ݡ�����������ζ��ҩ�ſ��԰��ҵĲ��κã���������������ڵ����������ˣ��Ҹ���û�취ȥ����������ζ��ҩ��������ٰ������æ��\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_24,1)&&!who->get_legend(TASK_24,2))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����һ����Σ�յĵط����ռ���ҩ��ʱ����һ��ҪС�İ���Ϊ�����๫����һ��Ҫ�úû���ȥ��\n"ESC"�뿪", me->get_name()));
		else if (who->get_legend(TASK_24,2)&&!who->get_legend(TASK_24,3))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Щ��ҩ���ҾͿ��԰��ҵ��������ã�Ȼ������������ҵ��๫�½������ˡ���������Ƿ򸾵Ĵ���ˣ���Ҳ��֪������ô������ã��������ҵ�һ��С���⣬ϣ������㻹�е��á�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 2:
        	if ( who->get_legend(TASK_23,28) && !who->get_legend(TASK_23,29) )
        	{
			if ( TASK_LEGEND_D->check_task_item(who,"��Ѱ���ļ���",1) != 1 )
				return ;
			TASK_LEGEND_D->task_finish(who);
			TASK_LEGEND_D->give_item(who,"item/product/64128",1);
			who->set_legend(TASK_23,29);
			who->add_exp(20000);
			who->add_potential(290);
			who->add_cash(20000);
			send_user(who,"%c%s",';',"��ʿ�İ��飨3�� ���� 20000 Ǳ�� 290 ��Ǯ 20000 �����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,40,"" );
       		}
        	break;
	case 3:
        	if ( who->get_legend(TASK_23,29)&&!who->get_legend(TASK_24,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,1);
        		who->delete_save_2("xercuanxinlian");
        		who->delete_save_2("xerdongcongcao");
        		who->delete_save_2("xerjinyinhua");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,29,"��ʿ�İ��飨4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ʿ�İ��飨4��");
        	}
        	break;  
        case 4:
        	if (who->get_legend(TASK_24,2)&&!who->get_legend(TASK_24,3))
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),70,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"������",5) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"�����",5) != 1 )
        		{
        			item = new("item/98/0110");
        			item->set_amount(5);
        			p = item->move(who,-1);
        			item->add_to_user(p);
        			return;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"������",8) != 1 )
        		{
        			item = new("item/98/0110");
        			item->set_amount(5);
        			p = item->move(who,-1);
        			item->add_to_user(p);
        			item = new("item/98/0111");
        			item->set_amount(5);
        			p = item->move(who,-1);
        			item->add_to_user(p);        			
        			return;        			
        		}
			TASK_LEGEND_D->task_finish(who);
			TASK_LEGEND_D->give_item(who,tmp,1);
			who->set_legend(TASK_24,3);
        		who->delete_save_2("xercuanxinlian");
        		who->delete_save_2("xerdongcongcao");
        		who->delete_save_2("xerjinyinhua");
			who->add_exp(56000);
			who->add_potential(830);
			who->add_cash(57000);
			send_user(who,"%c%s",';',sprintf("��ʿ�İ��飨4�� ���� 56000 Ǳ�� 830 ��Ǯ 57000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,29,"" );
        	}
        	break;
        }
}