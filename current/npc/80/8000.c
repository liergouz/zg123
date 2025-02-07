
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start(string arg);
void accept_task();
void join_task();
void do_welcome( string arg );
void do_task_list();

// ��������ȡ��������
int get_char_picid() { return 6800; }

// ���������촦��
void create()
{
        set_name("ξ������ͷ");
        set_city_name("����");

        set_2( "talk", ([
                "task"          : (: do_task_start :),
                "accept"        : (: accept_task :),
                "join"		: (: join_task :),
                "welcome"          : (: do_welcome :),
                "tasklist"          : (: do_task_list :),
        ]));      
	set("mpLegend",([30:({32}),]));
        setup();
}

// �������Ի�����
   void do_look( object who ) { TASK_ESCORT_D->do_look( who, this_object() ); }

// ��������ʼ����
   void do_task_start(string arg) { TASK_ESCORT_D->do_task_start( this_player(), this_object(),arg ); }
// ��������������
   void accept_task() { TASK_ESCORT_D->accept_task( this_player(), this_object() ); }
// ��������������
   void join_task() { TASK_ESCORT_D->join_task( this_player(), this_object() ); }

   void do_task_list() { TASK_ESCORT_D->do_task_list( this_player(), this_object() ); }
   
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("���Ƿ�ʹ��'���������'���������������ʱ�䣿\n"
	                	ESC "%c\n"ESC"use %x# escort2\n"
	                        , 1, getoid(item) ) );			
			return;
		}		
	}        
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �������үү�����˲����������⣬����Щ��ʵ���ǡ���������˵Ҳ�գ���ɱ��ٽ���ʧ���ˣ�����������Ҫ�г徢��֪�����뵱�����������ʱ�򡭡�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_00, 14);
		who->add_exp(250);
		who->add_potential(30);
		send_user(who,"%c%s",';',"��ξ������ͷ̸̸ ���� 250 Ǳ�� 30");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"" );		
		me->do_welcome(3);
		break;		
	case 3:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �����ﱾ�ǿ����ṩ������һ��׬Ǯ�Ļ��ᣬ�ɽ�Щ���ӣ���һЩ�����޵�֮�󱲣����Ÿ��Ұ�æ����ţ�������ƭ���˲������������ԣ��Ժ��������������ڵ��ˣ�������ͨ���ҵĲ�����һ�ء�\n    �������Ұ��������˵��������滨�����󺺴�������Ҳ������Ѻ�𣬵����мǣ������ڹ������ǲ���ʹ����վ����߷����ȴ��͹��ܣ������������ͻ�ʧ�ܣ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;		
	case 4:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
	                {
	                        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n    �����ϵĶ�����ô�࣬����û��һ����ȫ�ĵط��ܷ������������Ʒ�����뻹�ǲ�������ɡ������ܷ��������Ʒ�ˣ����������ҡ�");
	                        return;
	                }
			
	                item = new( "/item/98/0237" );
	                if( p = item->move(who, -1) ) item->add_to_user(p);
			who->set_legend(TASK_49,13);
		        who->set_quest("escort.time", time() );
			send_user( who, "%c%s", '!', "�������"HIY"һ̽��ʵ"NOR"����");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,15,"һ̽��ʵ" );
		}
		break;		
	case 5:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���ʦү�츣�����˲����������⣬����Щ��ʵ���ǡ���������˵Ҳ�գ���ɱ��ٽ���ʧ���ˣ�����������Ҫ�г徢��֪�����뵱�����������ʱ�򡭡�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 6:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,15);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("�ݷ�ξ������ͷ ���� 300 Ǳ�� 35 ��Ǯ 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,17,"" );
			me->do_welcome(7);
		}
		break;		
	case 7:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��˵���������һ��з��������Ϲ������������������������ս���������ľ������������Ŀǰ����һ�����������������������ļ����Ӣ�ۺú����������������֣�������Ȥ�Ļ���ȥ�������İɡ�����ǰ��Ĵ��ų�ȥ��˳�Ŵ�·�����߾Ϳ��Կ����������ˣ���վ��һ�ô������档\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;		
	case 8:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"�ݷ�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ݷ�������");
		}
		break;	

	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		TASK_ESCORT_D->biaowang(me,who,flag);
		break;

	}
}
