
// �Զ����ɣ�/make/npc/make8088

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

#define JOB_TRADER_D    "/inh/job/trader"

inherit OFFICER;
inherit "/inh/npc/trader";

void reset();
void do_good( string arg );
int is_self_look() { return 1;}

// ��������ȡ��������
int get_char_picid() { return 5401; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("κ������");
	set_real_name("����");
        set_city_name("κ��");

        set_2( "talk", ([
                "good"          : (: do_good :),
                "welcome"	: (: do_welcome :),
        ]) );
        reset();
//	set("level",23);
//	set("legend",({32*5+25}));
 	set("mpLegend",([20:({32*5+25}),]));
 	set("mpLegend2",([90:({32*38+17}),20:({32*5+27}),]));
        setup();
}

// ��������λ����
void reset()
{
	object me = this_object();
	me->set("reset_time", time());
        set_buy_rate( random(1001) );
        set_sell_rate( random(1001) );

        set_2( "good", ([
                "01" : "/item/99/9941",
                "02" : "/item/99/9942",
                "03" : "/item/99/9943",
        ]) );
        set_2( "list", ([
                "01" : 300,
                "02" : 200,
                "03" : 100,
        ]) );
}

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( ( who->get_level()>=20&&!who->get_legend(TASK_05,25)) || ( who->get_legend(TASK_05,25)&&!who->get_legend(TASK_05,27)) )
	{
		tmp = sprintf(ESC HIY "����������\ntalk %x# welcome.1\n",getoid(me));
	}
        if ( who->get_level() >= 90 && who->get_legend(TASK_38,17) && !who->get_legend(TASK_38,18) ) 
		tmp += sprintf(ESC HIY "ѯ�ʼ۸�\ntalk %x# welcome.4\n",getoid(me)); 

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_normal_word(me) + "\n"ESC"����\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		JOB_TRADER_D->do_look( who, this_object() ); 
	
}
void do_good( string arg ) { JOB_TRADER_D->do_good( this_player(), this_object(), arg ); }
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag;
        object who,item;     
       	string *nTmp,tmp;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_05,25)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ʶ�ٷ����ɽ���Һ�С��ʱ������Ҹ�����ǰ�������ԣ�һ��Ҫ������������˵����ˣ�һ����ô�����ȥ�ˣ����һ�δʵ�ֵ������µ����ԣ������ҵÿ����˵İ�������ʵ���ˡ�\n    ��Щ�������Ǹ��ٷ˲���������̫��Ĳ���������˺ܶ�ƶ��İ��գ�ϣ�������������֮�֣�������ٷ����ɽ������\n    ���������ڰ���ׯ�İ�����������棬����̤��������������Ե�����ׯ��\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_05,25) && !who->get_legend(TASK_05,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����һ����ұ�������æ���ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_05,26) && !who->get_legend(TASK_05,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���²������Ǹ����˵Ľٷ˱������ˣ��Ҷ�����������Ҳ����ˣ��ǳ���л��\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_05,25)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_05,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,17,"����������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����������");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_05,26) && !who->get_legend(TASK_05,27) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,20,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_05,27);
			who->add_exp(1300);
			who->add_potential(70);
			who->add_cash(1200);
			send_user(who,"%c%s",';',sprintf("���������� ���� 1300 Ǳ�� 70 ��Ǯ 1200 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,17,"" );
        	}
        	break;
        case 4:
        	if ( who->get_level() >= 90 && who->get_legend(TASK_38,17) && !who->get_legend(TASK_38,18) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫��Ǹ�ˣ����������Ѿ�����ȥ�ˣ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;        	
        case 5:
        	if ( who->get_level() >= 90 && who->get_legend(TASK_38,17) && !who->get_legend(TASK_38,18) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_38,18);
			who->add_exp(33000);
			who->add_potential(420);
			who->add_cash(25000);
			send_user(who,"%c%s",';',"ѯ�ʼ۸� ���� 33000 Ǳ�� 420 ��Ǯ 25000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,75,"" );
        	}
		break;
        case 99:
        	JOB_TRADER_D->do_look( who, me ); 
        	break;
        }
}