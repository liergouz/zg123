
// �Զ����ɣ�/make/npc/make0001

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// �����������ϰ�
int is_banker() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 5301; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�����ϰ�");
        set_real_name("�ֿ����Ա");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",49);
//	set("legend",({32*13+7})); 
	set("mpLegend",([50:({32*13+7}),]));
	set("mpLegend2",([50:({32*13+9}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_13,7) ) || ( who->get_legend(TASK_13,7) && !who->get_legend(TASK_13,9) ) )
		tmp =  sprintf(ESC HIY "���µ�Ԥ��\ntalk %x# welcome.1\n",getoid(this_object()));
	
        send_user( who, "%c%c%w%s", ':', 1, get_char_picid(), 
                sprintf("%s��\n    "+"/quest/word"->get_normal_word(this_object())+"\n"
                        ESC "����ʹ�õ���\npawn %x# 1\n"
                        ESC "��Ҫ�����ҵĵ���\npawn expand %x# 0\n"
                        + tmp +
                        ESC "��ֻ����㿴��\nCLOSE\n", who->get_name(), getoid(this_object()), getoid(this_object()) ) );
	"/quest/help"->send_help_tips(who, 4);                        
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
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_13,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ˮ����Ԥ�ԣ����ú���֣����һ������������ճ�������������֪��������ʲôΣ���˼�����飬����Ӧ�÷�����δȻ����ֹ���ĳ����������û�´�Ļ���Ӧ������������������Ƿ�Ը��ǰȥ�����µ��������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,7) && !who->get_legend(TASK_13,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ʱ�����ǲ����֣�������ﾭ�����Է���һ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,8) && !who->get_legend(TASK_13,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ҳ���õ�����Ԥ�������Ǽ٣����԰����Ĺ������ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_13,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,13,"���µ�Ԥ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���µ�Ԥ��");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_13,8) && !who->get_legend(TASK_13,9) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64074",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,9);
			who->add_exp(5600);
			who->add_potential(220);
			who->add_cash(4800);
			send_user(who,"%c%s",';',"���µ�Ԥ�� ���� 5600 Ǳ�� 220 ��Ǯ 4800 ̤�Ƽ�ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,13,"" );
        	}
        	break; 
  
        }
}