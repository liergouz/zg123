
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 6; }
// ���Լ���do_look����
int is_self_look() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 5403; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("ҩ���ϰ�");
	set_real_name("����");
        set_city_name("���");

        set_2( "good", ([
                "01" : "/item/91/9100",
                "02" : "/item/91/9101",
                "03" : "/item/91/9110",
                "04" : "/item/91/9111",
                "05" : "/item/stuff/0106",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
	set("mpLegend2",([50:({32*15+8}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( who->get_legend(TASK_15, 7) && !who->get_legend(TASK_15, 8) )
	{
		result = result + sprintf( ESC HIY "������֥\ntalk %x# welcome.1\n", getoid(me) );
	}
	if ( (who->get_legend(TASK_15, 8) && !who->get_legend(TASK_15, 9)) || (who->get_legend(TASK_15, 9) && !who->get_legend(TASK_15, 10)) )
	{
		result = result + sprintf( ESC HIY "���˵Ĺֲ�\ntalk %x# welcome.1\n", getoid(me) );
	}
	result = result + sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

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
 		if ( who->get_legend(TASK_15,7) && !who->get_legend(TASK_15,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֥�Ǻε�����ҩ�ģ�����û����ô���׵õ��������ȥ�೤������������\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_15, 8) && !who->get_legend(TASK_15, 9))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֥�Ǻε�����ҩ�ģ�����û����ô���׵õ��������ȥ�೤������������\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if (who->get_legend(TASK_15, 9) && !who->get_legend(TASK_15, 10))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ˵������֥�����ң���ɵö�Ŭ��ѽ��\n"ESC"�뿪", me->get_name()));

        	break;
    
        case 2:
        	if ( who->get_legend(TASK_15,7) && !who->get_legend(TASK_15,8) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,8);
			who->add_exp(4800);
			who->add_potential(180);
			who->add_cash(2800);
			send_user(who,"%c%s",';',"���˵Ĺֲ���1�� ���� 4800 Ǳ�� 180 ��Ǯ 2800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,30,"" );
        		me->do_welcome(1);
        	}
        	break;   
	case 3:
        	if(who->get_legend(TASK_15, 8) && !who->get_legend(TASK_15, 9))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,9);
        		who->delete_save_2("frlingzhi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,31,"���˵Ĺֲ���2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���˵Ĺֲ���2��");
        	}
        	break; 
        }
}