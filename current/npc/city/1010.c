
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5209; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�������");
        set_city_name("���");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",37);
//        set("legend",({32*9+28}));
 	set("mpLegend",([35:({32*9+28}),70:({32*38+11}),75:({32*25+1,})]));
 	set("mpLegend2",([75:({32*25+3,}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( who->get_level() >= 35 && !who->get_legend(TASK_09,28) )
	{
		tmp = sprintf(ESC HIY "��թ���췣\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >= 75 && !who->get_legend(TASK_25,1)) || (who->get_legend(TASK_25,1) && !who->get_legend(TASK_25,3)))
	{
		tmp += sprintf(ESC HIY "�����ԵĴ��\ntalk %x# welcome.3\n",getoid(me));
	}
	if ( who->get_level() >= 70 && !who->get_legend(TASK_38,11) )
	{
		tmp += sprintf(ESC HIY "��л\ntalk %x# welcome.6\n",getoid(me));
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_09,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��̩ɽһ���ĺ��ܡ��������10��ǰ�û�Ϊ�ˣ�һ��20�������ҹ��Ĵ󽫾�����Ҫ����������������ߴ󣬱�Ӧ���ˣ�����һ��֮������ȫ��Ǳ�ӣ�͵�����ҹ��ı�����������ŭ��һֱ��Ҫ׽�����ǣ���������Ϊ���죬�������׷�鵽���Ƕ���̩ɽһ������թ�ǻ��ܵ��췣�ģ����������Ǻ�ȥ���������Ͱɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_09,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_09,28);
        		who->delete_save_2("swheixiong");
        		who->delete_save_2("swtanglang");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,5,"��թ���췣" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��թ���췣");
        	}
        	break;
        case 3:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_25,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ȶ���һЩ���˹�����Ʈ����������������Ϊ����������������������һֱδ�ܵóѣ�������������ǳɹ�Ʈ�����Ļ������ǳ�����İ��ս��������룬Ϊ�˲������ǳ�����İ����ܵ�Σ��������Դ�������ȥ��ȶ�����Щ���˹���һ�ξ����ԵĴ��������ֻҪһ������������20�����˵Ļ���Ӧ�ÿ��Զ�������ɾ����ԵĴ���ˡ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_25,1) && !who->get_legend(TASK_25,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������޷��뿪���������ĸ�λ�ģ����Ծ�Ҫ�鷳���ˣ���������ʵ�ڲ��У������ȥ�Ҹ����֡�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_25,2) && !who->get_legend(TASK_25,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����úܺ�ѽ����϶���һ�ξ����ԵĴ���ˣ�������Щ���˹��Ժ�û��ʵ��������ǰ����Ƶ������ҪƮ�������ˣ��Ҵ������������ïлл�㡣\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
 
        	break;
	case 4:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_25,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_25,1);
        		who->delete_save_2("qgswwangliang");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,20,"�����ԵĴ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ԵĴ��");
        	}
        	break;
        case 5:
        	if ( who->get_legend(TASK_25,2) && !who->get_legend(TASK_25,3) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64136",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_25,3);
        		who->delete_save_2("qgswwangliang");
			who->add_exp(40000);
			who->add_potential(560);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"�����ԵĴ�� ���� 40000 Ǳ�� 560 ��Ǯ 37000 ����Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,20,"" );
        	}
        	break;
        case 6:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_38,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǹ�˭���ԣ������㣡\n    �ϴκ��������ǽ�������������Ŀ��Űɣ��ҷǳ���л����ô��������Ҫ�����ң��⼸����Ҳ�����˺ܾã������������ǵÿ��Լ��������һ�������Լ����ڵ�״̬������������鷳������һ�ˣ����ߺ������������������ڳ�͢���£����ù���������ˣ��һ�úû���ȥ�ģ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;        		
        case 7:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_38,11) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_38,11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,74,"��л" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��л");
        	}
        	break;	   
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}