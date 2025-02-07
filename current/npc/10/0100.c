#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5415; }

// ���������촦��
void create()
{
        set_name("����");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*9+22,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        if ( who->get_legend(TASK_09,21) && !who->get_legend(TASK_09,22) ) 
		tmp += sprintf(ESC HIY "�����ٵ�ѯ��\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_09,22) && !who->get_legend(TASK_09,23) ) 
		tmp += sprintf(ESC HIY "���ӵ�����\ntalk %x# welcome.1\n",getoid(this_object())); 
        send_user( who, "%c%s", ':', sprintf( "%s��\n    ۶����������������������Ŀ���������\n", get_name())
        + tmp +
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_09,21) && !who->get_legend(TASK_09,22) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Թ������ࡢ��������˵����������һ�����ϣ������������촽�������һ�����촽û���ˣ����ݾͻ�е����䡣����Թ����������ˣ�����ͻ��ֵ��롢������������Ҫ���Թ�������һ��ҪѸ�١�\n    ����Ϊ�ţ���ȥ������9�����ӣ�Ȼ�󽻸������٣����������ҵ���˼�ˣ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_09,22) && !who->get_legend(TASK_09,23) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Թ������ࡢ��������˵����������һ�����ϣ������������촽�������һ�����촽û���ˣ����ݾͻ�е����䡣����Թ����������ˣ�����ͻ��ֵ��롢������������Ҫ���Թ�������һ��ҪѸ�١�\n    ����Ϊ�ţ���ȥ������9�����ӣ�Ȼ�󽻸������٣����������ҵ���˼�ˣ�������ɽ�������Ϳ����õ����ӡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_09,23) && !who->get_legend(TASK_09,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��û�������ٴ����ҵ���˼��?\n"ESC"�뿪", me->get_name()));
        	break;

        case 2:
        	if ( who->get_legend(TASK_09,21) && !who->get_legend(TASK_09,22) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_09,22);
			who->add_exp(2500);
			who->add_potential(60);
			who->add_cash(1800);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,2,"" );
			send_user(who,"%c%s",';',"�����ݺ���2�� ���� 2500 Ǳ�� 60 ��Ǯ 1800");
			me->do_welcome(1);
        	}
        	break;   
 	case 3:
        	if ( who->get_legend(TASK_09,22) && !who->get_legend(TASK_09,23) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_09,23);
        		who->delete_save_2("zouzidaozi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,3,"�����ݺ���3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ݺ���3��");
        	}
        	break;  
        }
}