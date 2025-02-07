
// �Զ����ɣ�/make/npc/make0015

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void do_info();

// ��������ȡ��������
int get_char_picid() { return 7415; }
void do_exchange(string sArg);
void do_inputx(string sArg);
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�Ƶ��ϰ�");

      	set_2( "talk", ([
                "info"  : (: do_info :),
                "do_exchange" : (: do_exchange :),
                "inputx"	: (: do_inputx :),
                "welcome"	: (: do_welcome :),
        ]));
        set_2( "good", ([
                "01" : "/item/31/3150",
                "02" : "/item/31/3151",
                "03" : "/item/31/3152",
                "04" : "/item/32/3280",
                "05" : "/item/32/3281",
                "06" : "/item/32/3282",
                "07" : "/item/32/3283",
                "08" : "/item/32/3284",
                "09" : "/item/32/3285",
		"10" : "/item/stuff/0219",
		"11" : "/item/stuff/0220",
		"12" : "/item/stuff/0221",
		"13" : "/item/stuff/0222",                
		"14" : "/item/stuff/0223",
		"15" : "/item/stuff/0224",         
		"16" : "/item/stuff/0159",      
		"17" : "/item/32/3204",
        ]) );

//        set("level",5);
//        set("legend",({32*2+12,32*40+22}));
	set("mpLegend",([5:({32*2+18,32*40+22}),0:({32*49+18,})]));
	set("mpLegend2",([5:({32*2+20,}),0:({32*49+20,})]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object item;
	object me = this_object(), map;
        int id = getoid(me);
	string tmp;
	"/quest/help"->send_help_tips(who, 53);
	tmp = "";

	if ( who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
        	tmp += sprintf(ESC +HIY+ "��ʧ������\ntalk %x# welcome.1\n",id);
	if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18) )
        	tmp += sprintf(ESC +HIY+ "��Ƶ�ԭ����\ntalk %x# welcome.3\n",id);
	if ( who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20) )
		tmp += sprintf(ESC +HIY+ "��Ƶ�ԭ����\ntalk %x# welcome.3\n",id);
	if ( who->get_level() >= 5 &&!who->get_legend(TASK_40,22) )
		tmp +=  sprintf(ESC +HIY+ "ʳ�����Դ\ntalk %x# welcome.6\n",id);
	if ( !who->get_legend(TASK_49,18) )
		tmp +=  sprintf(ESC +HIY+ "͵�Ե�СҰ��\ntalk %x# welcome.8\n",id);
	if ( who->get_legend(TASK_49,19) && !who->get_legend(TASK_49,20) )
		tmp +=  sprintf(ESC +HIY+ "͵�Ե�СҰ��\ntalk %x# welcome.8\n",id);

        tmp += sprintf(ESC"����ʳ��\nlist %x#\n", id);
        tmp += sprintf(ESC"���䴫��\ntalk %x# info\n", id);
        tmp += ESC"�뿪\nCLOSE\n";
        send_user(who,"%c%s",':',get_name()+": \n    "+"/quest/word"->get_normal_word(this_object())+"\n    �͹٣���Ҫ����ʲô��\n"+ tmp);
}

// ������ס�޴���
void do_info()
{
        object me, who;
        string result, info;
        me = this_object();  who = this_player();
        TASK_MASTER_D->do_info(me, who);
}

void do_exchange(string sArg)
{
	TASK_COLLECT_D->do_exchange(sArg,0015);
}

void do_inputx(string sArg)
{
	object me,who;
	me = this_object(); who = this_player();
	TASK_COLLECT_D->do_inputx(me,who,sArg,0015);
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
        		send_user(who,"%c%s",':',sprintf("%s\n    �߹���ݣ�Ⱥ�����ԡ�������ս�����������У��ҵĸ�ĸ����ȥ����ĸ������ǰ�����ҵ�����Ҳ����Ū���ˣ����²������ף�\n    ��Ը������ҵ���ʧ��������������˵�������Ĺ�����һ��������������ܰ��ҵ����������Ĵ���������һ���úõ����������㡣���ҵ�������Ƚ��������򵼣���˵��������һ�������ľ����ʧ������ô���ˣ�Ӧ����������һ����������\n"ESC"����\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
        case 2:
		if ( who->get_legend(TASK_49, 8) && !who->get_legend(TASK_49, 9))
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->delete_save_2("dssouzuo");
			who->delete_save_2("dssouzuo1");
	        	who->set_legend(TASK_49, 9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,117,"��ʧ������" );
			send_user( who, "%c%s", '!', "�������"HIY"��ʧ������"NOR"����");
		}
               	break;
        case 3:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18) )
        		send_user(who,"%c%s",':',sprintf("%s\n    �����������ĹȺ���Ϫ������һ�ְߵ��ܣ�����ӵ��һ�ֽ�С��Ķ���������Ƶ��ϵȲ��ϣ��Һ�ϣ����������С������ϵȵľƣ�ʹ����С�ƹݵ������һЩ��\n    ������ܸ��Ҵ���3��С����һ�����������ġ�\n"ESC"����\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20) )
        		send_user(who,"%c%s",':',sprintf("%s\n    �����������Ȼ���ţ�˵��������\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
	case 4:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 18) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_NEWBIE_02, 18);
			who->delete_save_2("baqiu_xiaomai");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,44,"��Ƶ�ԭ����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ƶ�ԭ����");	
		}
		break;
	case 5:
		if ( who->get_legend(TASK_NEWBIE_02, 19) && !who->get_legend(TASK_NEWBIE_02, 20) )
		{
			if (TASK_LEGEND_D->check_task_item(who,"С��",3) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->delete_save_2("baqiu_xiaomai");
			who->add_exp(220);
			who->add_potential(10);
			who->set_legend(TASK_NEWBIE_02, 20);
			send_user(who,"%c%s",';',"��Ƶ�ԭ���� ���� 220 Ǳ�� 10");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,44,"" );			

		}
		break;
        case 6:
        	if ( who->get_level()>=5 && !who->get_legend(TASK_40, 22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����Ƶ����ṩ��ʳ�ﶼ�����������ģ����Ϸɵģ������ܵģ�ȫ�������˸��������ģ���֤�������ʡ�\n    ���������Ŀ��˺�Ȼ�Ͷ��ˣ�ԭ����Ӧ�������λ�����е�æ������������˵�Ľ����ϴ󲮲��㼼������Ҫ����ȥ���ҿ����������Ƿ�Ը�Ⲷ���������ң�Ҳ�ý���ȼü֮����\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	break;
        case 7:
        	if ( who->get_level()>=5 && !who->get_legend(TASK_40, 22) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,35,"ʳ�����Դ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ʳ�����Դ");
        	}
        	break;
        case 8:
		if( !who->get_legend(TASK_49, 18) )
        		send_user(who,"%c%s",':',sprintf("%s\n    ����ҵ���Ȼ���󣬵����������ȴ�����ķ����ܶ����Զ��ǰ��Ʒ��������ǳ����������Ϫ�м�СС����������������ƶ������������죬û�뵽����ǰһȺСҰ���ܽ���������͵�ԣ����ҵ�������̣��һ����Ϳ����ȥ���ҽ�ѵ��ѵ��ЩСҰ�ã���Щ�һ�һ�������ִ������Ϫ���\n"ESC"����\ntalk %x# welcome.9\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_49, 19) && !who->get_legend(TASK_49, 20) )
        		send_user(who,"%c%s",':',sprintf("%s\n    ��л����ҽ�ѵ�����ǣ�ϣ�������Ժ�Ҫȥ�ҵ��������海���ˣ������м�ƿ�ҵ�����׾ƣ�����ȥ�����ɣ�С�Ĳ�Ҫ��̫�ࡣ\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
	case 9:
		if( !who->get_legend(TASK_49, 18) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_49, 18);
			who->delete_save("jiudian_yetu");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,46,"͵�Ե�СҰ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"͵�Ե�СҰ��");	
		}
		break;
	case 10:
		if ( who->get_legend(TASK_49, 19) && !who->get_legend(TASK_49, 20) )
		{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;
			TASK_LEGEND_D->give_item(who,"item/stuff/0230",5); 
			TASK_LEGEND_D->task_finish(who);
			who->delete_save("jiudian_yetu");
			who->add_exp(150);
			who->add_potential(20);
			who->add_cash(500);
			who->set_legend(TASK_49, 20);
			send_user(who,"%c%s",';',"͵�Ե�СҰ�� ���� 150 Ǳ�� 20 ��Ǯ 500 �׾� 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,46,"" );			
		}
		break;
	case 99:
		TASK_COLLECT_D->do_talk_exchange( who, me,0015 );
		break;
        }
}
