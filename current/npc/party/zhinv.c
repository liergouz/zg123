#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>
#include <effect.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 7302; }
void do_visit(string arg);

// ���������촦��
void create()
{
        set_name("֯Ů");
        set_2( "talk", ([
                 "visit"         : (: do_visit :),
        ]) );
        setup();
	set("mpLegend",([0:({32}),]));
        if ( !clonep(this_object()) )
        	return ;
        if (MAIN_D->get_host_type()==2)		//̨�����
        	call_out("go_there",2);
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	int tId,i,size;
	int id = getoid(me);
	int iTime=time();
	object *team;
	if (MAIN_D->get_host_type()==2)
		return ;
	if ( who->get_gender() != 1 )
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���������ˮ�ϣ�ҹҹ�������񳯡�\n"
		ESC"��Ϧ�����Ե\ntalk %x# visit.1\n"
		ESC"�뿪",me->get_name(),id));
/*	if ( who->get_gender() != 1 && who->get_save_2("qixi.flag")==12)
	{
		tId = who->get_team_id();
		team = who->get_team();
	
	        if( ( size = sizeof(team) ) > 2 )
	        {
	                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "��\n    ��Ҫ��Щ����ɵ�������\n"ESC"�뿪" );
	                return;
	        }
	        if( !tId || ( size = sizeof(team) ) != 2 )
	        {
	                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "��\n    �����Ե���أ����ǸϿ��ҵ���Ե������������ɣ�\n"ESC"�뿪" );
	                return;
	        }
		for (i=0;i<size;i++)		
		{
			if (!inside_screen_2(me, team[i]))
			{
	                	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "��\n    ������һ������أ�����ôû�п����������ǵ�������һ�������Ұɣ�\n"ESC"�뿪" );	
				return;
			}
		}
		if (team[0]->get_save_2("qixi.together") != team[1]->get_save_2("qixi.together"))
			return;
		for (i=0;i<size;i++)
		{
			if ( team[i]->get_gender() != 1 )
				send_user(team[i],"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��������ɵ���̫��л�����ˣ����ǻ��к󱨵ġ�\n"
				ESC"�������\ntalk %x# visit.3\n"
				ESC"�뿪",me->get_name(),id));
			if ( team[i]->get_gender() == 1 )
				send_user(team[i],"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��������ɵ���̫��л�����ˣ����ǻ��к󱨵ġ�\n"
				ESC"�������\ntalk %x# visit.4\n"
				ESC"�뿪",me->get_name(),id));
		}
	}*/
}

void do_visit(string arg) { __FILE__->do_visit_call(this_object(),arg); }

void do_visit_call( object me,string arg )
{
	int flag, p,iTime,i,size,id,x,y,z,level,tId;
       	object who, item,*nTeam,member,npc,map,item_qx1,item_qx2,*team;
       	string name,*nTmp,tmp;
	mixed *mxTime;  

	
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
	if ( who->get_save_2("qixi.finish") == 1 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ�������Ϧ�����ˣ�����������\n"
		ESC"�뿪",me->get_name()));
		return ;	
	}
        switch(flag)
        {
        case 1:
		if ( who->get_gender() == 1 ) return ;

		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��Ը��������������Ը�⣬��ô�������������ɣ��ҵ����������ͬ��������ԣ�Ȼ��һ��ȥ�����ϣ����������һ�еġ�\n"
		ESC"��ȡ����\ntalk %x# visit.2\n"
		ESC"�뿪",me->get_name(),id));
        	break;
        case 2:
		if ( who->get_gender() == 1 ) return ;
//        	if ( who->get_save_2("qixi.receive") == 1 )
		if ( objectp( item = present("��Ϧ��õ��", who, 1, MAX_CARRY) ) || objectp( item = present("��Ϧ��õ��", who, 1, MAX_CARRY) ) || objectp( item = present("��Ϧ��õ��", who, 1, MAX_CARRY) ) || objectp( item = present("��Ϧ��õ��", who, 1, MAX_CARRY) ) || who->get_save_2( "qixi.flag" ) > 1 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻���Ѿ����������𣿸Ͽ�ȥ�������Ե�˰ɣ�\n"
			ESC"�뿪",me->get_name()));
			return ;	
		}
       		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%s",'!',"������һ����İ���������ȡ�ɣ�");
			return ;	
		}
		item = new(sprintf("item/04/045%d",random(4)));
		p = item->move(who,-1);
		item->add_to_user(p);
		who->set_save_2( "qixi.flag", 1 );
//		who->set_save_2("qixi.receive",1);	//�Ѿ���ȡ��
		send_user( who,"%c%s",';',sprintf("��õ���"HIR"%s",item->get_name()));
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ҵ������Ե�˺󣬽��������Ķ��飬Ȼ��ȥ�����ϣ�\n"
		ESC"�뿪",me->get_name()));
        	break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȴ����ѵĻ�Ӧ����\n"
			ESC"�뿪",me->get_name()));
        	break;
        case 4:
//	        if ( team[0]->get_save_2("qixi.flag") == 12 && team[1]->get_save_2("qixi.flag") == 12 && team[0]->get_gender() != team[1]->get_gender() && team[0]->get_save_2("qixi.together") == team[1]->get_save_2("qixi.together") )
	        if ( who->get_save_2("qixi.flag") == 12 )
		{
/*			if(USER_INVENTORY_D->count_empty_carry(team[0]) < 1 )
			{
			        send_user(team[0],"%c%s",';',"��Ķ���̫���ˣ�������һ����İ��������������ǰɣ�");
		    		return;
			}
			if(USER_INVENTORY_D->count_empty_carry(team[1]) < 1 )
			{
			        send_user(team[1],"%c%s",';',"��Ķ���̫���ˣ�������һ����İ��������������ǰɣ�");
		    		return;
			}

			if( !objectp( item_qx1 = present("��ţ��֯Ů���ɵ�", team[0], 1, MAX_CARRY) ) )
			{
				send_user(team[0],"%c%s",'!',"����ɵ���?");
				return;	
			}
			if( !objectp( item_qx2 = present("��ţ��֯Ů���ɵ�", team[1], 1, MAX_CARRY) ) )
			{
				send_user(team[1],"%c%s",'!',"����ɵ���?");
				return;	
			}

			item_qx1->remove_from_user();
                	destruct(item_qx1);
			item_qx2->remove_from_user();
                	destruct(item_qx2);*/
//			for (i=0;i<size;i++)
			{
				who->add_exp(50000*(who->get_online_rate()/100));
				who->add_cash(50000*(who->get_online_rate()/100));
//				if ( who->get_gender() == 1 )
//				     	item=new("item/04/ring1");
//				else
					item=new("item/04/ring2");
				p = item->move(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������ǵ�һ�����⣬���Ǿ����°ɡ�\n"
				ESC"�뿪",me->get_name()));
				send_user(who,"%c%s",';',sprintf(HIR"���������Ϧ�����Ե���񣬻�ý�Ǯ50000������50000����Ƚ��� "));
				who->delete_save_2("qixi.flag");
				who->set_save_2("qixi.finish",1);
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_QIXI,12,"" ); 
				send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_QIXI,"" ); 
			}
			send_user( CHAT_D->get_chat(), "%c%s", 0xA3, sprintf(HIY"��ϲ%s�����Ϧ�����Ե����ʹţ��֯Ů�ܹ��Ҹ���������һ��",who->get_name()) );
		}
        	break;
        }
}

int accept_object(object me, object item,int amount)
{

	return __FILE__->accept_object2(me, this_object(), item,amount);
}

int accept_object2(object me, object who, object item2,int amount)
{
	if ( USER_INVENTORY_D->count_empty_carry(me) < 1 )
	{
		send_user(who,"%c%s",';',"������һ����İ���������ȡ�ɣ�");
		return 0;	
	}
	if (item2->get_name()=="��֯Ů���ɵ�" && me->get_save_2("qixi.flag") == 12 )
	{
		who->do_visit(4);
tell_user(me,"jjjjjj");
		return 1;
	}
	return 0;
}

void go_there()
{
	object me=this_object();
	
	me->add_to_scene(802,78,43,2);
}
