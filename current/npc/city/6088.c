
// �Զ����ɣ�/make/npc/make8088

#include <npc.h>
#include <task.h>
#include <ansi.h>

#define JOB_TRADER_D    "/inh/job/trader"

inherit OFFICER;
inherit "/inh/npc/trader";
int is_self_look() { return 1;}

void reset();
void do_good( string arg );
void do_welcome(string arg);
// ��������ȡ��������
int get_char_picid() { return 5401; }

// ���������촦��
void create()
{
        set_name("��������");
	set_real_name("����");
        set_city_name("����");

        set_2( "talk", ([
                "good"          : (: do_good :),
                "welcome"	: (: do_welcome :),
        ]) );
        reset();
//	set("level",13);
//	set("legend",({32*3+11,}) );
	set("mpLegend",([10:({32*3+11}),30:({32*8+25})]));
	set("mpLegend2",([30:({32*8+27})]));
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
                "01" : "/item/99/9961",
                "02" : "/item/99/9962",
                "03" : "/item/99/9963",
        ]) );
        set_2( "list", ([
                "01" : 80,
                "02" : 50,
                "03" : 10,
        ]) );
}

void do_look( object who ) 
{
	string tmp="";
	object me = this_object();
	
	if ( who->get_level() >= 10 && who->get_legend(TASK_NEWBIE_03,11)==0 )
	{
		 tmp = sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 30 && !who->get_legend(TASK_08,25) ) || ( who->get_legend(TASK_08,25) && !who->get_legend(TASK_08,27) ) )
	{
		tmp += sprintf(ESC HIY "�����ֵĹ��\ntalk %x# welcome.3\n",getoid(me));
	}
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
        object who;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 10 && who->get_legend(TASK_NEWBIE_03,11)==0 )
        		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �١��������ˣ��Ҽ�������������������������ʶӦ�ò��ٰɡ���˵���Ϻ�����������Ǹ��ö�����\n    �������鱦����һ·���ǣ��ر����ǿ��Ϻ�������ǳ�������ۣ����ɵ����������պñ�����������ֵ��չ��ˣ���Ϊ���Ϻ�����ɻ��˲������ӣ���ȻҲ�������ü�Ǯ����һֱ���Ҹ�������װ����Ϻ����飬����һֱ������Ѱ�ú��ʵģ���ȥ�����ܲ��ܰ��������������������Ĵ󸻺������������ġ�\n    ��������������ͳ��ڣ�������������������ܿ����ˡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() >= 10 && who->get_legend(TASK_NEWBIE_03,11)==0 )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_NEWBIE_03,11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,7,"��������(1)" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������(1)");
        	}
        	break;
        case 3:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����һ�������ˣ�����������������Ž������˵��������Ϊ�˶�׬��Ǯ����ɫ�����˲Żؼҡ��׻�˵��ҹ·�߶��ˣ��ܻ�������������û����������Ǽ���һ�Ρ�\n    �Ҽǵ������Ѿ������ˣ������ŵ��Ӵ������ɽ�������֣�׼���ؼ��ݸ���ˮ�裬�ú���Ϣ��ͻȻ���ҷ��������ֺ����ƺ����������ǹ⣬ӫ��ӫ�̵ģ�ֱ�������ң���һ���ǹ��\n    ��������������˼�˵������������һ����һ��ҹ������������������ȥ����һ�°ɡ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_08,25) && !who->get_legend(TASK_08,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �´���������Ҳ��������·�����ˣ���ñ��Ƕ��ײ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_08,26) && !who->get_legend(TASK_08,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǣ��Ժ����������Ҳ���õ����ˡ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 4:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_08,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,21,"�����ֵĹ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ֵĹ��");
        	}
        	break;
        case 5:
        	if ( who->get_legend(TASK_08,26) && !who->get_legend(TASK_08,27) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/final/16/1637",5);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_08,27);
			who->add_exp(2500);
			who->add_potential(90);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"�����ֵĹ�� ���� 2500 Ǳ�� 90 ��Ǯ 2000 ��ʯ�� 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,21,"" );
        	}
        	break;   
        case 99:
        	JOB_TRADER_D->do_look( who, me ); 
        	break;
        }
}