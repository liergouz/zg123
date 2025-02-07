
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5401; }

// ���������촦��
void create()
{
        set_name("ҩ����");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",45);
//        set("legend",({32*11+27}));
	set("mpLegend",([45:({32*11+27}),]));
	set("mpLegend2",([45:({32*11+29}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 45 && !who->get_legend(TASK_11,27)) || (who->get_legend(TASK_11,27)&&!who->get_legend(TASK_11,29)) ) 
		tmp += sprintf(ESC HIY "�о�ʯԪ��\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    �⿿����ҩ�Ŀ���׬����Ǯ���ҵ�����İ취��\n", get_name())
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
        	if ( who->get_level() >= 45 && !who->get_legend(TASK_11,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ҪһЩ�ᷢ���ʯͷ�������о����Ƿ����ԭ�򣬿�������һζ�õ�ҩ�ġ���ȥ������5�����ɡ��ڳ�����ص��������ϻ������ҵ���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,27) && !who->get_legend(TASK_11,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ʵ���Ҳ���������Ҳû�취�ˣ���������ϣ�����ܾ�����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_11,28)&&!who->get_legend(TASK_11,29) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����о��ɹ�����һ�����޳�������Щҩ�ĵģ���ʱ����Ҳ������ȥ����׬��СǮ��\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
 	      	break;
     
        case 2:
        	if( who->get_level() >= 45 && !who->get_legend(TASK_11,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,27);
        		who->delete_save_2("yanjiushitou");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,19,"�о�ʯͷ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�о�ʯͷ");
        	}
        	break;

        case 3:
        	if( who->get_legend(TASK_11,28) && !who->get_legend(TASK_11,29) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�����ʯͷ",5) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,29);
        		who->delete_save_2("yanjiushitou");
			who->add_exp(5000);
			who->add_potential(160);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"�о�ʯͷ ���� 5000 Ǳ�� 160 ��Ǯ 4000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,19,"" );
        	}
        	break;
        }
}