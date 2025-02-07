
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
int get_char_picid() { return 5209; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�������");
        set_city_name("���");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("out", 11);
        set("in", 13);
//        set("level",100);
//        set("legend",({32*38+25}));
 	set("mpLegend",([95:({32*38+25})]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who ) 
{ 
	string tmp="";
	object me = this_object();

	if ( who->get_level() >= 95 && !who->get_legend(TASK_38,25) )
		tmp += sprintf(ESC HIY "��ս\ntalk %x# welcome.1\n",getoid(me));

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
        	if ( who->get_level() >= 95 && !who->get_legend(TASK_38,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ع����������Ǻ��Ʋ������ǣ�����Ϊ��������õ����������յ�һ�������һ���ȵȡ�\n    �������ǲ�ʹ�����汾�£����ǲ�֪�����ǵ���������������������������ع���������ս�飬��һ������֮��ľ�����\n    �鷳�㽫�����ս�齻���ع�������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 95 && !who->get_legend(TASK_38,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/98/0184",1);
        		who->set_legend(TASK_38,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,77,"��ս" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ս");
        	}
        	break;
 
        case 99:
        	GUARDER_D->do_look( who, me ); 
        	break;     
        }
}