
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5802; }

// ���������촦��
void create()
{
        set_name( "�ƴ���" );

        set_2( "talk", ([
                "welcome"         : (: do_welcome :),
        ]));

//        set("level", 8);
//        set("legend", ({ 32*2+28 }));
//	set("mpLegend",([5:({32*2+28,}),]));
        setup();
        if( !clonep(this_object()) ) return;
	"npc/task/0101"->create_npc();
}

// �������Ի�����
void do_look( object who )
{
        string tmp="";

//	if ( who->get_level() >=5 && !who->get_legend(TASK_NEWBIE_02, 30) )
//		tmp = sprintf(ESC"����֮ս\ntalk %x# welcome.1\n",getoid(this_object()));
        tmp += CHAIN_D->get_chain_menu(who,this_object());
	send_user(who,"%c%s",':',get_name()+":\n    ��������һ�죬Ҳû���ϼ����㣬���ܺͼ����йذɣ������������ԡ�\n"+tmp+ESC"�뿪");
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag;
	object who;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
//        switch(flag)
//        {
//	case 1:
//		if ( who->get_level() >=5 &&!who->get_legend(TASK_NEWBIE_02, 28) )
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �����������֮ʿ����ô���������ʱ�̵����ˣ�����Ϊ��ÿ���������µ�������㣬��ʵ����һ����̽����������̽�ö�������ӵĲ���֮������������⣬�Լ�����¶�����������������æ�����ҰѲ��������ִ�������ڵĶ�������ӻ��У��һ������ı��ꡣ\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
//		else if ( who->get_legend(TASK_NEWBIE_02, 28)&&!who->get_legend(TASK_NEWBIE_02, 29) )
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��Ȼ�������˵Ķ�ԣ����Ȼ����ɱ�����������������ȥ���ԣ�������ο��Գɹ���\n"ESC"�뿪",me->get_name()));			
//		else if ( who->get_legend(TASK_NEWBIE_02, 29)&&!who->get_legend(TASK_NEWBIE_02, 30) )
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �ҹ�Ȼû�п����ˣ���ô�������ɱ�����ˣ������Ժ����ܳ�Ϊ���ǵ�һԱ���ţ��Ҽǵ����ˣ���ɫ�������ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),getoid(me)));
//		break;
//	case 2:
//		if ( who->get_level() >=5 &&!who->get_legend(TASK_NEWBIE_02, 28) )
//		{	
//			who->set_legend(TASK_NEWBIE_02, 28);
//			//send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
//			//send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,22,"����֮ս" ); 
//			send_user( who, "%c%s", '!', "�������"HIY"����֮ս"NOR"����");    
//       		}
//		break;
//	case 3:
//		if ( who->get_legend(TASK_NEWBIE_02, 29)&&!who->get_legend(TASK_NEWBIE_02, 30) )
//		{
//			who->set_legend(TASK_NEWBIE_02, 30);
//			who->add_exp(600);
//			who->add_potential(50);
//			who->add_cash(1500);
//			send_user(who,"%c%s",';',"����֮ս ���� 600 Ǳ�� 50 ��Ǯ 1500");
//			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,22,"" );
//		}
//		break;
//	}
}
