
// �Զ����ɣ�/make/npc/make8012

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_out();
void do_record();

// ��������ȡ��������
int get_char_picid() { return 0050; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("��������");
        set_city_name("����");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("in", 13);
        set("out", 11);
//        set("level",31);
//        set("legend",({32*8+7}));
	set("mpLegend",([30:({32*8+7,32*37+25}),95:({32*33+16})]));
	set("mpLegend2",([30:({32*8+9,}),95:({32*33+18})]));
        setup();
}

string get_master() { return CITY_CHU->get_master(); }
string get_master_2() { return CITY_CHU->get_master_2(); }
string get_master_3() { return CITY_CHU->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	int id;
	object me = this_object();
	id = getoid(me);
	if ( (who->get_level() >= 30 && !who->get_legend(TASK_08,7)) || (who->get_legend(TASK_08,7)&&!who->get_legend(TASK_08,9)) )
	{
		tmp = sprintf(ESC HIY "����Ѱ��\ntalk %x# welcome.1\n",id);
	}
	if ( ( who->get_level() >= 95 && !who->get_legend(TASK_33,16) ) || ( who->get_legend(TASK_33,16) && !who->get_legend(TASK_33,18) ) )
		tmp += sprintf(ESC HIY "�ͽ�����\ntalk %x# welcome.4\n",id);
	if ( who->get_level() >= 30 && !who->get_legend(TASK_37,25) )
		tmp += sprintf(ESC HIY "�����Ÿ����ʹ��\ntalk %x# welcome.7\n",id);

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_2( who, me ); 
	
}
void do_out() { GUARDER_D->do_out( this_player(), this_object() ); }

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
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ȥ��������\n    ������ïʢ��ˮ�ݣ����õ�ľͷ����ʱ�������������̶����������������Ҳֻ��������Ϊ��ȥ�ĵط������п��ܴ��ڱ��\n    ������˵�����������һ�䱦�����Ķ����㹻��������һ���ӣ���������ʵ��̫Σ�գ��Ҳ�̫��ȥ����ȥ����������ô������������䱦��������Ժ���Ҳ����������վ���ˣ��紵���ܵ������治���ܰ���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_08,7) && !who->get_legend(TASK_08,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�ҵ���������ƭ�ҵİ����һ�������ȥ�Ұɡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_08,8) && !who->get_legend(TASK_08,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Ҳ����������վ���ˣ�����Ǯ�ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_08,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,15,"����Ѱ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����Ѱ��");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_08,8) && !who->get_legend(TASK_08,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_08,9);
			who->add_exp(2200);
			who->add_potential(80);
			who->add_cash(1700);
			send_user(who,"%c%s",';',"����Ѱ�� ���� 2200 Ǳ�� 80 ��Ǯ 1700");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,15,"" );
        	}
        	break;   
	case 4:
		if ( who->get_level() >= 95 && !who->get_legend(TASK_33,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫�����ˣ���������Ȼ������ε�Ϸ�ұ��ã������ɱ�ģ���Ȼ�Ҵ򲻹����������������������˫ȫ�����Ѱ�����һ��Ҫ���ҽ�ѵ�Ǹ����٣�������Ҳû�е��ӵ�Ϸ�ҵı��ã��ұ��������Ҫȥ���ɽ�����ֲɲ�ҩ������һ�����ڸ�������ץס����������趼����ʶ��\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_33,16) && !who->get_legend(TASK_33,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ʲô�����Ȼ��������ˣ����ģ����ǿ����ı��ã����ǿ�����δ����������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_33,17) && !who->get_legend(TASK_33,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������٣��۸��ұ��ã���ò��ú�����\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 5:
        	if ( who->get_level() >= 95 && !who->get_legend(TASK_33,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_33,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,38,"�ͽ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ͽ�����");        		
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_33,17) && !who->get_legend(TASK_33,18) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/61017",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_33,18);
			who->add_exp(71000);
			who->add_potential(930);
			who->add_cash(60000);
			send_user(who,"%c%s",';',"�ͽ����� ���� 71000 Ǳ�� 930 ��Ǯ 60000 ���ع�ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,38,"" );
        	}
        	break;
        case 7:
       		if ( who->get_level() >= 30 && !who->get_legend(TASK_37,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ʹ������ĸ�׵�ֶ�ӣ�Ҳ���ҵı�磬�����Ѿ��ܶ���û���ˣ�ĸ�����ˣ�Խ��Խ�������������Щ��������ǣ��������������������ң�����������ʱ����Щ�ý����Ǿ۾ۣ��ҿ�����һ�£����Ҫȥ�����Ҳֻ�ܽ�ס�����ʹ�ڼ��ˡ�����������ȥ�����ʹ�ڴ���к����������Ϣ��������\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 8:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_37,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_37,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,44,"�����Ÿ����ʹ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����Ÿ����ʹ��");        		
        	}
        	break;
        case 99:
        	GUARDER_D->do_look_2( who, me ); 
        	break;     
        }
}