
// �Զ����ɣ�/make/npc/make8006

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define INQUISITOR_D    "/inh/city/inquisitor"

inherit OFFICER;

void do_elect( string arg );
void do_vote( string arg );
void do_score( string arg );

// ��������ȡ��������
int get_char_picid() { return 5102; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("κ����ʷ");
	set_real_name("κ��");
        set_city_name("κ��");

        set_2( "talk", ([
                "elect"         : (: do_elect :),
                "vote"          : (: do_vote :),
                "score"         : (: do_score :),
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",100);
//        set("legend",({32*35+15}));
 	set("mpLegend",([100:({32*35+15}),]));
 	set("mpLegend2",([0:({32*35+14,32*35+24}),]));
        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( who->get_legend(TASK_35,13) && !who->get_legend(TASK_35,14) )
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_level() >= 100 && !who->get_legend(TASK_35,15) )
		tmp += sprintf(ESC HIY "̽��ԭ��\ntalk %x# welcome.3\n",getoid(me));
	if ( who->get_legend(TASK_35,23) && !who->get_legend(TASK_35,24) )
		tmp += sprintf(ESC HIY "ͨ�����\ntalk %x# welcome.3\n",getoid(me));
	if ( who->get_legend(TASK_35,24) && !who->get_legend(TASK_35,25) )
		tmp += sprintf(ESC HIY "����κ��\ntalk %x# welcome.3\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		INQUISITOR_D->do_look( who, this_object() ); 
	
}
void do_elect( string arg ) { INQUISITOR_D->do_elect( this_player(), this_object(), arg ); }
void do_vote( string arg ) { INQUISITOR_D->do_vote( this_player(), this_object(), arg ); }
void do_score( string arg ) { INQUISITOR_D->do_score( this_player(), this_object(), arg ); }

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
        	if ( who->get_legend(TASK_35,13) && !who->get_legend(TASK_35,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǣ��Ҿ�֪������µ�����\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;

        case 2:
        	if ( who->get_legend(TASK_35,13) && !who->get_legend(TASK_35,14) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/final/91/1813",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_35,14);
			who->add_exp(78000);
			who->add_potential(1100);
			who->add_cash(68000);
			send_user(who,"%c%s",';',"������� ���� 78000 Ǳ�� 1100 ��Ǯ 68000 ���� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,56,"" );
        	}
        	break;
        case 3:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_35,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���κ�Ϻ������౨��˵�����ٺ����ֳ�����ͬ�ϴ����Ƶ��¼�������Ԫ����������ô���ֳ����ˣ�Ī�ǻ���ͬ������ȥ��κ�Ϻ���ϸѯ��һ�����龭����\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_35,23) && !who->get_legend(TASK_35,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �յ������ٱض�����ϸ��ѡһ�������Ĺ�Ա�����ٺӡ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_35,24) && !who->get_legend(TASK_35,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ҹո��ֵõ�κ�Ϻ�����ת�����Ϣ��ԭ����ǰʯ����һ�����������Ǭ����ʯ�������������ҵ���һ������Ǭ���������⣬�����и���˵���˴���װ�ݴ�������Ʒ�����Һ��޸��أ��˵ȱ�����һٹ�����о�����ʹ�÷����͸�������ȥ������ȥͨ��һ������������һ�¡�\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 4:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_35,15) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_35,15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,57,"̽��ԭ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"̽��ԭ��");
        	}
        	break; 
        case 5:
        	if ( who->get_legend(TASK_35,23) && !who->get_legend(TASK_35,24) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_35,24);
			who->add_exp(80000);
			who->add_potential(1150);
			who->add_cash(70000);
			send_user(who,"%c%s",';',"ͨ����� ���� 80000 Ǳ�� 1150 ��Ǯ 70000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,60,"" );
			me->do_welcome(3);
        	}
        	break;
	case 6:
        	if ( who->get_legend(TASK_35,24) && !who->get_legend(TASK_35,25) ) 
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_35,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,61,"����κ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����κ��");
        	}
        	break;
        case 99:	
		INQUISITOR_D->do_look( who, me); 
        	break;
        }
}      