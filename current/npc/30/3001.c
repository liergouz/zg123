
#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5415; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����Τ");
        set_city_name("�Թ�");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
	set("mpLegend2",([0:({32*19+23,32*19+30,32*20+3,}),]));
        setup();
}

string get_master() { return CITY_QIN->get_master(); }
string get_master_2() { return CITY_QIN->get_master_2(); }
string get_master_3() { return CITY_QIN->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
        tmp += CHAIN_D->get_chain_menu(who,me);
        if ( who->get_legend(TASK_19,22)&&!who->get_legend(TASK_19,23) ) 
		tmp += sprintf(ESC HIY "̸̸\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_19,23)&&!who->get_legend(TASK_19,24)) || (who->get_legend(TASK_19,24)&&!who->get_legend(TASK_19,25)) ) 
		tmp += sprintf(ESC HIY "�Լ�\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_19,29)&&!who->get_legend(TASK_19,30) ) 
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_19,30)&&!who->get_legend(TASK_20,1)) || (who->get_legend(TASK_20,1)&&!who->get_legend(TASK_20,3)) ) 
		tmp += sprintf(ESC HIY "�峡\ntalk %x# welcome.1\n",getoid(this_object())); 
 
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"���Ϊĳ�����е����񰡡�\n" ,get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");

	
}

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
        	if ( who->get_legend(TASK_19,22)&&!who->get_legend(TASK_19,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �³���⡣ٮ�����⡣�����⡣�������⡣�³���⡣ٮ�ˑ��⡣�������⡣���Đ��⡣�³����⡣ٮ�����⡣��ز���⡣���Ĳ��⡭��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,23)&&!who->get_legend(TASK_19,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ǵģ�����һ��Ů�Ӱ������Դ�������¥�������ĸ裬���������裬���ջ�ǣ���ƣ���һ��û��ȥ������¥�������ͻ�����������˽�����˶�����ֻ�޲�����ʱʱ��������ߣ�������λ�輧ȴ�Ǹ��߰�֮�ˣ���������¥Ҳֻ�ǹҸ��ƶ��ѣ��������﹫�Ӷ��������ؼ�ȴ����������ܣ��������������ģ����������õ������ǵļ��ˣ���������֮ǰҲ��һ���������ִ�ͨһ��ʫ�Ķ��ѣ���ί�������½���ר�Ŵ������������壬������������ʱһ��Сʫ�������������͸��Լ���ϣ�����������ҵ����ģ������ں���������\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_19,24)&&!who->get_legend(TASK_19,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������仨���⣬��ˮ���鰡����Ȼ���Լ�Ϊʲô����������Ÿ��ҡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_19,29)&&!who->get_legend(TASK_19,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������������˼�ˣ��ҵÿ��׼�������ܻ���Ҫ��İ�����\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_19,30)&&!who->get_legend(TASK_20,1))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Լ����ұ�������˼�������ٺ٣���ȥ�Գ��Ǹ����峡�ɣ��Һ�����Ҫһ�������ĵط���̸��\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_20,1)&&!who->get_legend(TASK_20,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Һ��Լ�Լ�õ�ʱ��Խ��Խ���ˣ��������ȥ�峡�ɡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_20,2)&&!who->get_legend(TASK_20,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л���������ô���æ�������������Ϣ���ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
				
	       	break;
        case 2:
        	if( who->get_legend(TASK_19,22)&&!who->get_legend(TASK_19,23) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,23);
			who->add_exp(3800);
			who->add_potential(170);
			who->add_cash(3600);
			send_user(who,"%c%s",';',"������Τ̸̸ ���� 3800 Ǳ�� 170 ��Ǯ 3600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,22,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if( who->get_legend(TASK_19,23)&&!who->get_legend(TASK_19,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0088");
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!',"��Я������Ʒ̫����");	
        			return ;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_19,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,36,"�Լ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�Լ�");
        	}
        	break;
        case 4:
        	if( who->get_legend(TASK_19,29)&&!who->get_legend(TASK_19,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/65065",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_19,30);
			who->add_exp(3800);
			who->add_potential(177);
			who->add_cash(3600);
			send_user(who,"%c%s",';',"���� ���� 3800 Ǳ�� 177 ��Ǯ 3600 ��������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,38,"" );
        		me->do_welcome(1);
        	}
        	break;
        case 5:
        	if( who->get_legend(TASK_19,30)&&!who->get_legend(TASK_20,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_20,1);
        		who->delete_save_2("lbwdaodunbing");
        		who->delete_save_2("lbwjiandunbing");
        		who->delete_save_2("lbwgongbing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,39,"�峡" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�峡");
        	}
        	break;
        case 6:
        	if( who->get_legend(TASK_20,2)&&!who->get_legend(TASK_20,3) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_20,3);
        		who->delete_save_2("lbwdaodunbing");
        		who->delete_save_2("lbwjiandunbing");
        		who->delete_save_2("lbwgongbing");
			who->add_exp(12000);
			who->add_potential(730);
			who->add_cash(18000);
			send_user(who,"%c%s",';',"�峡 ���� 12000 Ǳ�� 730 ��Ǯ 18000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,39,"" );
        	}
        	break;        	
        }
}
