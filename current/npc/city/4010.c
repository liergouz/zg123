
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5209; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("κ������");
        set_city_name("κ��");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",84);
//        set("legend",({32*28+23}));
 	set("mpLegend",([80:({32*28+23})]));
 	set("mpLegend2",([80:({32*28+25})]));
        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( (who->get_level() >= 80 && !who->get_legend(TASK_28,23)) || (who->get_legend(TASK_28,23) && !who->get_legend(TASK_28,25)))
	{
		tmp += sprintf(ESC HIY "��Ĺ�����\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_3( who, me ); 
	
}

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
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
 	case 1:
        	if ( who->get_level() >=80 && !who->get_legend(TASK_28,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ٺ٣���֪�����Ǹ�ʲô����֪���𣬲�֪���ɣ�����ľ�����֪������֪����֪��������ȷ������˵��ȷ������ȷ����ȷ����ô�����˲������أ������ŵ���ô˵����ȷ���أ���������ʵ��������ɣ����洫������һ��ΰ��ķ�ˮ�����ղ��ߣ������ˮ����˼�أ�����ż�ǵĻ��Ӿ��Ƿ�ˮ�����������ղ��أ����ǰѱ��˷ŵ�������û��ʲô�õı����ղ�������ʹ���ܹ��õ����õı��ܺ����ָ���ľ��ü�ֵ�����ְҵΰ��ɣ��ɱ���������Ĺ��ֻ��������Щ��֪���������֪����һ��ͨ�׵Ľз�����������Сʱ�򹷹���С������������˵ʲô���ߣ����ˣ�������õ�һ���ɿ���Ϣ��������Ĺ�������˲�֪��ϧ�ؽ�һ�����ʾ��ѵĹ��������������ˣ����Ǳ������� ������Ϊ��ˮ�����ղ��߾��Բ������������ƻ����������ܹ�����ǰȥȡ���������Ƕ�л���ˡ�������˵����ô�ࡣ\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_28,23) && !who->get_legend(TASK_28,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������㻹����һ��רҵ�ĵ�Ĺ�ߣ�Ҫ���ѵ�����ǣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_28,24) && !who->get_legend(TASK_28,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫���ˣ��Ҿ����߼��չ���������\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=80 && !who->get_legend(TASK_28,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,30,"��Ĺ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ĺ�����");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_28,24) && !who->get_legend(TASK_28,25) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,25);
			who->add_exp(47000);
			who->add_potential(690);
			who->add_cash(47000);
			send_user(who,"%c%s",';',"��Ĺ����� ���� 47000 Ǳ�� 690 ��Ǯ 47000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,30,"" );
        	}
        	break;  
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}