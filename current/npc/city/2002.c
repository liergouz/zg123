
// �Զ����ɣ�/make/npc/make8002

#include <npc.h>
#include <city.h>
#include <task.h>
#include <equip.h>
#include <ansi.h>

#define GENERAL_D       "/inh/city/general"

inherit OFFICER;

void do_patrol( string arg );
void do_soldier( string arg );
void do_armor( string arg );
void do_defence( string arg );

// ��������ȡ��������
int get_char_picid() { return 5201; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�����󽫾�");
	set_real_name("����");
        set_city_name("����");

        set_2( "talk", ([
                "patrol"        : (: do_patrol :),
                "soldier"       : (: do_soldier :),
                "armor"         : (: do_armor :),
                "welcome"	: (: do_welcome :),
                "defence"	: (: do_defence :),
        ]) );
//        set("level",20);
//        set("legend",({32*37+19}));
 	set("mpLegend",([15:({32*37+19,}),20:({32*4+29}),70:({32*23+1,}),]));
 	set("mpLegend2",([20:({32*4+30}),70:({32*23+3,}),]));
        setup();
}

string get_master() { return CITY_HAN->get_master(); }
string get_master_2() { return CITY_HAN->get_master_2(); }
string get_master_3() { return CITY_HAN->get_master_3(); }

void do_defence(string arg) { "/sys/party/defence"->do_defence(this_player(), this_object(), arg); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();

	if ( who->get_level() >= 15 && !who->get_legend(TASK_37,19) )
		tmp += sprintf(ESC HIY "�޴���˵����\ntalk %x# welcome.8\n",getoid(me));
	
	if ( (who->get_level() >= 20 && !who->get_legend(TASK_04,29) ) || ( who->get_legend(TASK_04,29) && !who->get_legend(TASK_04,30)) )
	{
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >= 70 && !who->get_legend(TASK_23,1) ) || ( who->get_legend(TASK_23,1) && !who->get_legend(TASK_23,3)) )
	{
		tmp += sprintf(ESC HIY "й��֮��\ntalk %x# welcome.5\n",getoid(me));
	}
	if ("/sys/sys/count"->get_war_flag1()||"/sys/party/defence"->get_count())
		tmp += sprintf(ESC HIY "�ʳǱ���ս\ntalk %x# defence.1\n",getoid(me));
	
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GENERAL_D->do_look( who, this_object() ); 
	
}
void do_patrol( string arg ) { GENERAL_D->do_patrol( this_player(), this_object(), arg ); }
void do_soldier( string arg ) { GENERAL_D->do_soldier( this_player(), this_object(), arg ); }
void do_armor( string arg ) { GENERAL_D->do_armor( this_player(), this_object(), arg ); }
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
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_04,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ϴ�������ɽ�ľ����²������ӣ�ͻ����ɫ���磬��֪����ħ���������������󡣻�æ�����б�������Ȼ��С�İѵ�����Ū���ˡ��������Ǻã�%s�ܰ��Ұ��ǵ�����Ѱ������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
		else if ( who->get_legend(TASK_04,29) && !who->get_legend(TASK_04,30) )
			me->do_welcome(4);
        	break;
        case 2:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_04,29) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->delete_save("diaobingfu");
        		who->set_legend(TASK_04,29);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,15,"����֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����֮��");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_04,29) && !who->get_legend(TASK_04,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/final/33/1703",3);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_04,30);
			who->delete_save("diaobingfu");
			who->delete_save_2("diaobingfu");
			who->add_exp(2200);
			who->add_potential(80);
			who->add_cash(1500);
			send_user(who,"%c%s",';',"����֮�� ���� 2200 Ǳ�� 80 ��Ǯ 1500 ������ 3");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,15,"" );
        	}
        	break;
        case 4:
        	if ( !who->get_legend(TASK_04,29) || who->get_legend(TASK_04,30) )
        		return ;
        	if ( objectp(item=present("������",who,1,MAX_CARRY)) && item->is_legend_item() == 1 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����̫���ˣ�%s������һ����úó�л���㣡\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
		else
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ֻ�����������ȥ��ϣ�������ܹ���ˡ���ҡ�\n"ESC"�뿪", me->get_name()));
        	break;
        case 5:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_23,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Դӳ�ƽ֮ս������֮���Ѿ�û���κ�һ�����Ե������ع��Կ��ˣ��ع�һֱ�������������������д���˵�ع��ĵ�һ��Ŀ��������Ǻ��������������Ǳߺ�����Щ��Ѱ���Ķ���һ����̽�Ѿ��������һ�����ع�����̽�Ѿ��ڿ�ʼ�ռ��ҹ��ľ����鱨�ˣ�Ϊ�˷����ع��������ȵð�������̽��������ȥ���ȥ���Ұ�������̽ɱ���ɣ��³ɺ���һ���������������������͡�\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_23,1) && !who->get_legend(TASK_23,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ϣ��������������̽��õ��ҹ��鱨֮ǰ���������������Ȼ���ǹ��Ҿ�Σ���ˡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_23,2) && !who->get_legend(TASK_23,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ���������̽�����ˣ������д���˵���ǵľ��������Ѿ��͵������ˣ���������Ҫ׼�������ع�һս�ˡ�����εĹ������Ѿ���������ˣ���������ʹ͡�\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 6:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_23,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_23,1);
        		who->delete_save_2("hgdjjmitan");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,44,"й��֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"й��֮��");
        	}
        	break;  
        case 7:
        	if ( who->get_legend(TASK_23,2) && !who->get_legend(TASK_23,3) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_23,3);
        		who->delete_save_2("hgdjjmitan");
			who->add_exp(25000);
			who->add_potential(430);
			who->add_cash(23000);
			send_user(who,"%c%s",';',"й��֮�� ���� 25000 Ǳ�� 430 ��Ǯ 23000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,44,"" );
        	}
        	break;
        case 8:
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_37,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����κ���Ĵ޴������һ�����о���ս���治�ɶ�õ��˲ţ���Ȼ��ʧȥ�˼��䣬����һ���˵�ı���ǲ�����ʧȥ�ģ��������������������Ǿ�Ӫ����ʦү��ֻ�ǲ�֪�����Ƿ��Ӧ�У�����������ȥκ�����������͸��޴���ˣ�һ��Ҫ���ֽ��������ˣ�����û��\n    �޴���˾;�ס��κ���Ĵ������ڡ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 9:
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_37,19) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		TASK_LEGEND_D->give_item(who,"item/98/0178",1);	
        		who->set_legend(TASK_37,19);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,48,"�޴���˵����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�޴���˵����");
        	}
        	break;
        case 99:	
		GENERAL_D->do_look( who, me); 
        	break;
        }
}
