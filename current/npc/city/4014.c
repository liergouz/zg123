
// �Զ����ɣ�/make/npc/make8014

#include <npc.h>
#include <city.h>
#include <ansi.h>
#include <task.h>

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
        set_name("κ������");
        set_city_name("κ��");

        set_2( "talk", ([
                "enter"         : (: do_enter :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("out", 11);
        set("in", 13);
//        set("level",24);
//        set("legend",({32*6+7}));
 	set("mpLegend",([20:({32*6+7}),]));
 	set("mpLegend2",([20:({32*6+9}),]));
        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( who->get_level() >= 20 && (!who->get_legend(TASK_06,7) || !who->get_legend(TASK_06,9)))
	{
		tmp = sprintf(ESC HIY "Ӣ����\ntalk %x# welcome.1\n",getoid(me));
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
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_06,7)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����˽����۳�ɳ����Ӣ�£���С����������Ӣ�ۼ׳۳���ɳ��֮�ϣ������Ӣ����ȴ��û����ô����ʵ�֣���������Ҫ���ó����׼������Ȼ��ǿ��������������Ҫ�ģ����ǣ����˶��������⣬�Ҽ��е���õ�һ��Ӣ�ۼף�����˵����̤��������ͤ����Ӣ�ۼף����������������������������ׯ�͵���̤���ˣ������ų̿죬�ҹ��ư��ʱ������������ҵ��ˡ�\n    ��������Ӣ�ۼף�����Բ���Ұ���Σ���һ�����������ġ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_06,7) && !who->get_legend(TASK_06,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������Ⱳ���Ǳ���ʵ���ҵ����Ӣ�����ˣ���������ʵʵվ���ҵĸڰɣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_06,8) && !who->get_legend(TASK_06,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ĸ���������Ӣ�ۼף�̫���ˣ�����ʵ�ظо�������ʵ�������ֽ���һ����\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_06,7)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_06,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,21,"Ӣ����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ӣ����");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_06,8) && !who->get_legend(TASK_06,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Ӣ�ۼ�",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_06,9);
			who->add_exp(1500);
			who->add_potential(60);
			who->add_cash(1200);
			send_user(who,"%c%s",';',"Ӣ���� ���� 1500 Ǳ�� 60 ��Ǯ 1200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,21,"" );
        	}
        	break;
        case 99:
        	GUARDER_D->do_look( who, me ); 
        	break;
        }
}