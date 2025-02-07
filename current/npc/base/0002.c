
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 5; }
// ���Լ���do_look����
int is_self_look() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 5402; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�ӻ����ϰ�");
        set_city_name("���ִ�");

        set_2( "good", ([
                "01" : "/item/std/0401",
                "02" : "/item/std/0407",
                "04" : "/item/std/0409",
                "05" : "/item/std/0413",
                "06" : "/item/std/0591",
                "07" : "/item/32/3231",
                "08" : "/item/98/9871",
                "09" : "/item/std/9808",
		"10" : "/item/std/9819",
		"11" : "/item/std/9820",
		"12" : "/item/49/4900",
		"13" : "/item/std/0410",
		"14" : "/item/08/0010",
		"15" : "/item/08/0011",
		"16" : "/item/08/0012",
		"17" : "/item/44/4403",
		"18" : "/item/44/4406",
//		"19" : "/item/44/4405",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 0);
//        set("legend", ({ 32*41+11 }));
	set("mpLegend",([5:({32*49+15}),]));
	set("mpLegend2",([0:({32*48+14,32*49+17}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result="";
	"/quest/help"->send_help_tips(who, 41);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
	{
		result = result + sprintf( ESC +HIY+  "�ɸ봫��\ntalk %x# welcome.1\n", getoid(me) );
	}
//	if ( !who->get_legend(TASK_NEWBIE_01, 14) )
	if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
	{
		result = result + sprintf( ESC  +HIY+ "������ϰ������\ntalk %x# welcome.3\n", getoid(me) );
	}	
	if ( who->get_legend(TASK_NEWBIE_01, 14) && !who->get_legend(TASK_NEWBIE_01, 15) )
	{
		result = result + sprintf( ESC  +HIY+ "������ϰ������\ntalk %x# welcome.5\n", getoid(me) );
	}
	if ( who->get_level() >=5 && !who->get_legend(TASK_49, 17) )
	{
		result = result + sprintf( ESC +HIY+ "���ϴ����ķ���\ntalk %x# welcome.8\n", getoid(me) );
	}
/*	if ( who->get_level() >=5 && !who->get_legend(TASK_41, 11) )
	{
		result = result + sprintf( ESC "������\ntalk %x# welcome.6\n", getoid(me) );
	}*/

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
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
//		if ( !who->get_legend(TASK_NEWBIE_01, 12)||who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �ȡ��ȡ��ȡ��������ˣ���ÿ�춼������ݳ��������ø���������֪����˭�����������ҵ��ֵܣ������ܹ����Ժ�����л���������ģ���������ı���ɣ����ӡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 2:
//		if ( !who->get_legend(TASK_NEWBIE_01, 12)||who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
		{
			if( !objectp( item = present("������", who, 1, MAX_CARRY) ) || item->is_huodan() != 1 )
			{
				send_user(who,"%c%s",'!',"��ĳ�������?");
				return;			
			}	
			item->remove_from_user();
			destruct(item);			
			item = new("/item/08/0010");
			p =item->move(who, -1);
                        item->add_to_user(p);	
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 14);	
			who->add_exp(290);
			who->add_potential(20);
			who->add_cash(200);
			send_user(who,"%c%s",';',"�ɸ봫�� ���� 290 Ǳ�� 20 ��Ǯ 200 ��ͨ������ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,106,"" );
			me->do_welcome(3);
		}
		break;
	case 3:
//		if ( who->get_legend(TASK_NEWBIE_01, 14) )
//			return;		
		if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ǰЩ����������ϰ�����������һ����������ϧ������û�У������Ҵ�Ӧ���������ҵ����������Ҵ�����������Ϣ������Ϫ�����ֽ���С������С�۷�Ķ���������ϴ������������ܶ�������˵�����ǵ������е�ǿ��������һ��ҪС��Ŷ����Ȼ���Ƚ����ѵ�������һ�����Ƚϸߵı���Ŷ�����õ�������ֱ�ӽ���������ϰ�����ˡ�\n    �����������alt+w���������Խ��棬��ʹ����������Ϳ��Կ��ٻص����ִ�Ŷ��\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 4:
//		if ( who->get_legend(TASK_NEWBIE_01, 14) )
//			return;
		if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_48, 15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,107,"������ϰ������" );
			send_user( who, "%c%s", '!', "�������"HIY"������ϰ������"NOR"����");
		}
		break;	
	case 5:
		if ( who->get_legend(TASK_NEWBIE_01, 14) && !who->get_legend(TASK_NEWBIE_01, 15) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ������̫ǿ������ɵøϿ�Ŷ���Ҵ�Ӧ��������ϰ壬�ɲ���ʧ��������\n"ESC"�뿪",me->get_name(),));
		break;
        case 6:
        	if ( who->get_level() >=5 && !who->get_legend(TASK_41,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������������Ķ��������Ѿ�ȫ���ռ����ˣ�������ȫ��������������ˣ����ܸ����˹�ȥ��\n    �������ס��������ȥ�Ĵ�·�Աߣ������Ϻ��Ǻܺõ��ھ��أ��������ǰ���Ǹ������߹�����Ӧ�ú����׾��ҵ����ģ�����ûȥ��Ҳ��Ҫ������������·���ߣ������������Ŷ����ķ��ӣ�������������ˡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(), getoid(me)));
        	break;
	case 7:
        	if ( who->get_level() >=5 && !who->get_legend(TASK_41,11) )
        	{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/98/0201",1);
        		who->set_legend(TASK_41,11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,33,"������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������");
        	}
        	break;			
        case 8:
		if( who->get_level() >=5 && !who->get_legend(TASK_49, 15) )
        		send_user(who,"%c%s",':',sprintf("%s\n    �Ҵ�С�Ͱ��Է��ۣ�һ��������û���������������Ȼ��С�ˣ���ζȴһֱû�䡣ǰЩ����һλ�����ѴӰ�����������Ҵ�����ʮ�޷��ۣ��Ұ������ղ����Ĺȵ�ľ��������Ĺ������кܶ�С���ϻ����һֱ�ܵ������ǻ�ȥ͵���ҵķ��ۣ���Ҫ���п�ȥ���Ҹɵ���ֻС���ϣ������Ҿ��ܰ����ˡ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_49, 16) && !who->get_legend(TASK_49, 17) )
        		send_user(who,"%c%s",':',sprintf("%s\n    ���Ѿ��ɵ�С�����ˣ�̫���ˣ������ڷ����ˣ���ЩǮ����лл��ģ�ʡ�ŵ㣬��һ�λ����ˡ�\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
	case 9:
		if ( who->get_level() >=5 && !who->get_legend(TASK_49, 15) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_49, 15);
			who->delete_save("xsc_mayi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,45,"���ϴ����ķ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ϴ����ķ���");	
		}
		break;
	case 10:
		if ( who->get_legend(TASK_49, 16) && !who->get_legend(TASK_49, 17) )
		{
			TASK_LEGEND_D->task_finish(who);
			who->delete_save_2("xsc_mayi");
			who->add_exp(150);
			who->add_potential(25);
			who->add_cash(800);
			who->set_legend(TASK_49, 17);
			send_user(who,"%c%s",';',"���ϴ����ķ��� ���� 150 Ǳ�� 25 ��Ǯ 800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,45,"" );			
		}
		break;
	}
}
