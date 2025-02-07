
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5805; }

// ���������촦��
void create()
{
        set_name("ţ��");

        set_2( "talk", ([
                "welcome"    : (: do_welcome :),
        ]));
//        set("level", 5);
//        set("legend", ({ 51,53 }));
	set("mpLegend",([0:({32+19,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        int id = getoid( this_object() );
	if ( who->get_legend(TASK_NEWBIE_01, 17) && !who->get_legend(TASK_NEWBIE_01, 18) )
		tmp += ESC "��������¡�\n"  + sprintf( "talk %x# welcome.6\n", id );
	if ( !who->get_legend(TASK_NEWBIE_01, 19) )
			tmp += ESC +HIY+ "ţ��������\n"  + sprintf( "talk %x# welcome.8\n", id );
/*	if ( who->get_level() >= 5 && (!who->get_legend(TASK_NEWBIE_01, 21) || !who->get_legend(TASK_NEWBIE_01, 22)))
	{
		if ( sizeof(tmp) )
			tmp += ESC "ţ���Ŀ��ա�\n"  + sprintf( "talk %x# welcome.10\n", id );
		else
			tmp = ESC "ţ���Ŀ��ա�\n"  + sprintf( "talk %x# welcome.10\n", id );
	}*/
        more_look_menu( who, get_name() + "��\n    ��λ" + NPC_RANK_D->get_respect(who) + "����ʲô��Ϊ��Ч�͵���\n"
        	+ tmp +
                ESC "�����ִ���Ϊ�ҵĻسǵ㡣\n" + sprintf( "talk %x# welcome.1\n", id ) +
                ESC "��������ס��ʲô�ط���\n" + sprintf( "talk %x# welcome.2\n", id ) +
                ESC "���ִ�Ĺ�ͷ�����\n" + sprintf( "talk %x# welcome.3\n", id ) +
                ESC "��������ʲô�ط���\n" + sprintf( "talk %x# welcome.4\n", id ) +
                ESC "�峤�ļ����İ���\n" + sprintf( "talk %x# welcome.5\n", id ) 
                );
}

// �������ƶ�����
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        object who;
        int p, z, x, y, flag;
	object item;
	
        who = this_player();
        
        flag = to_int(arg);
        switch(flag)
        {
        case 1:                               
                if( p = get_jumpin(1, 10) )
                {        
                        who->set_latest_city(00110);    // �سǷ������ִ�(001 #10)
        
                        write_user( who, ECHO "���������ִ�Ϊ�سǵ㡣\n" );
                }
                break;
        case 2:
                send_user( who, "%c%s", ':', get_name() + "��\n    �Ҹղź������������������λ���˼ҡ�\n");                
                break;
        case 3:
                send_user( who, "%c%s", ':', get_name() + "��\n    ��ͷ�����ϲ�����ڴ��ӵľƵ�Ⱦơ�\n");                
                break;
        case 4:
                send_user( who, "%c%s", ':', get_name() + "��\n    �����Ǵ����λ��\n");                
                break;
        case 5:
                send_user( who, "%c%s", ':', get_name() + "��\n    �ϴ峤�ļҾ��ڴ��ӵĶ����ͷ����\n");                
                break;
	case 6:
		if ( !who->get_legend(TASK_NEWBIE_01, 17) || who->get_legend(TASK_NEWBIE_01, 18))
			return ;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �����͹�����ѽ���Ҷ���ȥ����ü����ˣ�һֱ��û�и����ͻ������ɵ������Ҳ���ũ������ɻ��û����ѽ��\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 7:
		if ( !who->get_legend(TASK_NEWBIE_01, 17) || who->get_legend(TASK_NEWBIE_01, 18))
			return ;
		if( !objectp( item = present("����", who, 1, MAX_CARRY) ) || item->is_tieqiu() != 1 )
		{
			send_user(who,"%c%s",'!',"���������?");
			return;	
		}
		item->remove_from_user();
		destruct(item);		
		who->set_legend(TASK_NEWBIE_01, 18);
		who->add_exp(80);
		who->add_potential(5);
		send_user(who,"%c%s",';',"��������� ���� 80 Ǳ�� 5");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,9,"" );		
		break;
	case 8 :		
		if (!who->get_legend(TASK_NEWBIE_01, 19) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ǰ��������ɽ���ԣ���С������һȺ���ˡ���Щ���˽�������ֵǮ�Ķ���ȫ�������ˣ��Һ���ʱ���ӳ�Ѳɽ�����ұ�������Ʒȫ��׷������Ϊ�˴�л���ӳ��������⽫�Լ�����������ɾ�Ǯ�������͸��������������͸����������ڴ��ӵĶ����ͷ�������ϴ峤����һ��\n"ESC"����\ntalk %x# welcome.9\n"ESC"�뿪",me->get_name(),getoid(me)));			
		break;
	case 9:
		if ( who->get_legend(TASK_NEWBIE_01, 19) )
			return ;
		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
		item = new( "/item/98/9884" );
		if ( !item )
			return ;
                p =item->move(who, -1);
                if ( p == 0 )
                {
                	destruct(item); 
                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
                	return ;
                }	
                item->add_to_user(p);
		who->set_legend(TASK_NEWBIE_01, 19);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,10,"ţ������" );
		send_user( who, "%c%s", '!', "�������"HIY"ţ������"NOR"����");		
		break;
//	case 10:
//		if ( who->get_level() < 5 )
//			return ;
//		if (!who->get_legend(TASK_NEWBIE_01, 21) )
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �Ҵ�С����ϰ�䣬����Ϊ�˰���������ǿ׳���õȳ����Ժ�ȥ��ʦѧ�ա��ò����׵��ҳ����Ժ�ȥ�Ҵ�ڵ��Ǹ��������������ҽ��ܸ�ʦ�����������������˵�����̫��ϰ��֮��Ҫ��С��ʼ�������˵ʲôҲ���ϰ��ҽ���ʦ������ʦѧ��һ�������������һ������Ը����Ը�����ȥ˵˵������˵��ϲ�����壬����һ������������͸�����\n"ESC"����\ntalk %x# welcome.11\n"ESC"�뿪",me->get_name(),getoid(me)));			
//		else if (!who->get_legend(TASK_NEWBIE_01, 22))
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��ʦѧ�գ��������һ������Ը��������%s�ܾ��ľ��������������¡�\n"ESC"�뿪",me->get_name(),NPC_RANK_D->get_respect_2(who)));			
//		
//		break;
//	case 11:
//		if ( who->get_level() < 5 || who->get_legend(TASK_NEWBIE_01, 21) )
//			return ;
//		item = new( "/item/98/9885" );
//		if ( !item )
//			return ;
//                p =item->move(who, -1);
//                if ( p == 0 )
//                {
//                	destruct(item); 
//                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
//                	return ;
//                }	
//                item->add_to_user(p);
//		who->set_legend(TASK_NEWBIE_01, 21);
//		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
//		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,11,"ţ���Ŀ���" );
//		send_user( who, "%c%s", '!', "�������"HIY"ţ���Ŀ���"NOR"����");			
//		break;
        }
}
