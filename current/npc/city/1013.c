
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
int get_char_picid() { return 5209; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�������");
        set_city_name("���");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("in", 12);
        set("out", 10);
//        set("level",82);
//        set("legend",({32*27+25}));
 	set("mpLegend",([30:({32*37+27}),80:({32*27+25})]));
 	set("mpLegend2",([80:({32*27+27}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();

	if ( (who->get_level() >= 80 && !who->get_legend(TASK_27,25)) || (who->get_legend(TASK_27,25) && !who->get_legend(TASK_27,27)))
	{
		tmp = sprintf(ESC HIY "��Ŀ�Դ�\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_level() >= 30 && !who->get_legend(TASK_37,27) )
		tmp += sprintf(ESC HIY "��ׯ�ڵĳ�ͷ\ntalk %x# welcome.4\n",getoid(me));

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
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    %s�����������������������ε��˽�����ǿ��ѵ��ˣ��ɰ����ε��ˡ��뵱�꣬����үү��үүΪ�����������˿Ӳ��������Ŀ�ɱ�˶����ˣ�ɱ���ֶ����ˣ�����үү������ÿ���ȥ�����۵�ֱ�����ᣬ�����Щ���˿������þ�Ȼ����ѹ����үү��үү��ʬ�ǣ�����үү��үү����ҹ����ҿ��ߣ�˵��Щ������ɱ�ļ������������������������ε���ң��������������°�����Ͻ�ȥ�ɵ�10�������ĵ������ã�������Ŀ�Դ�������ĺ���Ϣ����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),who->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_27,25) && !who->get_legend(TASK_27,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ӵ����Ϻ��ô���������Ժ����������������أ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_27,26) && !who->get_legend(TASK_27,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Щ���û����췴����\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 2:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_27,25);
        		who->delete_save("qgswdaodkl");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,24,"��Ŀ�Դ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ŀ�Դ�");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_27,26) && !who->get_legend(TASK_27,27) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_27,27);
        		who->delete_save("qgswdaodkl");
			who->add_exp(45500);
			who->add_potential(640);
			who->add_cash(44000);
			send_user(who,"%c%s",';',"��Ŀ�Դ� ���� 45500 Ǳ�� 640 ��Ǯ 44000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,24,"" );
        	}
        	break; 
        case 4:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_37,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰЩ��������ͷȥ�Ҽң�˵�ҽ��Ƿ��㣬�������Ҹ���������ׯ���õĳ�ͷ����˵һ��Ҫ���Ѻ����ֱ��˵ģ�������ȥ���м��������ϰ��죬����ѡ��һ�Ѳ���ĳ�ͷ���۸�Ҳ���������Լ�һֱû��ʱ�������ȥ���ҿ����������ɣ������Ұ����ͷ��ȥ������ͷ������������Ӧ���ڳ����԰�Ըɻ��ء�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_37,27) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/98/0180",1);
        		who->set_legend(TASK_37,27);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,72,"��ׯ�ڵĳ�ͷ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ׯ�ڵĳ�ͷ");
        	}
        	break;
        case 99:
        	GUARDER_D->do_look_2( who, me ); 
        	break;     
        }
}