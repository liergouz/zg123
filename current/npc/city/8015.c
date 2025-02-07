
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
int get_char_picid() { return 9390; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�ܹ�����");
        set_city_name("�ܹ�");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("in", 13);
        set("out", 11);
 	set("mpLegend2",([0:({32*20+14}),]));
        setup();
}

string get_master() { return CITY_ZHOU->get_master(); }
string get_master_2() { return CITY_ZHOU->get_master_2(); }
string get_master_3() { return CITY_ZHOU->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( who->get_legend(TASK_20,13)&&!who->get_legend(TASK_20,15) )
	{
		tmp = sprintf(ESC HIY "�ջ���\ntalk %x# welcome.1\n",getoid(me));
	}

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
		if ( who->get_legend(TASK_20,13)&&!who->get_legend(TASK_20,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ع�������Ī�������İɣ����ϴξ͸��Ҵ���к��ˣ�������Щ����ȥ�ɣ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_20,14)&&!who->get_legend(TASK_20,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ĸ�׶��ھ��¾������죬���³����ľջ���һ������֦Ҷ��������׼����Ƶ���ʳ�У�Ȼ��һ��������ƣ������ڶ�����¾������á��ž�������������ʢ����ó��þơ���˵�������־ƣ������������١�\n"ESC"�뿪", me->get_name()));
        	break;
        case 2:
        	if ( who->get_legend(TASK_20,13)&&!who->get_legend(TASK_20,14) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0092");
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!',"��Я������Ʒ̫����");	
        			return;
        		}
        		item->add_to_user(p);
			who->set_legend(TASK_20,14);
			who->add_exp(7000);
			who->add_potential(260);
			who->add_cash(7500);
			send_user(who,"%c%s",';',"�����ڣ�2�� ���� 7000 Ǳ�� 260 ��Ǯ 7500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,51,"" );
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,52,"�����ڣ�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ڣ�3��");
        	}
        	break;   
        case 99:
        	GUARDER_D->do_look( who, me ); 
        	break;     
        }
}