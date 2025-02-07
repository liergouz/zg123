
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();
void do_fortune();
void accept_task();
void task_bonus();
void do_welcome( string arg );

void do_gold_task_start();
void accept_gold_task();
void gold_task_bonus();

// ��������ȡ��������
int get_char_picid() { return 6002; }

// ���������촦��
void create()
{
        set_name( "���ӳ�" );

        set_2( "talk", ([
                "task"          : (: do_task_start :),
                "cancel"        : (: do_task_cancel :),
                "fortune"	: (: do_fortune :),
                "accept"	: (: accept_task :),
                "bonus"		: (: task_bonus :),
                "welcome"    	: (: do_welcome :),

                "gold_start"    : (: do_gold_task_start :),
                "gold_accept"	: (: accept_gold_task :),
                "gold_bonus"	: (: gold_task_bonus :),
        ]));
//        set("level", 10);
//        set("legend", ({ 32,55 }));
//	set("mpLegend",([0:({32*41+1,32*41+13}),10:({32+23}),]));
	set("mpLegend2",([0:({32*48+20,32*48+27,32+20}),]));
        setup();
}

// �������Ի�����
void do_look( object who ) { TASK_BANDITI_D->do_look( who, this_object() ); }

// ��������ʼ����
void do_task_start() { TASK_BANDITI_D->do_task_start( this_player(), this_object() ); }
// ������ȡ������
void do_task_cancel() { TASK_BANDITI_D->do_task_cancel( this_player(), this_object() ); }
//ʹ����Ʒ
void do_fortune()
 { 
	TASK_BANDITI_D->do_fortune( this_player(), this_object() ); 
 } 
void task_bonus()
 { 
	TASK_BANDITI_D->task_bonus( this_player(), this_object() ); 
 }
 //��������
void accept_task()
 { 
	TASK_BANDITI_D->accept_task( this_player(), this_object()); 
 } 

// ��������ʼ�ƽ����ӳ�����
void do_gold_task_start() { TASK_BANDITI_D->do_gold_task_start( this_player(), this_object() ); }
// �������ƽ����ӳ�������
void gold_task_bonus() { TASK_BANDITI_D->gold_task_bonus( this_player(), this_object() ); }
//���������ܻƽ����ӳ�����
void accept_gold_task() { TASK_BANDITI_D->accept_gold_task( this_player(), this_object()); } 

// --------------------------------------------------------------- Զ�̵��� ----

// ������������Ʒ
int accept_object( object who, object item ){ return __FILE__ ->accept_object_callout( this_object(), who, item ); }

// ������������Ʒ(���߸���)
int accept_object_callout( object me, object who, object item ) 
{
        int level;

        me->to_front_eachother(who);

        if( !item->is_task_item() ) 
        {
                return 0;
        }
        else
        {
                item->give_bonus(who);

							 send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
                sprintf("%s��\n    ̫�D�D̫���ˣ��ҨD�D��һֱ�ܨD�D����Ҫ�����"
                        , me->get_name() ) );
        	return 1;
        }
}
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        object who, item;
        int p, z, x, y, flag;
	
        who = this_player();

	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("���Ƿ�ʹ��'���������'���������������ʱ�䣿\n"
	                	ESC "%c\n"ESC"use %x# banditi\n"
	                        , 1, getoid(item) ) );			
			return;
		}		
	}
        flag = to_int(arg);
        switch(flag)
        {
        case 1:                               
                if ( who->get_legend(TASK_NEWBIE_01, 19) && !who->get_legend(TASK_NEWBIE_01, 20) )
                	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ̫����̫����̫���ˣ��񡪡������֡����֡����оƺ��ˡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
                break;
	case 2:
		if ( !who->get_legend(TASK_NEWBIE_01, 19) || who->get_legend(TASK_NEWBIE_01, 20) )
			return ;
		if (TASK_LEGEND_D->check_task_item(who,"��Ǯ",1) != 1 )
        			return;
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_01, 20);
		who->add_exp(160);
		who->add_potential(10);
		send_user(who,"%c%s",';',"ţ������ ���� 160 Ǳ�� 10");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,10,"" );	
		break;
	case 3:
		if ( who->get_level()<10 )
			return ;
		if ( !who->get_legend(TASK_NEWBIE_01, 23) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �ܡ����ܹ�������үү˵�С����������㣬�㡪����ȥ�������ܡ�����һ�˰ɣ���Ҳ�ǡ����Ǹ������Ļ���ѽ���ǡ����ǵ��ˣ��ǡ�����ȥ�ܹ�Ŷ������㡪����֪��������ôȥ�Ļ����ҡ�������վ�ϰ��æ�͡��������ˡ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
 		else if ( !who->get_legend(TASK_NEWBIE_01, 24) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �㡪���㻹ûȥ���ɡ����������ҡ����������м���������Ŷ��\n"ESC"�뿪",me->get_name()));
		break;
	case 4:
		if ( who->get_level()<10 || who->get_legend(TASK_NEWBIE_01, 23)  )
			return;
		who->set_legend(TASK_NEWBIE_01, 23);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,13,"�����Ļ���" );
		break;
        case 5:
		if ( who->get_legend(TASK_48, 19) && !who->get_legend(TASK_48, 20))
//        	if ( !who->get_legend(TASK_41,1) )
//			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ԭ�������Сɽ����һȺ��ô�ɰ���С���������Ұ����ʳ��������ɽ���Ե�ʱ�����Ƕ���Χ��������Χ����Ϊ����֪���Ҳ����˺����ǣ��������ڣ�һ�ж����ˡ���\n    ���ǲ��ٿɰ����������������ǻṥ�����࣬�һ������Ǳ������Ի��������ֿ��ƣ��ű�������������ɣ�����ȥ�������ЩСɽ�����������������ǵ�����������������һ������ô����\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
//        	else 	if ( who->get_legend(TASK_41, 2) && !who->get_legend(TASK_41, 3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ���ǵ�������ôǿ���ҹ����Ǹ�Ļ��������ǵ���������Ҳ�������ҿ��ҵúúò�����һ�������Ǻܸ�л�㣡\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	
        	break;
	case 6:
        	if ( !who->get_legend(TASK_41,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_41,1);
        		who->delete_save("wdzxiaosj");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,31,"���Ի���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ի���");
        	}
        	break;
        case 7:
		if ( who->get_legend(TASK_48, 19) && !who->get_legend(TASK_48, 20))
//        	if ( who->get_legend(TASK_41,2) && !who->get_legend(TASK_41,3) )
        	{
			item = new( "/item/91/9100" );   //�о�ɢ
			if ( !item )
				return ;
			item->set_amount(5);
	                p =item->move(who, -1);
	                if ( p == 0 )
	                {
	                	destruct(item); 
	                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
	                	return ;
	                }
	                item->add_to_user(p);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48,20);
        		who->delete_save("new_chy");
			who->add_exp(650);
			who->add_potential(30);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"���Ի��� ���� 650 Ǳ�� 30 ��Ǯ 1000 �о�ɢ 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,108,"" );
			me->do_welcome(11);
        	}
        	break;  
        case 8:
//        	if ( !who->get_legend(TASK_41, 13) )
		if ( who->get_legend(TASK_48, 27) && !who->get_legend(TASK_48, 28))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ǹ����ˣ������һ���ͦ��������ľ��µģ���ϲ���ڼ������㻨���ݲݵģ����������￴����������������Ȼ�������˲��ٵ����������񡢾ջ�֮��ģ���������ϲ���Ļ����ǰٺϣ������Ŵ��ࡣ\n    ���ִ�ĵ����ϰ�һֱ���������ˣ���������װ�ޣ�������������һЩ�ٺϻ���װ�η��ݣ�����˵����ĳ��Ȳ��ˡ�����ϻ���ĸ�ܶ����аٺϻ�����ȥ������Щ���͵����Ұɡ�\n    �����������alt+w���������Խ��棬��ʹ����������Ϳ��Կ��ٻص����ִ�Ŷ��\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
//        	else 	if ( who->get_legend(TASK_41, 14) && !who->get_legend(TASK_41, 15) )
//			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ְٺϻ���������ϲ���ģ�\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	
        	break;
	case 9:
//        	if ( !who->get_legend(TASK_41,13) )
		if ( who->get_legend(TASK_48, 27) && !who->get_legend(TASK_48, 28))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_48,28);
        		who->delete_save("wdzbaihh");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,112,"װ�η���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"װ�η���");
        	}
        	break;
        case 10:
        	if ( who->get_legend(TASK_41,14) && !who->get_legend(TASK_41,15) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�ٺϻ�",3) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_41,15);
        		who->delete_save("wdzbaihh");
			who->add_exp(250);
			who->add_potential(10);
			send_user(who,"%c%s",';',"װ�η��� ���� 250 Ǳ�� 10");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,30,"" );
        	}
        	break;  
        case 11: 
		if ( who->get_legend(TASK_48, 20) && !who->get_legend(TASK_48, 21))
			send_user(who,"%c%s",':',sprintf("%s:\n    ���ִ�Ĵ��񼸺���������һ�ֲ�������ȫ��ƣ��������������˯����û�о���ȥ���֣�ȥ���������⣬����Ӱ���˴�����������֮ǰ���Ѿ�ѯ�ʹ�ҩ���ϰ��ˣ���ϧ��Ҳ��֪��������ʲô������˵����ҽ��ô�����δ���������ֵĲ�֢����˵�������˼���ʶ�㣬Ӧ�û�֪��������������ȥ�˹������˼ң�ѯ�������ڴ��˲�֢֮�¡�\n    �������˾��������ĺ��棬��ú����Ұɡ��ҵ�����ע���ʵ���ϸ�㡣\n"ESC"��������\ntalk %x# welcome.12\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 26) && !who->get_legend(TASK_48, 27))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ǵģ�����������������¶��ˣ��Ҷ���úõ�����µģ���һ·���������ˣ�\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 12:
//		if ( who->get_level() >= 5 && !who->get_legend(TASK_41, 4) )
		if ( who->get_legend(TASK_48, 20) && !who->get_legend(TASK_48, 21))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_48,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,109,"������֢��1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������֢��1��");
        	}
        	break; 
        case 13:
		if ( who->get_legend(TASK_48, 26) && !who->get_legend(TASK_48, 27))
        	{
			if (TASK_LEGEND_D->check_task_item(who,"��ҩ",1) != 1 )
        			return;
			item = new( "/item/88/0001" );   //��Ь
			if ( !item )
				return ;
	                p =item->move(who, -1);
	                if ( p == 0 )
	                {
	                	destruct(item); 
	                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
	                	return ;
	                }
	                item->add_to_user(p);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48,27);
			who->add_exp(600);
			who->add_potential(25);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"������֢��3�� ���� 600 Ǳ�� 25 ��Ǯ 2000 ���ֲ�Ь 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,111,"" );
			me->do_welcome(8);
        	}
        	break; 
        }
}