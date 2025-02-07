#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 5502; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���޴�Խ����");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
        if ( !clonep(this_object()) )
        	return ;
        if (MAIN_D->get_host_type()==2)		//̨�����
        	call_out("go_there",2);
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }
void do_look_call(object me,object who)
{
	int id = getoid(me);
	int iTime=time();
	
	if (MAIN_D->get_host_type()==2)
		return ;
	if ( who->get_save_2("51cuanye.time") )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    ��վ���������Ͷ���������񣬾���Ҳ�ã�����Ҳ�գ���ֻ�ȴ��Ǹ�Ѱ���ҵ��ˡ�\n"ESC"���޴�Խ\ntalk %x# welcome.1\n"ESC"�뿪",me->get_name(),id,));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    ��վ���������Ͷ���������񣬾���Ҳ�ã�����Ҳ�գ���ֻ�ȴ��Ǹ�Ѱ���ҵ��ˡ�\n"ESC"�뿪",me->get_name(),));
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,i,size,id,iTime,amount;
       	object who, item,*nTeam;
	  
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	iTime = who->get_save_2("51cuanye.time");
        	if ( !iTime )
        		return ;
		if ( !who->is_leader() )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ��������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( !objectp(item = present("���޴�Խ֤����", who, 1, MAX_CARRY)) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ļ��޴�Խ֤�����أ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
        	id = getoid(me);
        	i = gone_time(iTime)/60;
        	if ( i <= 10 )
        		p = 5;
        	else if ( i <= 20 )
        		p = 4;
        	else if ( i <= 30 )
        		p = 3;
        	else
        		p = 2;
        	who->set_save_2("51cuanye.min",i);
        	who->set_save_2("51cuanye.amount",p);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    û�뵽����ô����ҵ����ˣ��һ���Ϊ����Ҫ�ٵ���һ���꣡\n    �㻨����%d�����ҵ��ң����õ�%d��ս���Ͷ����¡�\n"ESC"���޴�Խ\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),i,p,id,));
		break;
	case 2:
		iTime = who->get_save_2("51cuanye.time");
		i = who->get_save_2("51cuanye.min");
		amount = who->get_save_2("51cuanye.amount");
		if ( !amount )
			return ;
		if ( !who->is_leader() )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ��������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( !objectp(item = present("���޴�Խ֤����", who, 1, MAX_CARRY)) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ļ��޴�Խ֤�����أ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		who->delete_save_2("51cuanye.min");
		who->delete_save_2("51cuanye.amount");
		nTeam = who->get_team();
		size = sizeof(nTeam);
		if ( !size )
			return ;
		for(i=0;i<size;i++)
		{
			if ( !objectp(nTeam[i]) )
				continue;
			if ( !inside_screen_2(nTeam[i],me) )
				continue;
			if ( iTime != nTeam[i]->get_save_2("51cuanye.time") )
				continue;
			if ( USER_INVENTORY_D->count_empty_carry(nTeam[i]) < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������"HIR+nTeam[i]->get_name()+NOR"��ҵĵ������ռ䲻��������ճ�һ��������������Ʒ��\n"ESC"�뿪",me->get_name(),));
				return ;
			}
		}				
		item->remove_from_user();
		destruct(item);
		for(i=0;i<size;i++)
		{
			if ( !objectp(nTeam[i]) )
				continue;
			if ( !inside_screen_2(nTeam[i],me) )
				continue;
			if ( iTime != nTeam[i]->get_save_2("51cuanye.time") )
				continue;
			nTeam[i]->delete_save_2("51cuanye.time");
			item = new("item/04/0438");
			item->set_amount(amount);
			p = item->move(nTeam[i],-1);
			item->add_to_user(p);
			send_user(nTeam[i],"%c%s",';',sprintf("��������񣬵õ�%d��ս���Ͷ�����",amount));
	                send_user( nTeam[i], "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,1,"" );                  		
		}

		break;
	}

}

void go_there()
{
	object me=this_object();
	
	me->add_to_scene(802,78,43,2);
}