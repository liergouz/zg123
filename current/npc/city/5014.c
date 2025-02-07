
// �Զ����ɣ�/make/npc/make8014

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_enter();
void do_record();

// ��������ȡ��������
int get_char_picid() { return 0651; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�ع�����");
        set_city_name("�ع�");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("out", 11);
        set("in", 13);
	set("mpLegend",([80:({32*38+13})]));
	set("mpLegend2",([100:({32*38+26}),110:({32*38+30}),]));
        setup();
}

string get_master() { return CITY_QIN->get_master(); }
string get_master_2() { return CITY_QIN->get_master_2(); }
string get_master_3() { return CITY_QIN->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();

	if ( who->get_level() >= 80 && !who->get_legend(TASK_38,13) )
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_level() >= 100 && who->get_legend(TASK_38,25) && !who->get_legend(TASK_38,26) )
		tmp += sprintf(ESC HIY "��ս\ntalk %x# welcome.3\n",getoid(me));
	if ( who->get_level() >= 110 && who->get_legend(TASK_38,29) && !who->get_legend(TASK_38,30) )
		tmp += sprintf(ESC HIY "�ھ��˲�\ntalk %x# welcome.5\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look( who, me ); 
	
}
void do_enter() { GUARDER_D->do_enter( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }

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
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_38,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ǹ��¶���\n    ���Ҽ��µ��������Ҿ�û�����ҵĵ�������ҳ����ˣ����ر����ҵ��Լ���������ĸ�������ҵ�Ŭ����෽��������������֪�������ܹ�����˼��п���֪���ҵ����������Լ��ǳ���ȥ�ʸ�����������⵱�Ҳ����˵�߾����ߵġ����Ի����������������ܹܣ�������ǳ��ż���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_38,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_38,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,50,"����֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����֮��");
        	}
        	break;
	case 3:
		if ( who->get_level() >= 100 && who->get_legend(TASK_38,25) && !who->get_legend(TASK_38,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ҿ���������ս��������ˣ�û�뵽����������һ�����ã������ս���ҽ����ˣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 4:
		if ( who->get_level() >= 100 && who->get_legend(TASK_38,25) && !who->get_legend(TASK_38,26) )
		{
        		if (TASK_LEGEND_D->check_task_item(who,"�����������ս��",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_38,26);
			who->add_exp(42000);
			who->add_potential(600);
			who->add_cash(40000);
			send_user(who,"%c%s",';',"��ս ���� 42000 Ǳ�� 600 ��Ǯ 40000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,77,"" );
        	} 
        	break; 
	case 5:
		if ( who->get_level() >= 110 && who->get_legend(TASK_38,29) && !who->get_legend(TASK_38,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ǲ���ȥ�ģ��������ع����ˣ���Ҳ���ع��Ĺ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 6:
		if ( who->get_level() >= 110 && who->get_legend(TASK_38,29) && !who->get_legend(TASK_38,30) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_38,30);
			who->add_exp(48000);
			who->add_potential(610);
			who->add_cash(45000);
			send_user(who,"%c%s",';',"�ھ��˲� ���� 48000 Ǳ�� 610 ��Ǯ 45000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,66,"" );
        	} 
        	break; 
        case 99:
        	GUARDER_D->do_look( who, me ); 
        	break;     
        }
}