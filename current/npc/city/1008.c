
// �Զ����ɣ�/make/npc/make8008

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define WARDER_D        "/inh/city/warder"

inherit OFFICER;

void do_faling();
void accept_task();

// ��������ȡ��������
int get_char_picid() { return 5102; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("���������");
        set_city_name("���");

        set_2( "talk", ([
                "faling"        : (: do_faling :),
                 "accept_task"	: (: accept_task :),
                "welcome"	: (: do_welcome :),
        ]) );
//	set("level",75);
//	set("legend",({32*24+26}));
 	set("mpLegend",([75:({32*24+26,}),]));
 	set("mpLegend2",([75:({32*24+28,}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( (who->get_level() >= 75 && !who->get_legend(TASK_24,26) ) || ( who->get_legend(TASK_24,26) && !who->get_legend(TASK_24,28)) )
	{
		tmp += sprintf(ESC HIY "���µķ���\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		WARDER_D->do_look( who, this_object() ); 
	
}
void do_faling() { WARDER_D->do_faling( this_player(), this_object() ); }

void accept_task() { WARDER_D->accept_task( this_player(), this_object() );}

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
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_24,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������淢����һ�����µ����ߣ����������������е��˶���Ⱦ�����ߣ���Ȼ���Ѿ��Ѽ������������ˣ������ҵ������߻��ǻ���һ�촫Ⱦ�������������������ⳡ���ߵ�������ȶ����߹�ֻҪ����Щ�߹�ɱ��������Ϳ������ⳡ����ƽ����������ȥ��ȶ�ȥ����Щ���ߵ�Դͷ������ɣ���Щ�߹�һȺһ����20����������ȫ������������������һᰴ����Ĺ��͸��㱨��ġ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_24,26) && !who->get_legend(TASK_24,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڼ�����������߻��ǵò������ƣ������������Ⱥ�߹��������߻���������ȥ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_24,27) && !who->get_legend(TASK_24,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڼ�������������Ѿ��õ������ˣ�����������Ϊ���Ѿ�����ȶ����߹�����˰ɡ���ε��������ǹ�������ߣ���������ı��꣬�������°ɣ��Ҵ���������¸�л�㡣\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break; 
        case 2:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_24,26) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,26);
        		who->delete_save_2("qgdygyigui");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,19,"���µķ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���µķ���");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_24,27) && !who->get_legend(TASK_24,28) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64135",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_24,28);
        		who->delete_save_2("qgdygyigui");
			who->add_exp(37000);
			who->add_potential(528);
			who->add_cash(35000);
			send_user(who,"%c%s",';',"���µķ��� ���� 37000 Ǳ�� 528 ��Ǯ 35000 ��¶Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,19,"" );
        	}
        	break;   

        case 99:
        	WARDER_D->do_look( who, me ); 
        	break;
        }
}