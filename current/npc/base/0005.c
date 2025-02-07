
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 4; }
// ���Լ���do_look����
int is_self_look() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 5405; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("���ߵ��ϰ�");
        set_city_name("���ִ�");

        set_2( "good", ([
                "01" : "/item/60/0005",
                "02" : "/item/61/0005",
                "03" : "/item/65/0005",
                "04" : "/item/66/0005",
                "05" : "/item/88/0005",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level", 0);
//        set("legend", ({ 32+5,32+7 }));
//	set("mpLegend",([0:({32+5, }),]));
	set("mpLegend2",([0:({32*48+5,32*48+7,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 40);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "�������ʺ��ҵ�װ����\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	if (who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
	{
		result = result + sprintf( ESC  +HIY+ "��������\ntalk %x# welcome.1\n", getoid(me) );
	}
	if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
	{
		result = result + sprintf( ESC  +HIY+ "Ѱ������\ntalk %x# welcome.3\n", getoid(me) );
	}
	if (who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
	{
		result = result + sprintf( ESC  +HIY+ "Ѱ������\ntalk %x# welcome.9\n", getoid(me) );
	}
	if ( (who->get_legend(TASK_48, 7) && !who->get_legend(TASK_48, 8)) )
	{
		result = result + sprintf( ESC  +HIY+ "��������\ntalk %x# welcome.6\n", getoid(me) );
	}
	if (who->get_legend(TASK_NEWBIE_01, 7) && !who->get_legend(TASK_NEWBIE_01, 8))
	{
		result = result + sprintf( ESC  +HIY+ "��������\ntalk %x# welcome.8\n", getoid(me) );
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
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��ѽ�����������ϰ����ҿ�ν��һ�ļ���ѽ����Ҳ����������������뷨����л����������˵�ͣ������ɣ��Һ�����Լ��ʱ��ú�̸̸���ú���ı���ɣ�\n"ESC"�������\ntalk %x# welcome.2\n",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
		{
			if(who->get_gender()==1) item = new("item/60/0001");
				else item = new("item/61/0001");
			if ( !item ) break;
			if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
			{
                                p =item->move(who, -1);
                                item->add_to_user(p);			
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_48, 5);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,102,"" );
				who->add_cash(500);
				who->add_exp(120);
				who->add_potential(20);
				send_user(who,"%c%s",';',sprintf("�������� ���� 120 Ǳ�� 20 ��Ǯ 500 �����·� 1"));
				me->do_welcome(3);
			}
			else
			{
                                	destruct(item); 
                                	send_user( who, "%c%s", '!', "������û�п�λ��");				
			}
		}
		break;
	case 3:
		if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Ҫ������Ѱ�����յĴ̼��������ȵ�ȥ�ҵ�һ�Ųر�ͼ���������Ųر�ͼ������ܼ���Ѱ�������ˣ���������ҵ��ر�ͼ�����ٻ�������ɣ��һ��������һ��������\n"ESC"��ȡ����\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),getoid(me)));
		}
		break;
	case 4:
		if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
		{	//�򿪱���
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_48, 6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,103,"Ѱ������" ); 
			send_user( who, "%c%s", '!', "�������"HIY"Ѱ������"NOR"����");                       
		}
		break;
	case 5 :
		if ( who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
		{
			if( !objectp( item = present("�ر�ͼ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
			{
				send_user(who,"%c%s",'!',"��Ĳر�ͼ��?");
				return;	
			}
	//		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���������ϵĲر�ͼһֱ�����ߣ���Ұ����ͻ���Ǹ�����ȥ���ң������Ǹ��ݴ��88��62�����ҵ����������ڱ��ˡ���εĽ����ɷ���ˣ����ҵ������ȥ��ҩ���ϰ壬������㽱���ġ�\n"ESC"��ȡ����\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),getoid(me)));
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 7);
			who->add_exp(180);
			who->add_potential(40);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"Ѱ������ ���� 180 Ǳ�� 40 ��Ǯ 1000");
//			send_user( who, "%c%c%c%w%c", 0x51, 2, 1,TID_NEWBIE_01,"" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,103,"" );
			me->do_welcome(6);
		}
		break;
	case 6:
		if (!who->get_legend(TASK_48, 7) )
			return ;		
		if( !objectp( item = present("�ر�ͼ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			send_user(who,"%c%s",'!',"��Ĳر�ͼ��?");
			return;	
		}
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���������ϵĲر�ͼһֱ�����ߣ�����Ϫ��ͻ���Ǹ����Ϻú����ң������Ǹ��ݴ��88��62�����ҵ������Ϳ����ڱ��ˣ���Ȼ�����������ҵ��ر�ͼ�Ľ�������࣬���Ƿ�Ը����ս�أ����ҵ������ȥ��ҩ���ϰ壬���������Ҫ�Ķ�����\n    �����������alt+w���������Խ��棬��ʹ����������Ϳ��Կ��ٻص����ִ�Ŷ��\n"ESC"��ȡ����\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 7:
		if (!who->get_legend(TASK_48, 7))
			return ;		
		if( !objectp( item = present("�ر�ͼ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			send_user(who,"%c%s",'!',"��Ĳر�ͼ��?");
			return;	
		}
		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
		who->set_legend(TASK_48, 8);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,104,"��������" );
		send_user( who, "%c%s", '!', "�������"HIY"��������"NOR"����");
		break;		
	case 8:
		if ( (who->get_legend(TASK_NEWBIE_01, 7) && !who->get_legend(TASK_NEWBIE_01, 8)))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Ϊʲô����ȥ�ڱ��أ����ڵ��ı��ｻ��ҩ���ϰ壬���õ����ٽ���ѽ��\n"ESC"�뿪",me->get_name(),));
		break;
	case 9:
		if (who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
		{
			if( !objectp( item = present("�ر�ͼ", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
			{
				send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���Ҳ������Ųر�ͼ���ǲ����ǳ���ͷ͵͵�������ˣ������ɣ�����ȥ���ң���ϸ�㣡\n"ESC"�뿪",me->get_name()));
			}
			else 
				send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��ô��ͻ������ţ��Եģ������ϵĲر�ͼ������������Ҫ�����ţ��ɵò���\n"ESC"�������\ntalk %x# welcome.5\n",me->get_name(),getoid(me)));
		}
		break;
	case 99:
		result = sprintf("%s��\n    ��֪��ȥ��������ĵ�װ�����Ҹ�������ˡ�\n"
			"    �����ִ�ͳ����㶼����ͨ�õ�װ�������ִ嶼��0���ģ����������Ƿ���10����װ����\n"
			"    ��"HIR" �Թ� "NOR"������"HIR" �һ�Դ "NOR"��װ����\n"
			"    "HIR" �ܹ� "NOR"��"HIR" ������ "NOR"װ����ר�ŵꣻ\n"
			"    "HIR" ��ɽ "NOR"��װ��������"HIR" ��� "NOR"����\n"
			"    ��"HIR" ���� "NOR"�Ϳ����ҵ�"HIR" ���� "NOR"��װ��ר�ŵꣻ\n"
			"    ��"HIR" �ع� "NOR"����"HIR" ����ɽ "NOR"��װ����\n"
			"    "HIR" éɽ "NOR"��װ�����Ե�"HIR" ��� "NOR"ѰѰ����\n"
			"    ���"HIR" ������ "NOR"��װ����ֻҪ��"HIR" κ�� "NOR"������ҵ��ˡ�"
			"\n", me->get_name() );
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
		break;		
	}
}	               
