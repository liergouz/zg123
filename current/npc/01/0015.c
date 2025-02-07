
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5403; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name( "�ǻ�����" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}
// �������Ի�����
void do_look( object who )
{
        string tmp = "";
        string tmp214 = "";
        object item;

	if ( (who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5)) || (who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6)) || (who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8)) || (who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9)))
        	tmp = sprintf(ESC"������֢\ntalk %x# welcome.3\n",getoid(this_object()));

	if( objectp( item = present("���ص�����", who, 1, MAX_CARRY) ) && who->get_quest("valentine.flag") == 4)
        	tmp = sprintf(ESC"����֮��\ntalk %x# welcome.214\n",getoid(this_object()));

	send_user(who,"%c%s",':',sprintf("%s:\n    ��֪����\n    ���Ǿ�����ҵ������Ѫֵ�����ԡ�����Խ�ã���ҽ�ɫ�������ѪֵҲԽ�ߡ�\n    ���������ҵ������ֵ�뷨���Ĺ�������������������Խ�ߣ���ҽ�ɫ�������ֵҲԽ�ߣ������������������ҲԽǿ��\n    ����������ҵ����������������Խ����ҽ�ɫ�����е����������ҲԽ�ߡ�������������Ҫ������֮һ��\n"ESC"����\ntalk %x# welcome.1\n" +
	tmp + tmp214 +
	ESC"�뿪",get_name(),getoid(this_object())));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,p,i;
	object who,item;
	string file,cWord="";
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        	case 1:
        		if ( who->get_legend(TASK_NEWBIE_02, 10) && !who->get_legend(TASK_NEWBIE_02, 11) )
				send_user(who,"%c%s",':',sprintf("%s:\n    ����������ҵ���������������Խ�ߣ���ҽ�ɫ�����е���������ҲԽ�ߡ��ǽ�������Ҳ��ɺ��ӵ����ԡ�\n    �������ܶԷ��Ĺ���������Ӱ�칥���������ʡ�����Խ�ߣ���ҽ�ɫ���ܶ�ܵĹ���ҲԽ�࣬���Ҹ����׹��������ˣ����ٹ�����յļ��ʡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
			else
				send_user(who,"%c%s",':',sprintf("%s:\n    ����������ҵ���������������Խ�ߣ���ҽ�ɫ�����е���������ҲԽ�ߡ��ǽ�������Ҳ��ɺ��ӵ����ԡ�\n    ����Խ�ߣ����ܶԷ������ļ��ʻ�Խ�ߣ������������Ի�Ӱ����ÿ�ι����ı����ʡ�\n"ESC"�뿪",me->get_name(),getoid(me)));
        		break;
        	case 2:
        		if ( who->get_legend(TASK_NEWBIE_02, 10) && !who->get_legend(TASK_NEWBIE_02, 11) )
        		{
        			who->set_legend(TASK_NEWBIE_02, 11);
				who->add_exp(280);
				who->add_cash(1500);
				send_user(who,"%c%s",';',"���ǻ�����̸̸ ���� 280 ��Ǯ 1500");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,17,"" );
        		}
        		break;
	        case 3: 
			if ( who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5) )
				send_user(who,"%c%s",':',sprintf("%s:\n    ��������������������������Ǹ����Ͳ��������������ж��ˣ����������ⶾ�ķ������������Ұɡ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6) )
				send_user(who,"%c%s",':',sprintf("%s:\n    ���ҹ��ƣ�������Ӧ��������һ����Ϊ���ɢ�Ķ�������Դ���Ǵ����ǿ�ˮ�����ж��Ĵ��������ù�����ǿ�ˮ�����ˮ�󣬲ų��ִ�֢״�ġ�\n    ��˶������ۻ�ɢ������Ҫ������ҩ����ϲ�����Ч����ҩ��ú�ֹҪ�������Ƿ��£���������ˮ�������ⶾ�á�\n    ����ȥ�����ۻ�ɢ�ɣ�����˵��һ����Сɽ�����϶������ۻ�ɢ��\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8) )
				send_user(who,"%c%s",':',sprintf("%s:\n    ����ҩ����Ҫһ����ʱ�䣬����������������ҩ�ɣ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪",me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9) )
				send_user(who,"%c%s",':',sprintf("%s:\n    �㽫�����ҩ�ø��峤�����Ҹ�������ǧ��Ҫ�ǵö���������������첻Ҫȥ�����ǿ�ˮ�����ˮ���ã��ǵ�Ҫ����ҩ�ø�������ã���Ҫ����ҩ����ˮ���ڣ����������α����α���\n    ����һ���£���ǧ�򲻵����ţ�������ϴ峤����������������ˮ�������˶���������峤�������£������¶��ĺ���֮�ˡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),getoid(me)));

	        	break;
	        case 4:
			if ( who->get_legend(TASK_41, 4) && !who->get_legend(TASK_41, 5) )
	        	{
				who->set_legend(TASK_41,5);
				who->add_exp(150);
				who->add_potential(20);
				send_user(who,"%c%s",';',"������֢��1�� ���� 150 Ǳ�� 20");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,27,"" );
				me->do_welcome(3);
        		}
	        	break;
		case 5:
	        	if ( who->get_legend(TASK_41, 5) && !who->get_legend(TASK_41, 6) )
	        	{
	        		who->set_legend(TASK_41,6);
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,28,"������֢��2��" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"������֢��2��");
	        	}
	        	break;
		case 6:
			if( who->get_legend(TASK_41, 7) && !who->get_legend(TASK_41, 8) )
			{
				if (TASK_LEGEND_D->check_task_item(who,"�ۻ�ɢ",1) != 1 )
	        			return;
//				TASK_LEGEND_D->give_item(who,"item/91/9100",5);
				who->add_exp(300);
				who->add_potential(30);
				who->add_cash(1800);
				who->set_legend(TASK_41, 8);
				send_user(who,"%c%s",';',"������֢��2�� ���� 300 Ǳ�� 30 ��Ǯ 1800");			
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,28,"" );
			}
			break;		        	
		case 7:
	        	if ( who->get_legend(TASK_41, 8) && !who->get_legend(TASK_41, 9) )
	        	{
	        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
	        			return ;
				TASK_LEGEND_D->give_item(who,"item/98/0200",1);
	        		who->set_legend(TASK_41,9);
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,29,"������֢��3��" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"������֢��3��");
	        	}
	        	break;
		case 214:
			if( who->get_quest("valentine.flag") == 4)
			{

			send_user(who,"%c%s",':',sprintf("%s:\n    �����������˼��С���ӣ������������������ӿ�������֮���ɲ���һ�����ɵ��°�������Ҫ������Ѫ�����࣬��Ը����\n"ESC"Ը��\ntalk %x# welcome.215\n"ESC"��Ը��",me->get_name(),getoid(me)));

			}
	        	break;
		case 215:
			if( who->get_quest("valentine.flag") == 4)
			{
			if(USER_INVENTORY_D->count_empty_carry(who) < 3 )
			{
			        send_user(who,"%c%s",';',"������û���㹻��λ���������ճ��������������˽����");
        			return;
			}
			if( objectp( item = present("���ص�����", who, 1, MAX_CARRY) ) )
			{
        			item->remove_from_user();
        			destruct(item); 
			}
                        switch( random(4) )
                        {
                               case 0 : file = "/item/04/0426";  break;
                               case 1 : file = "/item/04/0427";  break;
                               case 2 : file = "/item/04/0428";  break;
                               case 3 : file = "/item/04/0429";  break;
                              default : break;
                        }
                        for (i=0;i<3;i++)
                        {
				item = new (file);    
                        	if ( item )
				{	
					p = item->move(who,-1);
					item->add_to_user(p);			
				}	
			}
        		who->set_hp(1);
			who->set_quest( "valentine.flag", 10 );
			who->add_exp(500);
			who->add_potential(10);
	        	send_user( who, "%c%s", '!', "�õ�"HIR"õ��"NOR"��֦");
	        	write_user(who,ECHO"��Ϊ���������������õ������˽�����"+item->get_name()+"��֦���Ͻ��͸��İ������ɣ�");
	        	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
	        	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,4,"" ); 		                        
			}
	        	break;
	}
}