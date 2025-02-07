
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
        set_name("�����ʷ");
	set_real_name("����");
        set_city_name("���");

        set_2( "talk", ([
                "elect"         : (: do_elect :),
                "vote"          : (: do_vote :),
                "score"         : (: do_score :),
                "welcome"	: (: do_welcome :),
        ]) );
//	set("level",88);
//	set("legend",({32*30+8,}));
 	set("mpLegend",([85:({32*30+8,32*30+20}),]));
 	set("mpLegend2",([85:({32*30+2,32*30+29}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( who->get_legend(TASK_30,1) && !who->get_legend(TASK_30,2) )
		tmp += sprintf(ESC HIY "�����ź�\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_legend(TASK_30,2) && !who->get_legend(TASK_30,3) )
		tmp += sprintf(ESC HIY "���̽��\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,8) )
		tmp += sprintf(ESC HIY "ѯ��ԭ��\ntalk %x# welcome.4\n",getoid(me));
	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,20) )
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.6\n",getoid(me));
	if ( who->get_legend(TASK_30,28) && !who->get_legend(TASK_30,29) )
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.6\n",getoid(me));
	if ( who->get_legend(TASK_30,29) && !who->get_legend(TASK_24,29) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.6\n",getoid(me));

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
        	if ( who->get_legend(TASK_30,1) && !who->get_legend(TASK_30,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���²��ð찡��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_30,2) && !who->get_legend(TASK_30,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ϊ��֮��ֻ����������������ˣ�����û��ʲô����������ȥ�������������ï�ɣ�����û��ʲô��Ұ���ԡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;

        case 2:
        	if ( who->get_legend(TASK_30,1) && !who->get_legend(TASK_30,2) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�����ź�",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,2);
			who->add_exp(58000);
			who->add_potential(770);
			who->add_cash(51000);
			send_user(who,"%c%s",';',"�����ź� ���� 58000 Ǳ�� 770 ��Ǯ 51000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,31,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_30,2) && !who->get_legend(TASK_30,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,32,"���̽��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���̽��");
        	}
        	break;
        case 4:
        	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����м���������ͷʹ�������¾��������Ѷ��Ƿǣ����Ϊ�����أ��������װ��춷�ò����ֺ�������Ҳ��֪����β��֣���˵������������������ϵ���������ˣ���ȥ�����������鵽����ô���¡�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 5:
        	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,8) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,8);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,35,"ѯ��ԭ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ѯ��ԭ��");
        	}
        	break;
        case 6:
        	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ã����������������ºõõ��������ȥ�о��Ұ��մ������������������û��ʲô�����ֵ���������������ñ����ܹ���������ɵľ;��ܴ�Ӧ���ǰɡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,28) && !who->get_legend(TASK_30,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ȼ���ҵĺ��������Ժ�����һ죬�ҳ�����������������\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,29) && !who->get_legend(TASK_24,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǹ���С�߱�����һ������������������ͬ���˵������������ƻ��úܣ�һֱû������ץ���鰸������Ҳ��������������ڽ������ˣ���˳���������ڵ����ѣ�����һ�����ð�����Ͻ�������������������Ҳ����һ�¡�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 7:
        	if ( who->get_level() >= 85 && !who->get_legend(TASK_30,20) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,20);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,40,"�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������");
        	}
        	break;
        case 8:
        	if ( who->get_legend(TASK_30,28) && !who->get_legend(TASK_30,29) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64158",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,29);
			who->add_exp(68000);
			who->add_potential(830);
			who->add_cash(56000);
			send_user(who,"%c%s",';',"������� ���� 68000 Ǳ�� 830 ��Ǯ 56000 ն��Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,43,"" );
			me->do_welcome(6);
        	}
        	break;
        case 9:
        	if ( who->get_legend(TASK_30,29) && !who->get_legend(TASK_24,29) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,29);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,44,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;
        case 99:	
		INQUISITOR_D->do_look( who, me); 
        	break;
        }
}        	