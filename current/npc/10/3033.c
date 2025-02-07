
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5901; }

// ���������촦��
void create()
{
        set_name("�Ŷ���");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",51);
//        set("legend",({32*13+22}));
	set("mpLegend",([50:({32*13+22}),]));
	set("mpLegend2",([50:({32*13+24}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 50 && !who->get_legend(TASK_13,22)) || (who->get_legend(TASK_13,22)&&!who->get_legend(TASK_13,24)) ) 
		tmp += sprintf(ESC HIY "���\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    ˵����ϹŶ���������¿���û�����˱ȵù��ң�\n", get_name())
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
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
	       	if ( who->get_level() >= 50 && !who->get_legend(TASK_13,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����һ��ʧ�������ա������\n    ���ǿ����ú��������ܳ����ָ����ķ������ޣ���滨�񣬿�ϧ���ǣ����������Ѿ�ʧ���ܾúܾ��ˣ����գ�����˵���೤��һ��������һ����񣬿����֪������һ����ô����������������취�ҵ�10���Ļ�����һ�����߼�Ǯ�չ���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,22) && !who->get_legend(TASK_13,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڱ��˶�����֪�����£�Ҳ��֪�ⶫ��ֵǮ����ɵøϽ�����������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,23) && !who->get_legend(TASK_13,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������ؿɷ�����ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_13,22) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,22);
        		who->delete_save_2("gdsnidiao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,20,"���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_13,23) && !who->get_legend(TASK_13,24) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���",10) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64077",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,24);
        		who->delete_save_2("gdsnidiao");
			who->add_exp(5700);
			who->add_potential(220);
			who->add_cash(4600);
			send_user(who,"%c%s",';',"��� ���� 5700 Ǳ�� 220 ��Ǯ 4600 ��Х��װͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,20,"" );
        	}
        	break;   
		
        }
}