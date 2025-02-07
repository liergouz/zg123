
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5805; }

// ���������촦��
void create()
{
        set_name( "������" );

        set_2( "talk", ([
                "welcome"         : (: do_welcome :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	
	if (who->get_legend(TASK_NEWBIE_02, 7)&&!who->get_legend(TASK_NEWBIE_02, 8))
		tmp +=  sprintf(ESC HIY "С������������\ntalk %x# welcome.1\n",getoid(this_object()));
	if (who->get_legend(TASK_41, 11)&&!who->get_legend(TASK_41, 12))
		tmp +=  sprintf(ESC "��ľ��\ntalk %x# welcome.3\n",getoid(this_object()));

        tmp += CHAIN_D->get_chain_menu(who,this_object());
        send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), 
                sprintf("%s��\n    �Դӽ�ѵ����Щɽ���������ӱ���ǰ��̹���ˣ�������ȥ������С����������ɡ�\n"
                        + tmp +
                        ESC "��ֻ����㿴��\nCLOSE\n",get_name(), getoid(this_object()) ) );
}
// �������Ի�����
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,p;
	object who,item;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        	case 1:
			if (!who->get_legend(TASK_NEWBIE_02, 7)||who->get_legend(TASK_NEWBIE_02, 8)||who->get_legend(TASK_NEWBIE_02, 9) )
				return;
	                send_user( who, "%c%c%w%s", ':',3,get_char_picid(), sprintf(get_name() + "��\n    �������ֻС���˰ɣ����ǲ������ڲ�����Ҫ�Եģ��Ǻǣ��Ҿ�֪���������������������ȥι���ɡ�С����ܸ��˵ġ�\n"ESC"�õ�����\ntalk %x# welcome.2\n"ESC"�뿪",getoid(me)));
        		break;
		case 2:
			if (!who->get_legend(TASK_NEWBIE_02, 7)||who->get_legend(TASK_NEWBIE_02, 8) ||who->get_legend(TASK_NEWBIE_02, 9))
				return;
			item = new("item/98/9887");
			p = item->move(who,-1);
			if ( !p )
			{
				send_user(who,"%c%s",'!',"�����ϵĶ���̫����");				
				return ;
			}
			item->add_to_user(p);
			who->set_legend(TASK_NEWBIE_02, 8);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,16,"С������(�Ѿ����)" );
			USER_TASK_D->send_task_intro(who,2,TID_NEWBIE_01,16);
			send_user(who,"%c%s",'!',"��õ�С������");	
			break;
	        case 3:
	        	if ( who->get_legend(TASK_41,11) && !who->get_legend(TASK_41,12) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ��˺þã������ڰ��ҰѶ������ռ����ˣ�лл������͹�����\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
	        	break;
	        case 4:
	        	if ( who->get_legend(TASK_41,11) && !who->get_legend(TASK_41,12) )
			{
				if (TASK_LEGEND_D->check_task_item(who,"��ľ��",1) != 1 )
	        			return;
				who->add_exp(250);
				who->add_potential(20);
				who->set_legend(TASK_41, 12);
				send_user(who,"%c%s",';',"������ ���� 250 Ǳ�� 20");			
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,33,"" );
			}
	        	break;
        }
}