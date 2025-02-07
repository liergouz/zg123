#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 6010; }
void do_bonus();
void do_welcome(string arg);
void read_renwang();
void read_lifeskill();

// ���������촦��
void create()
{
        set_name("��������");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());

	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�������ӣ�\n    ���ã������������ӡ���ӭ��������ս�������磬Ϊ�˹���������ҵ��ȡ�ģ��������͸���һ�����\n"ESC"��ȡ����\ntalk %x# welcome.1\n"ESC"�뿪",id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,iTime,i,size;
       	object who, item;
       	string name;
	mixed *mxTime;    
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
     	        if ( who->get_level() < 10 )
     	        {
     	        	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"�������ӣ�\n    �����ڵĵȼ�������10�������ﻹ��ʱ�����͸��㡣����10��֮���������Ұɡ�");
			return ;
		}
		if ( who->get_save("ruyi_gift") )
        	{
     	        	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"�������ӣ�\n    ��ô����ʯ��Ч������ɡ���������������������֮���Ч��һ������ߡ�");
			return ;
		}
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�������ӣ�\n    ��ʮ���ˣ�������װ�������в�ͬ��Ҫ���ˣ����������Ҿ�������3�ſ��Ը�����װ���������Եľ�ʯ������㰴�մӵ͵��ߵĵȼ�˳�����ν���3�ž�ʯ�������������߷����ϣ���ῴ�����ǵĹ�����ǿ����Ŷ����ס����Щ��ʯֻ��20�����µ�װ����Ч��\n"ESC"��ȡ\ntalk %x# welcome.2\n"ESC"�뿪",getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() < 10 )
        		return ;
        	if ( who->get_save("ruyi_gift") )
        		return ;
		if ( TASK_LEGEND_D->can_carry_amount(who,6) != 1 )
        			return ;
		for(i=1;i<4;i++)
		{
			item = new("item/93/9343");
			item->set_level(i);
			p = item->move(who,-1);
			item->add_to_user(p);
		}
		for(i=1;i<4;i++)
		{
			item = new("item/93/9345");
			item->set_level(i);
			p = item->move(who,-1);
			item->add_to_user(p);
		}
		send_user(who,"%c%s",'!',"��ϲ��õ��������ӵ�����");
		who->set_save("ruyi_gift",1);
        	break;
	}

}