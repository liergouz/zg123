
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 0252; }

// ���������촦��
void create()
{
        set_name("�װ���");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*30+11,32*30+14,32*30+17,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me=this_object();
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_30,10) && !who->get_legend(TASK_30,11) )
	{
		tmp += sprintf(ESC HIY "�����Ƿ�\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_legend(TASK_30,11) && !who->get_legend(TASK_30,12)) || (who->get_legend(TASK_30,12) && !who->get_legend(TASK_30,14)) )
	{
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_legend(TASK_30,14) && !who->get_legend(TASK_30,15)) || (who->get_legend(TASK_30,15) && !who->get_legend(TASK_30,17)) )
	{
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_legend(TASK_30,17) && !who->get_legend(TASK_30,18) )
	{
		tmp += sprintf(ESC HIY "ѱ�����\ntalk %x# welcome.1\n",getoid(me));
	}
        send_user( who, "%c%s", ':', sprintf( "%s��\n    %s\n", get_name(),TASK_COLLECT_D->get_talk_string(0611))
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
        	if ( who->get_legend(TASK_30,10) && !who->get_legend(TASK_30,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ʲô�ˣ�Ҳ���������Ǵ������?\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,11) && !who->get_legend(TASK_30,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ӱ����ؾ����Ҽҵģ���ô�ˣ�Ҫͬ�Ҷ��������㣬���н�����Ĺ�Ĳ��30��ǹٸ��30������ʯٸ�����������б����ȴ������ǵ�������ͬ��˵����������\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_30,12) && !who->get_legend(TASK_30,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ҵ��£������˵㣡\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_30,13) && !who->get_legend(TASK_30,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������С�ӻ�û������\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,14) && !who->get_legend(TASK_30,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������������Ҫ���ģ���ɱ���������£��������ˣ���������������Ĺ�Ĳ㶫������Ϊ������֮����\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_30,15) && !who->get_legend(TASK_30,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������ȥ���Ҵ���鷳�����ֿ�ԣ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_30,16) && !who->get_legend(TASK_30,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ô���ܻ��ţ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_30,17) && !who->get_legend(TASK_30,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������С�ӣ��������������ܺͰ��ǽ�ɣ���û�д������ˡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
 
        	break;
        case 2:
        	if ( who->get_legend(TASK_30,10) && !who->get_legend(TASK_30,11) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,11);
			who->add_exp(65000);
			who->add_potential(780);
			who->add_cash(51000);
			send_user(who,"%c%s",';',"�����Ƿ� ���� 65000 Ǳ�� 780 ��Ǯ 51000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,36,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_30,11) && !who->get_legend(TASK_30,12) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,12);
        		who->delete_save("lbtqianyong");
        		who->delete_save("lbtgongjsy");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,37,"�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������");
        	}
        	break; 
        case 4:
        	if ( who->get_legend(TASK_30,13) && !who->get_legend(TASK_30,14) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,14);
        		who->delete_save("lbtqianyong");
        		who->delete_save("lbtgongjsy");			
			who->add_exp(67000);
			who->add_potential(790);
			who->add_cash(53000);
			send_user(who,"%c%s",';',"������� ���� 67000 Ǳ�� 790 ��Ǯ 53000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,37,"" );
			me->do_welcome(1);
        	}
        	break;   
        case 5:
        	if ( who->get_legend(TASK_30,14) && !who->get_legend(TASK_30,15) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,38,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break; 
        case 6:
        	if ( who->get_legend(TASK_30,16) && !who->get_legend(TASK_30,17) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64157",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,17);
			who->add_exp(66000);
			who->add_potential(790);
			who->add_cash(52000);
			send_user(who,"%c%s",';',"�������� ���� 66000 Ǳ�� 790 ��Ǯ 52000 ӫ��Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,38,"" );
			me->do_welcome(1);
        	}
        	break;   
        case 7:
        	if ( who->get_legend(TASK_30,17) && !who->get_legend(TASK_30,18) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,18);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,39,"ѱ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ѱ�����");
        	}
        	break; 
        }
}