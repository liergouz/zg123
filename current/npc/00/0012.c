
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0012; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��ֵĵ�����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
	set("mpLegend",([0:({17,}),]));
	set("mpLegend2",([0:({19}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        int id = getoid( this_object() );

	if ( !who->get_legend(TASK_NEWBIE_00, 19))	
		tmp = sprintf(ESC  +HIY+"�����˵�ί��\ntalk %x# welcome.1\n",id);
	send_user( who, "%c%s", ':', get_name() + "��\n    ��������\n        (����ȥ�е����ڲ�ͬ�ĵ����ˡ�)\n" +
		tmp +
		ESC"�뿪"
		);
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);

        switch(flag)
        {
        case 1:
		if ( !who->get_legend(TASK_NEWBIE_00, 17) )
		{
	                 send_user( who, "%c%s", ':', sprintf("%s��\n    �������Ǳߵ����ࡣ\n"
	                 "    û�����ǽ��㡣\n"
	                 "    ��ʵ��һ�������Ѿ������Һó�һ��ʱ���ˡ���\n"
	                 "    �������������ģ��������������һ�ѵ������ֻ�в�Ƭ��ľ���ˡ������Щ��������ѻ�����ǳ�Ц��û���ԡ���Ȼ������������Ҳ����ʵ�������Ҳ������һ����һ�����ԵĻ�����Щ��ѻҲ�����ٳ�Ц���ˡ�\n"
	                 "    ����˵��Ϫ�Ķ����������ڳ��������ȡ���˲��ٵ���ʯ���������Щ��ʯ��Ϊ�ҵ��Դ�Ӧ���൱������ϧ��û�нţ������߹�ȥ��������ܰ������æ���һ�ܸм���ġ�\n"
	                 ESC "��������\ntalk %x# welcome.2\n"
	                 ESC "�뿪",
	                 me->get_name(), getoid(me) ) );
		}
		else if ( who->get_legend(TASK_NEWBIE_00, 18) && !who->get_legend(TASK_NEWBIE_00, 19) )
			send_user( who, "%c%s", ':',me->get_name()+":\n    ̫�����������������γ����ˡ������ǰ�����һ����æ����ʵ��̫��л�ˡ�\n"+sprintf(ESC"�������\ntalk %x# welcome.3\n",getoid(me))+ESC"�뿪");
		else
			send_user( who, "%c%s", ':',me->get_name()+":\n    ����ʱ��Ҫ�����ң�����˼��һ������µ��������������õ���ʯ���������Ұɣ�\n"ESC"�뿪");
                break;
	case 2:
		if (who->get_legend(TASK_NEWBIE_00, 17))	
			return ;
		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
		who->set_legend(TASK_NEWBIE_00, 17);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,19,"�����˵�ί��" );
		send_user( who, "%c%s", '!', "�������"HIY"�����˵�ί��"NOR"����");
		break;
	case 3:
		if ( who->get_legend(TASK_NEWBIE_00, 18) && !who->get_legend(TASK_NEWBIE_00, 19) )
		{
			if( !objectp( item = present("��ʯ", who, 1, MAX_CARRY) ) )
			{
				send_user(who,"%c%s",'!',"�����ʯ��?");
				return;
			}
			item->remove_from_user();
			destruct(item);
			TASK_LEGEND_D->task_finish(who);
			who->add_potential(30);
			who->add_exp(180);
			send_user(who,"%c%s",';',"�����˵�ί�� ���� 180 Ǳ�� 30 ");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,19,"" );	
			who->set_legend(TASK_NEWBIE_00, 19);
		}
		break;                                                                                                                                 
        }
}
