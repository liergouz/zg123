
// �Զ����ɣ�/make/npc/make8084

#include <npc.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5501; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("ׯ��");
        set_city_name("����");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
	set("mpLegend2",([0:({32*3+23,}),1:({32*3+25,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	
	if ( who->get_legend(TASK_NEWBIE_03,22) && !who->get_legend(TASK_NEWBIE_03,28) )
	{
		tmp = sprintf(ESC HIY "������\ntalk %x# welcome.1\n",getoid(me));
	}

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    ���ҿ���������������������ֻ�����ݳ����ֵ������ˣ���������������" + "\n",get_name()) +
		tmp +
		ESC"�뿪");
	else
		more_look_menu( who, sprintf( "%s��\n    ���ҿ���������������������ֻ�����ݳ����ֵ������ˣ���������������\n", get_name() ) );
	
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
        string name,place;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_NEWBIE_03,22) && !who->get_legend(TASK_NEWBIE_03,23) )
        	{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ѵ��Э�飬���������ݾ��Թ�������һ·�Ϸ��¶�ޣ���׼�����������ѽ��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	}
        	else if ( who->get_legend(TASK_NEWBIE_03,23) && !who->get_legend(TASK_NEWBIE_03,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ѵ��Э�飬���������ݾ��Թ�������һ·�Ϸ��¶�ޣ���׼�����������ѽ���Ҹ���˵��ӹ�صĵ����������ڴ���һ������������ǳ伢�ĺö���ѽ����ʿ����ȥ������20�����ɣ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_NEWBIE_03,24) && !who->get_legend(TASK_NEWBIE_03,25) )
			me->do_welcome(4);
		else if ( who->get_legend(TASK_NEWBIE_03,25) && !who->get_legend(TASK_NEWBIE_03,26) )	
        		me->do_welcome(6);
        	if ( who->get_legend(TASK_NEWBIE_03,26) && !who->get_legend(TASK_NEWBIE_03,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������¿ɵþ��죡���������¿ɵþ��죡\n"ESC"�뿪", me->get_name()));
        	break;
        case 2:
        	if ( who->get_legend(TASK_NEWBIE_03,22) && !who->get_legend(TASK_NEWBIE_03,23) )
        	{
			who->add_exp(500);
			who->add_potential(10);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_NEWBIE_03,23);
			send_user(who,"%c%s",';',"������ ���� 500 Ǳ�� 10");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,9,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_NEWBIE_03,23) && !who->get_legend(TASK_NEWBIE_03,24) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_NEWBIE_03,24);
        		who->delete_save_2("zxganliang");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_DONGTINGHU,"��ͥ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGTINGHU,1,"������(2)" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������(2)");
        	}
        	break;
        case 4:
		if ( !who->get_legend(TASK_NEWBIE_03,24) || who->get_legend(TASK_NEWBIE_03,25) )
			return ;
		if ( who->get_save_2("zxganliang")<20 )
        		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ɵÿ�㣬�������ҵİ�Ǩ��ƣ�\n"ESC"�뿪", me->get_name()));
		else
        		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫лл���ˣ���20�������ɰ����ҵĴ�æ�����ҵİ�Ǩ�ƻ����˲�С�����ð���\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 5:
        	if ( who->get_save_2("zxganliang")<20 )
        		return ;
		inv = all_inventory(who, 1, MAX_CARRY);
		
		if( !objectp( item = present("����", who, 1, MAX_CARRY) ) || item->is_legend_item() != 1 )
		{
			send_user(who,"%c%s",'!',"��ĸ�����?");
			return;	
		}			
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "����" || inv[i]->is_legend_item() != 1 )
				continue;
			amount += inv[i]->get_amount();		
		}
		if ( amount < 20 )
		{
			send_user(who,"%c%s",'!',"����������?");
			return;	
		}
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "����" || inv[i]->is_legend_item() != 1 )
				continue;
			inv[i]->remove_from_user();
			destruct(inv[i]);
		}
		who->add_exp(900);
		who->add_potential(40);
		who->add_cash(1000);
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_03,25);
		who->delete_save_2("zxganliang");
		send_user(who,"%c%s",';',"������ ���� 900 Ǳ�� 40 ��Ǯ 1000");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGTINGHU,1,"" );
		me->do_welcome(1);
        	break;  
        case 6:
        	if ( who->get_legend(TASK_NEWBIE_03,25) && !who->get_legend(TASK_NEWBIE_03,26) )
        	{
        		if ( !(name=who->get_save_2("zxkillnpc")) || !(place=who->get_save_2("zxkillnpc1")))
        		{
	        		name = ({"�ݺ�","�ĺ�","۳���","�ٸ���"})[random(4)];
	        		who->set_save_2("zxkillnpc",name);
	        		if ( name == "�ݺ�" )
	        			place = "������1";
	        		else if ( name == "�ĺ�" )
	        			place = "������2";
	        		else
	        			place = "������3";
	        		who->set_save_2("zxkillnpc1",place);
	        	}
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Թ�а��ѹ���������ҵ�һƬ����Ȱ˵����������ʡ������ˣ�����ɱ��ֻ֪�ݳ�����%s�����Ҳ���¶�棬������ɱ�����ǰɣ�%s����%s���㾡��ȥ�ɣ�ɱ�����Ǻ󱨸�������󽫾���������ˣ�����һ���ᰴ�����͵ġ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),name,name,place,getoid(me)));
        	}
        	break;
        case 7:
        	if ( !who->get_legend(TASK_NEWBIE_03,25) || who->get_legend(TASK_NEWBIE_03,26) )
        		return;
        	if ( !(name=who->get_save_2("zxkillnpc")) || !(place=who->get_save_2("zxkillnpc1")))
        		return;
		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
		who->set_legend(TASK_NEWBIE_03,26);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_DONGTINGHU,"��ͥ��" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_DONGTINGHU,2,"������(3)" );
		send_user( who, "%c%s", '!', "�õ����� "HIY"������(3)");        	
        	break;      	
        }
}