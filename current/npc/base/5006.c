
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 7405; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��Ʒ���ϰ�");
	set_real_name("����");
        set_city_name("�ع�");

        set_2( "good", ([
                "01" : "/item/88/6020",
                "02" : "/item/88/6030",
                "03" : "/item/88/6040",
                "06" : "/item/87/6020",
                "07" : "/item/87/6030",
                "08" : "/item/87/6040",

        ]) );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
 	set("mpLegend",([65:({32*51+1})]));
 	set("mpLegend2",([65:({32*51+3})]));
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 51);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( (who->get_level() >= 65 && !who->get_legend(TASK_2_01,1)) || 
		(who->get_legend(TASK_2_01,1) && !who->get_legend(TASK_2_01,3)) )
		result += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	result += sprintf(ESC "�������ʺ��ҵ�װ����\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
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
        	if ( who->get_level() >= 65 && !who->get_legend(TASK_2_01,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������������ɡ���������λ�������ӳճմ��������ʸ����ĳɿ���ɡ���\n"ESC"�뿪", me->get_name(),));
		else if ( who->get_legend(TASK_2_01,1) && !who->get_legend(TASK_2_01,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������������\n"ESC"�뿪", me->get_name(),));
		else if ( who->get_legend(TASK_2_01,2) && !who->get_legend(TASK_2_01,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ɡ������������ܶ�������������\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_legend(TASK_2_01,2) && !who->get_legend(TASK_2_01,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_01,3);
			who->add_exp(16800);
			who->add_potential(400);
			who->add_cash(19600);
			send_user(who,"%c%s",';',"������� ���� 16800 Ǳ�� 400 ��Ǯ 19600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,103,"" );
        	}
        	break;
	default:
	case 99:
        	"/npc/base/0005"->do_welcome2(me, "99");
		break;
	}
	
}