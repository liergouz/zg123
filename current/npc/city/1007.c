
// �Զ����ɣ�/make/npc/make8007

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define DIPLOMAT_D      "/inh/city/diplomat"

inherit OFFICER;

void do_relation( string arg );

// ��������ȡ��������
int get_char_picid() { return 5102; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���ʹ��");
	set_real_name("����");
        set_city_name("���");

        set_2( "talk", ([
                "relation"      : (: do_relation :),
                "welcome"	: (: do_welcome :),
        ]) );
//	set("level",82);
//	set("legend",({32*27+19}));
 	set("mpLegend",([54:({32*50+7}),80:({32*27+19})]));
 	set("mpLegend2",([35:({32*37+26,}),54:({32*50+9}),80:({32*27+21,}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who ) 
{
	string tmp="";
	object me = this_object();
	
	if ( ( who->get_level() >= 80 && !who->get_legend(TASK_27,19) ) || ( who->get_legend(TASK_27,19) && !who->get_legend(TASK_27,21) ) )
	{
		tmp += sprintf(ESC HIY "��ȶ�֮��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_level() >= 35 && who->get_legend(TASK_37,25) && !who->get_legend(TASK_37,26) )
	{
		tmp += sprintf(ESC HIY "��ܵĿ���\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( ( who->get_level() >=54 && !who->get_legend(TASK_2_00,7) ) || ( who->get_legend(TASK_2_00,7) && !who->get_legend(TASK_2_00,8) ) || ( who->get_legend(TASK_2_00,8) && !who->get_legend(TASK_2_00,9) ) ) 
		tmp += sprintf(ESC HIY "Թ��֮��\ntalk %x# welcome.6\n",getoid(me)); 
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		DIPLOMAT_D->do_look( who, this_object() ); 
	
}
void do_relation( string arg ) { DIPLOMAT_D->do_relation( this_player(), this_object(), arg ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,item2,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������̰���ʱ�򱻷���°����һ���ǳ������Ķ�Ѩ����Ȼ�������Щͭ��ʬ���˸�������Ū���Ǳ������������Һú�����һ���ϵ������˳�����֮�����һ�������Ƕ���������������ľ�ɫ��Ȼ��������������ڴ������Ǹ��ط�������ȶ�������������ɽ��ˮ����������ǰ��������ְ�����ޣ�����ʱ�������ٻ�����������ǰȥ������Դ���ǰȥ�ٴ�̽��һ���𣬻���˳�����ɱ10ֻͭ��ʬ�Գ����������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_27,19) && !who->get_legend(TASK_27,20) )
 			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ�����ʱֻ��һʱ��ʹ֮��Ļþ��𣿰�����������Ī����ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_27,20) && !who->get_legend(TASK_27,21) )
 			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ԭ����ʱ�������治�鰡��������Ϫ��Ȫ������������кѩ���񣬻������䣬������ʯ��Ω��ΩФ���鶯���棬�鲼�İ¡��������������Ĵ˼䡣�Ⱥ���⣬ɴ�����١���Ϊ�顢��֮��������֪��ʱ��ʹ������̤�˶�����\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 2:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,19) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->delete_save("qgsjtongjiasi");
        		who->set_legend(TASK_27,19);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,22,"��ȶ�֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ȶ�֮��");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_27,20) && !who->get_legend(TASK_27,21) )
        	{
			who->delete_save("qgsjtongjiasi");
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_27,21);
			who->add_exp(44000);
			who->add_potential(635);
			who->add_cash(43500);
			send_user(who,"%c%s",';',"��ȶ�֮�� ���� 44000 Ǳ�� 635 ��Ǯ 43500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,22,"" );
        	}
        	break;
        case 4:
        	if ( who->get_level() >= 35 && who->get_legend(TASK_37,25) && !who->get_legend(TASK_37,26) )
 			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ҳ�þ�û�м����ұ������һ���ˣ����ڴ�����\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
        case 5:
        	if ( who->get_level() >= 35 && who->get_legend(TASK_37,25) && !who->get_legend(TASK_37,26) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_37,26);
			who->add_exp(2500);
			who->add_potential(60);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"�����Ÿ����ʹ�� ���� 2500 Ǳ�� 60 ��Ǯ 2000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,44,"" );
        	}
        	break;
        case 6:
        	if ( who->get_level() >=54 && !who->get_legend(TASK_2_00,7) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֪���ع��и���὾�Ӫ����˵�������ĵܵ�����ı�Ѷ�˽��ľ�Ӫ�����Ͳ��ϣ���˽���˿ڽ�ȥ�����������ҵ���Թ�����أ���������������ܷ�ȥ��������Թ��֮�飬���ҿ����������ȣ��������������ˣ������ѻ귨��������������ɱ��Թ����ܵõ�Թ��֮���ˡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_2_00,7) && !who->get_legend(TASK_2_00,8) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �㻹û�д���Թ��֮��ô���浣�İ���\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_2_00,8) && !who->get_legend(TASK_2_00,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л��λӢ�ۣ������ڿ���������������Թ���ˡ���\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 7:
        	if ( who->get_level() >=54 && !who->get_legend(TASK_2_00,7) ) 
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			item = new("/item/98/0238");
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
        		who->set_legend(TASK_2_00,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,103,"Թ��֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Թ��֮��");
       		}
        	break;
        case 8:
        	if ( who->get_legend(TASK_2_00,8) && !who->get_legend(TASK_2_00,9) )
        	{
			if( !objectp( item = present("�ѻ귨��", who, 1, MAX_CARRY) ) )
			{
				send_user(who,"%c%s",'!',"����ѻ귨����?");
				return;	
			}
			if( !objectp( item2 = present("Թ��֮��", who, 1, MAX_CARRY) ) )
			{
				send_user(who,"%c%s",'!',"���Թ��֮����?");
				return;	
			}
			item->remove_from_user();
			destruct(item);	
			item2->remove_from_user();
			destruct(item2);	
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_2_00,9);
			who->add_exp(9800);
			who->add_potential(500);
			who->add_cash(11600);
			send_user(who,"%c%s",';',"Թ��֮�� ���� 9800 Ǳ�� 500 ��Ǯ 11600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,103,"" );
		}
        	break;

        case 99:	
		DIPLOMAT_D->do_look( who, me); 
        	break;
        }
}