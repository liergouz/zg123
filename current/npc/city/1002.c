
// �Զ����ɣ�/make/npc/make8002

#include <npc.h>
#include <city.h>
#include <task.h>
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
        set_name("����󽫾�");
	set_real_name("���");
        set_city_name("���");

        set_2( "talk", ([
                "patrol"        : (: do_patrol :),
                "soldier"       : (: do_soldier :),
                "armor"         : (: do_armor :),
                "welcome"	: (: do_welcome :),
                "defence"	: (: do_defence :),
        ]) );
//	set("level",74);
//	set("legend",({32*24+4})); 
	set("mpLegend",([70:({32*24+4,}),75:({32*24+20,}),100:({32*36+11}),]));
	set("mpLegend2",([0:({32*9+30,32*29+27,32*30+7,}),70:({32*24+6,}),75:({32*24+22,}),100:({32*36+13,32*36+28,}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_defence(string arg) { "/sys/party/defence"->do_defence(this_player(), this_object(), arg); }

void do_look( object who )
{
	int id;
	string tmp="";
	object me = this_object();
	
	id = getoid(me);
	if ( who->get_legend(TASK_09,28) && !who->get_legend(TASK_09,30) )
	{
		tmp = sprintf(ESC HIY "��թ���췣\ntalk %x# welcome.1\n",id);
	}
	if ( (who->get_level() >= 70 && !who->get_legend(TASK_24,4)) || (who->get_legend(TASK_24,4) && !who->get_legend(TASK_24,6)) )
	{
		tmp += sprintf(ESC HIY "������\ntalk %x# welcome.3\n",id);
	}
	if ( (who->get_level() >= 75 && !who->get_legend(TASK_24,20)) || (who->get_legend(TASK_24,20) && !who->get_legend(TASK_24,22)) )
	{
		tmp += sprintf(ESC HIY "������ԩ��\ntalk %x# welcome.6\n",id);
	}
	if ( who->get_legend(TASK_29,26) && !who->get_legend(TASK_29,27) )
	{
		tmp += sprintf(ESC HIY "̽�ý���\ntalk %x# welcome.9\n",id);
	}
	if ( who->get_legend(TASK_29,27) && !who->get_legend(TASK_30,1) )
	{
		tmp += sprintf(ESC HIY "�����ź�\ntalk %x# welcome.9\n",id);
	}
	if ( who->get_legend(TASK_30,6) && !who->get_legend(TASK_30,7) )
	{
		tmp += sprintf(ESC HIY "ʧ������\ntalk %x# welcome.9\n",id);
	}
	if ( (who->get_level() >= 100 && !who->get_legend(TASK_36,11)) || (who->get_legend(TASK_36,11) && !who->get_legend(TASK_36,13)) )
	{
		tmp += sprintf(ESC HIY "��Σ����\ntalk %x# welcome.13\n",id);
	}
	if ( who->get_legend(TASK_36,26) && !who->get_legend(TASK_36,28) )
	{
		tmp += sprintf(ESC HIY "���������\ntalk %x# welcome.16\n",id);
	}
	if ("/sys/sys/count"->get_war_flag1()||"/sys/party/defence"->get_state())
		tmp += sprintf(ESC HIY "�ʳǱ���ս\ntalk %x# defence.1\n",id);
	
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),id) +
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
        int flag,i,size,p,amount;
        string tmp;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_09,28) && !who->get_legend(TASK_09,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ʊ������ж񱨣����ǲ�����ʱ��δ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_09,29) && !who->get_legend(TASK_09,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������ڵõ���Ӧ�еĳͷ���\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_legend(TASK_09,29) && !who->get_legend(TASK_09,30) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64029",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_09,30);
			who->add_exp(3500);
			who->add_potential(112);
			who->add_cash(3000);
			send_user(who,"%c%s",';',"��թ���췣 ���� 3500 Ǳ�� 112 ��Ǯ 3000 ������װͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,5,"" );
        	}
        	break;   
        case 3:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_24,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰһ�����Ҿ��ľ����ⱻһȺ�����������ƻ�����Ȼ��ʳû����ʧ��������������װʳ��Ĺ���ȫ������Ⱥ�����������ˣ���Ȼ��Щʳ��ޱ�������ȥ֮��Ͳ�����������װ��ʳ�ˣ��������Ǳ���Ҫ����Ⱥ������ʩ�Գͽ䣬�������Ժ󲻸����ҵľ�Ӫ���ҡ���ȥ��������10ֻ���������������ڶ��Ѿ��ӵ���ȶ���һ���ˣ��³�֮���һ�úõ��ʹ���ģ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_24,4) && !who->get_legend(TASK_24,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҽ�����ȥ����°����û�У��������������С���鶼�첻�õĻ���Ҳ���������������������ͷ���ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_24,5) && !who->get_legend(TASK_24,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ⱥ�����������Ժ�Ҳ�������ҵľ�Ӫ�����ˣ������ҳ�ŵ������Ľ�������������������еģ��úðɣ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 4:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_24,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,4);
        		who->delete_save_2("qgdjjguanzy");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,14,"������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������");
        	}
        	break; 
        case 5:
        	if ( who->get_legend(TASK_24,5) && !who->get_legend(TASK_24,6) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/65077",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_24,6);
        		who->delete_save_2("qgdjjguanzy");
			who->add_exp(28000);
			who->add_potential(490);
			who->add_cash(29000);
			send_user(who,"%c%s",';',"������ ���� 28000 Ǳ�� 490 ��Ǯ 29000 �Ļ�����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,14,"" );
        	}
        	break;  
        case 6:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_24,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������˵����������ｨ�����澭���ֹ��������������˸����������ݣ��޾���ɡ��Ҿ������������Ļ�����в�����������Ѿ���̽�Ӳ鵽���������ֵĹ������ȶ�������Щԩ�꣬��ȥ��ȶ�����ȥɱ��20��ԩ�꣬�������Ժ󶼲������������ｨ�����֣�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_24,20) && !who->get_legend(TASK_24,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ͽ�ȥ�ɣ���ɱ����Щԩ��Ļ�������ÿ�����϶����ð�����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_24,21) && !who->get_legend(TASK_24,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ã����¾��Ѿ���ɱ����Ѽ�������ˣ��ҿ���Щԩ���Ժ���ԶҲ����̤�������ｨ���벽��\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 7:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_24,20) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,20);
        		who->delete_save_2("qgdjjyuanhun");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,17,"������ԩ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ԩ��");
        	}
        	break; 
        case 8:
        	if ( who->get_legend(TASK_24,21) && !who->get_legend(TASK_24,22) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64134",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_24,22);
        		who->delete_save_2("qgdjjyuanhun");
			who->add_exp(35000);
			who->add_potential(510);
			who->add_cash(33000);
			send_user(who,"%c%s",';',"������ԩ�� ���� 35000 Ǳ�� 510 ��Ǯ 33000 ����Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,17,"" );
        	}
        	break;  
        case 9:
        	if ( who->get_legend(TASK_29,26) && !who->get_legend(TASK_29,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����һ���Ѿ�����\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_29,27) && !who->get_legend(TASK_30,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ǰ�����������̿ͣ���þ�Ӫ���ɹ���������������������һ���ױ��⣬��Ȼ�����ҵĵ�����������������͵ȥ�ˣ�����ֻץס��һ���̿ͣ���������Ȼ�������У�������Ҳû���ˣ�ֻ������ʷ���������ˣ��㽫���ױ��ź�������ʷ���ˣ������Ƿ��кð취��\n"ESC"��������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,6) && !who->get_legend(TASK_30,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ҿ��Է����ˡ�\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 10:
        	if ( who->get_legend(TASK_29,26) && !who->get_legend(TASK_29,27) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_29,27);
			who->add_exp(56000);
			who->add_potential(750);
			who->add_cash(53000);
			send_user(who,"%c%s",';',"̽�ý��� ���� 56000 Ǳ�� 750 ��Ǯ 53000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,30,"" );
			me->do_welcome(9);
        	}
        	break; 
        case 11:
        	if ( who->get_legend(TASK_29,27) && !who->get_legend(TASK_30,1) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/98/0143",1);
        		who->set_legend(TASK_30,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,31,"�����ź�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ź�");
        	}
        	break;
        case 12:
        	if ( who->get_legend(TASK_30,6) && !who->get_legend(TASK_30,7) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����������",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/final/33/1770",5);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,7);
			who->add_exp(63000);
			who->add_potential(800);
			who->add_cash(52000);
			send_user(who,"%c%s",';',"ʧ������ ���� 63000 Ǳ�� 800 ��Ǯ 52000 ���ع� 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,34,"" );
        	}
        	break;
        case 13:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_36,11)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ҫ���ģѡ��һ�������롢����ı������������������������Ϊ���������ƾ��ã�����������˼���������Ŀ����һ�����Ⱦ�Ҫ�����ܹ���Σ���壬���������������ս����Ϊ���ٵ�һԱ�������ȥ����������8ֻ�����ɣ�11ֻ�����˰ɣ�\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_36,11) && !who->get_legend(TASK_36,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ʵ�ڱ�Ǹ���������Ǿ��Ӳ���Ҫ�㡣\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_36,12) && !who->get_legend(TASK_36,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ģ������ˣ���һ�ֺ�ѡͨ������ؼҵȺ���һ��֪ͨ�ɣ�\n"ESC"�������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 14:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_36,11)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_36,11);
        		who->delete_save("qgdjjguanzx");
        		who->delete_save("qgdjjguixr");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,53,"��Σ����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Σ����");
        	}
        	break;
	case 15:
        	if ( who->get_legend(TASK_36,12) && !who->get_legend(TASK_36,13) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_36,13);
        		who->delete_save("qgdjjguanzx");
        		who->delete_save("qgdjjguixr");
			who->add_exp(80000);
			who->add_potential(955);
			who->add_cash(68000);
			send_user(who,"%c%s",';',"��Σ���� ���� 80000 Ǳ�� 955 ��Ǯ 68000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,53,"" );
        	}
        	break; 
        case 16:
        	if ( who->get_legend(TASK_36,26) && !who->get_legend(TASK_36,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ʿ�������Ҿ�������������֪��ʿ���Ҳ��ǰ���������ģ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_36,27) && !who->get_legend(TASK_36,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������ô����ʿ�������Ҿ��γ�Ʒ��أ�\n"ESC"�������\ntalk %x# welcome.17\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 17:
        	if ( who->get_legend(TASK_36,27) && !who->get_legend(TASK_36,28) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",10) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"�쵶",10) != 1 )
        		{
        			TASK_LEGEND_D->give_item(who,"item/98/0171",10); 
        			return;
        		}
        		TASK_LEGEND_D->give_item(who,"item/final/16/1633",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_36,28);
        		who->delete_save("qwlijian");
        		who->delete_save("qwkuaidao");
			who->add_exp(84000);
			who->add_potential(1048);
			who->add_cash(73000);
			send_user(who,"%c%s",';',"��������� ���� 84000 Ǳ�� 1048 ��Ǯ 73000 ���������� 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,58,"" );
        	}
        	break; 
 	case 99:
 		GENERAL_D->do_look( who, me); 
 		break;
        }
}