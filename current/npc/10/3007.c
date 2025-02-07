
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 0450; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("��С��");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      

 	set("mpLegend",([85:({32*38+15,}),]));
 	set("mpLegend2",([0:({32*31+2,32*31+5,32*31+8,}),85:({32*38+16,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	int id;
	string tmp="";

	id = getoid(this_object());
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_31,1) && !who->get_legend(TASK_31,2) ) 
		tmp += sprintf(ESC HIY "ѯ��С��\ntalk %x# welcome.1\n",id); 
        if ( (who->get_legend(TASK_31,2) && !who->get_legend(TASK_31,3)) || (who->get_legend(TASK_31,3) && !who->get_legend(TASK_31,5)) ) 
		tmp += sprintf(ESC HIY "����ɻ�\ntalk %x# welcome.1\n",id); 
        if ( (who->get_legend(TASK_31,5) && !who->get_legend(TASK_31,6)) || (who->get_legend(TASK_31,6) && !who->get_legend(TASK_31,8)) ) 
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",id); 
        if ( who->get_legend(TASK_31,8) && !who->get_legend(TASK_31,9) ) 
		tmp += sprintf(ESC HIY "��֪������\ntalk %x# welcome.1\n",id); 
        if ( who->get_level() >= 85 && who->get_legend(TASK_38,15) && !who->get_legend(TASK_38,16) ) 
		tmp += sprintf(ESC HIY "�ܵܵ��ʺ�\ntalk %x# welcome.8\n",id); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0201))
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
        	if ( who->get_legend(TASK_31,1) && !who->get_legend(TASK_31,2) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �治֪�������������˵��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,2) && !who->get_legend(TASK_31,3) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ͷһ�����飬������ͻȻ�������ϱ��ӵ����飬���ܵ����ں���������ϱ��������������ǿ����ɱ�ˣ��������ү�ж���Ϊ��������������С�������ڹ������Ͷ̥�ˣ�������ǿ�����ڣ���������Ҳ����ǿ���ˣ�������ٸ�ˣ����Ǿ��ǽ�����Ĺ�Ĺ���ʯٸ��ǹٸ����ȥ���Ҹɵ����ǣ����������ج�Ρ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,3) && !who->get_legend(TASK_31,4) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ��ϱ��ӵ�ծ�����ǻ������ˡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_31,4) && !who->get_legend(TASK_31,5) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ������Ҳ��õ����ˡ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,5) && !who->get_legend(TASK_31,6) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �и����������Ķ�ԣ�ǿ�����ҽ������ѣ���Ȼ��Ҫ�����ҵ�̯�ӣ�������С�����⣬��ǿ��ά�����ƣ����ж��Ǯ����������˵�������������ڽ�����Ĺ�����ϲ��ش������������ɱ���͸�����һ����\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,6) && !who->get_legend(TASK_31,7) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ҵ�׼����ұ����ˡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_31,7) && !who->get_legend(TASK_31,8) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɺ��ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,8) && !who->get_legend(TASK_31,9) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����˵�ƺ�������ͬ�������е�ʲô��ϵ�������ȥ֪��һ�£�����������鷳��\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
 
	    	break;
        case 2:
        	if ( who->get_legend(TASK_31,1) && !who->get_legend(TASK_31,2) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,2);
			who->add_exp(70000);
			who->add_potential(840);
			who->add_cash(56000);
			send_user(who,"%c%s",';',"ѯ��С�� ���� 70000 Ǳ�� 840 ��Ǯ 56000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,45,"" );
			me->do_welcome(1);
        	}
        	break;   
	case 3:
        	if ( who->get_legend(TASK_31,2) && !who->get_legend(TASK_31,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,3);
        		who->delete_save("qxfgongjsy");
        		who->delete_save("qxfqianyong");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,46,"����ɻ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ɻ�");
        	}
        	break;  
        case 4:
        	if ( who->get_legend(TASK_31,4) && !who->get_legend(TASK_31,5) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,5);
        		who->delete_save("qxfgongjsy");
        		who->delete_save("qxfqianyong");
			who->add_exp(69000);
			who->add_potential(830);
			who->add_cash(55000);
			send_user(who,"%c%s",';',"����ɻ� ���� 69000 Ǳ�� 830 ��Ǯ 55000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,46,"" );
			me->do_welcome(1);
        	}
        	break;  
	case 5:
        	if ( who->get_legend(TASK_31,5) && !who->get_legend(TASK_31,6) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,47,"�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������");
        	}
        	break;  
        case 6:
        	if ( who->get_legend(TASK_31,7) && !who->get_legend(TASK_31,8) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,8);
			who->add_exp(70000);
			who->add_potential(820);
			who->add_cash(57000);
			send_user(who,"%c%s",';',"������� ���� 70000 Ǳ�� 820 ��Ǯ 57000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,47,"" );
			me->do_welcome(1);
        	}
        	break;  
	case 7:
        	if ( who->get_legend(TASK_31,8) && !who->get_legend(TASK_31,9) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,48,"��֪������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��֪������");
        	}
        	break;
        case 8:
        	if ( who->get_level() >= 85 && who->get_legend(TASK_38,15) && !who->get_legend(TASK_38,16) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ҳ���ȥ�������������׬��Ǯ��ȥ�����ҵ�������Ϻõ�����ӣ�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 9:
        	if ( who->get_level() >= 85 && who->get_legend(TASK_38,15) && !who->get_legend(TASK_38,16) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_38,16);
			who->add_exp(30000);
			who->add_potential(400);
			who->add_cash(22000);
			send_user(who,"%c%s",';',"�ܵܵ��ʺ� ���� 30000 Ǳ�� 400 ��Ǯ 22000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,65,"" );
        	}
        	break; 
        }
}