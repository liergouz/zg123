
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 7302; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("����");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",42);
//        set("legend",({32*11+6}));    
	set("mpLegend2",([0:({32*11+5,32*11+8,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_11,4)&&!who->get_legend(TASK_11,5) ) 
		tmp += sprintf(ESC HIY "��ǿ������\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_11,5) && !who->get_legend(TASK_11,6)) || (who->get_legend(TASK_11,6)&&!who->get_legend(TASK_11,8)) ) 
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_11,8) && !who->get_legend(TASK_11,9)) || (who->get_legend(TASK_11,9)&&!who->get_legend(TASK_11,10)) ) 
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    ����Ժ�������е������ʴӡ���\n", get_name())
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
        	if ( who->get_legend(TASK_11,4)&&!who->get_legend(TASK_11,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Ư������ػ��˺ܶ๦����ҵ��ģ����ǿ�������������డ���������һ��ÿ�����һ�¡�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,5) && !who->get_legend(TASK_11,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �׻�˵��������ۣ�����Ⱥ�֡���Ȼ��ǿ�����������������϶�Ҳ����ֵ�����ε��ˣ�������ȥ֣�������30�����ۣ��Ҿ��������������Ҳ���ų�ǿ���۹⡣\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,6) && !who->get_legend(TASK_11,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ɱ�����ʧ������Ȼ�ҶԳ�ǿҲ��ʧȥ���ĵġ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_11,7) && !who->get_legend(TASK_11,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ����!���ǿû�п����ˣ�Ҳ˵�������۹��൱��ˮ׼��\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,8) && !who->get_legend(TASK_11,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ŭ�����Կ���������һ���������θе��ˣ������ų�ǿҲ������һ������һ���ܼ縺���ͥ���ε����ˣ��������������ĸ�㣬���㽫��������ǿ��\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,9) && !who->get_legend(TASK_11,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ž��˻ỵ���ģ����ǸϽ���ȥ�ɣ�\n"ESC"�뿪", me->get_name()));
        	break;
       case 2:
        	if ( who->get_legend(TASK_11,4) && !who->get_legend(TASK_11,5) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,5);
			who->add_exp(4200);
			who->add_potential(130);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"�����ع���2�� ���� 4200 Ǳ�� 130 ��Ǯ 3500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,4,"" );
			me->do_welcome(1);
        	}
        	break;        
        case 3:
        	if( who->get_legend(TASK_11,5) && !who->get_legend(TASK_11,6) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,6);
        		who->delete_save_2("bbkuyi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,5,"�����ع���3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ع���3��");
        	}
        	break;
        case 4:
 		if ( who->get_legend(TASK_11,7) && !who->get_legend(TASK_11,8) )
 		{
 			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/final/15/1507",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,8);
        		who->delete_save_2("bbkuyi");
			who->add_exp(5500);
			who->add_potential(180);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"�����ع���3�� ���� 5500 Ǳ�� 180 ��Ǯ 4000 �м��﹥ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,5,"" );
			me->do_welcome(1);
        	}
        	break;
        case 5:
        	if( who->get_legend(TASK_11,8) && !who->get_legend(TASK_11,9) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			item = new("item/98/0044");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				send_user( who, "%c%s", '!', "�����ϵĶ���̫����");
				return;
			}
			item->add_to_user(p);
        		who->set_legend(TASK_11,9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,6,"�����ع���4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ع���4��");
        	}
        	break;
        }
}