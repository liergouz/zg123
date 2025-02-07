
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;
void do_welcome(string arg);


// ��������ȡ��������
int get_char_picid() { return 5909; }

// ���������촦��
void create()
{
        set_name("��ͯС��");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",39);
//        set("legend",({32*10+8}));
 	set("mpLegend",([35:({32*10+8}),]));
 	set("mpLegend2",([35:({32*10+10}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 35 && !who->get_legend(TASK_10,8)) || (who->get_legend(TASK_10,8)&&!who->get_legend(TASK_10,10)) ) 
		tmp += sprintf(ESC HIY "��ʧ�ĺ�����\ntalk %x# welcome.1\n",getoid(this_object())); 
        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0701))
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
        	if (who->get_level() >= 35 && !who->get_legend(TASK_10,8))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҹ���̫��������ͯû���죬��Ū���˼������ӣ���Ȼ��ү����û������ң������Ͼ����ھΣ���Ҫ�ֲ��Լ��Ĺ���\n    ��˵̩ɽ�ĺ����������ӣ�����ȥ��3����������̩ɽʵ��̫�ն���һ��С���ӣ�����ֻ��ǰ�������/��㣬�ҿ���һ�������˵ã��ܲ��ܰ���ң�ȥ������3���������أ�\n    ������̫������ȥ������ֱ�ӵ�̩ɽ�ˡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_10,8) && !who->get_legend(TASK_10,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ȼ��ү�ͷ��˲�������ң������һ������ֲ��Լ��Ĺ�����������һ����\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_10,9) && !who->get_legend(TASK_10,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл%s��������ү�ͷ��˿϶�����ҵģ��Ǻǣ��濪�ġ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
        case 2:
        	if(who->get_level() >= 35 && !who->get_legend(TASK_10,8))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_10,8);
        		who->delete_save_2("qtheiqizi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,11,"��ʧ�ĺ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ʧ�ĺ�����");
        	}
        	break;
       case 3:
        	if ( who->get_legend(TASK_10,9) && !who->get_legend(TASK_10,10) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		who->delete_save_2("qtheiqizi");
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_10,10);
			who->add_exp(4000);
			who->add_potential(115);
			who->add_cash(3000);
			send_user(who,"%c%s",';',"��ʧ�ĺ����� ���� 4000 Ǳ�� 115 ��Ǯ 3000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,11,"" );
        	}
        	break;        
        }
}