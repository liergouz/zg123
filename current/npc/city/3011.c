
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0600; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�Թ�����");
        set_city_name("�Թ�");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",55);
//        set("legend",({32*16+3}));
	set("mpLegend",([55:({32*16+3}),80:({32*28+1})]));
	set("mpLegend2",([55:({32*16+5}),80:({32*28+3})]));
        setup();
}

string get_master() { return CITY_ZHAO->get_master(); }
string get_master_2() { return CITY_ZHAO->get_master_2(); }
string get_master_3() { return CITY_ZHAO->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( (who->get_level() >= 55 && !who->get_legend(TASK_16,3)) || (who->get_legend(TASK_16,3)&&!who->get_legend(TASK_16,5)) )
	{
		tmp = sprintf(ESC HIY "��·��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >= 80 && !who->get_legend(TASK_28,1)) || (who->get_legend(TASK_28,1) && !who->get_legend(TASK_28,3)))
	{
		tmp += sprintf(ESC HIY "���\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_3( who, me ); 
	
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
        	if ( who->get_level() >=55 && !who->get_legend(TASK_16,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Գ��Ǳ����ҹ���������ıؾ�֮����������ȴ�������������⣬�����˹�·�ѣ�����һȺ��Ǯ�ۿ�����·����\n    �����������ܱ����������ؾ�֮����դ����ס��Ѱ������Ҫ��Ӵ�·���������������·Ǯ������Ŀ����������ϣ��%s���������壬Ϊ���ճ�����������Ⱥ��·����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(), NPC_RANK_D->get_respect_2(who),getoid(me)));
		else if ( who->get_legend(TASK_16,3) && !who->get_legend(TASK_16,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������£�����յĳ��оͱ�ü�Ϊ�������ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,4) && !who->get_legend(TASK_16,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������վ����ܵ��ͷ��ġ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=55 && !who->get_legend(TASK_16,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,3);
        		who->delete_save_2("zgjianbing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,7,"��·��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��·��");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_16,4) && !who->get_legend(TASK_16,5) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_16,5);
        		who->delete_save_2("zgjianbing");
			who->add_exp(6500);
			who->add_potential(260);
			who->add_cash(5600);
			send_user(who,"%c%s",';',"��·�� ���� 6500 Ǳ�� 260 ��Ǯ 5600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,7,"" );
        	}
        	break;  
        case 4:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_28,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������һ�������ĵ�̴�ʦ������̳����Ķ���Ω��ΩФ���������Ҷ���Ϊ��Ʒ���������Ӧ�Ұ�����һ����լ�ʼܣ���Ҫ8��ľ���3����ʯ������˵��ʯ��������ľ������ʬľ��������ȡԹ��֮�������Զ��������������ֶ������˿���Ѱ�����ף���֪׳ʿ���п�ȥ��һ����\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_28,1) && !who->get_legend(TASK_28,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ��������ȥ���˿ӣ�����ϣ������������Ҫ��ľ������ʯ��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_28,2) && !who->get_legend(TASK_28,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ȵ���լ�ʼ����ɰ��ŵ����죬��һ������ǰ���ιۡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 5:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_28,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,1);
        		who->delete_save("zgswmuban");
        		who->delete_save("zgswyushi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,45,"���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_28,2) && !who->get_legend(TASK_28,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ľ��",8) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"��ʯ",3) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/62073",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,3);
        		who->delete_save("zgswmuban");
        		who->delete_save("zgswyushi");
			who->add_exp(48600);
			who->add_potential(688);
			who->add_cash(46800);
			send_user(who,"%c%s",';',"��� ���� 48600 Ǳ�� 688 ��Ǯ 46800 ������ȸͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,45,"" );
        	}
        	break; 
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}