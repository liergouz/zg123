
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5601; }

// ���������촦��
void create()
{
        set_name("����ʿ");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",77);
//        set("legend",({32*25+17}));  
 	set("mpLegend",([75:({32*25+17})]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
        tmp += CHAIN_D->get_chain_menu(who,me);
        if ( who->get_level() >= 75 && !who->get_legend(TASK_25,17) ) 
		tmp += sprintf(ESC HIY "��ı�ײ�\ntalk %x# welcome.1\n",getoid(me)); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0311))
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
	       	if ( who->get_level() >= 75 && !who->get_legend(TASK_25,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������ڵ���������У���ȶ��Ǳ�ÿ���������죬����ٲ��������Ļ����ܿ����Ǻ�����������������¡���Ϊ���������ҿɲ��ܶ����²��Ų��ʣ��ҿ�����¶�����������Ҫ�Ӻ������Ǻ�������ǰ���Ѿ�������µ�����ȥ�����²��������������Ұ�������������������������겻������ȥ�������������������ȥ��������£�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >= 75 && !who->get_legend(TASK_25,17) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0119");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!',"��Я������Ʒ̫����");	
        			return ;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_25,17);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,21,"��ı�ײ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ı�ײ�");
        	}
        	break;       
        }
}  