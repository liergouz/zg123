
#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;
inherit SAVE_F;
int iStart,iFinish,iStart2;
string org_name;
int max_org_qgl;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5205; }
string get_save_file()	{ return "data/qiguoling"SAVE_EXTENSION;}
// ���������촦��
void create()
{
	restore();
        set_name("�߹����ռ�Ա");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
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
	object orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", me->get_org_name() ) );
	int id = getoid(me);
	if (!objectp(orgnpc))
		return ;
	if (MAIN_D->get_host_type()==2)
		return ;
	if (who->get_org_name() != me->get_org_name())
		return ;
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����߹����뱾������ĳ�����صĹ�ϵ��Ϊ�˽ҿ�������ܣ��㻹�ǽ��߹�����Ұɡ�����Ϊ�ر����㽫��õ�һ���Ľ���Ŷ����    ���ڰ������Ѿ����ɵ��߹����ۼ���"HIR"%d"NOR"��\n"
		ESC"�����߹���\ntalk %x# welcome.1\n"
		ESC"��ȡ�������ĺ�����\ntalk %x# welcome.3\n"
		ESC"��ȡ�����޵а�ά\ntalk %x# welcome.9\n"
		ESC"�˽�������ĺ�����\ntalk %x# welcome.7\n"
		ESC"�˽ⳬ���޵а�ά\ntalk %x# welcome.8\n"
		ESC"�뿪",
		me->get_name(),orgnpc->get_save("qgl_org_n"),id,id,id,id,id));
}

void do_welcome(string arg) { __FILE__->do_welcome_call(this_object(),arg); }

void do_welcome_call( object me,string arg )
{
	int flag, p,iTime,i,size,id,x,y,z,level,number;
       	object who, item,*nTeam,member,npc,map,orgnpc;
       	string name,*nTmp,tmp,result;
	mixed *mxTime;  
	
	
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);

        switch(flag)
        {
        case 1:
		if (iStart==0 || time() < iStart)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���û��ʼ�أ�������鿴�ٷ���վ(zg.mop.com)���档\n"ESC"�뿪",me->get_name(),));
		else if (iStart==1 || (time()>iStart && time()<iFinish))
		{
			if (who->get_org_name() != me->get_org_name())
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���������кι�ɣ�ǧ��Ҫ������Ŷ������Ȼ�����ֵ�һ������㲻�����ġ���\n"ESC"�뿪",me->get_name(),));
	        	else if( !objectp( item = present("�߹���", who, 1, MAX_CARRY) ) )
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϲ�û���߹�������㻹�Ǻú�����ɡ������룬�ǲ������Ƿ���ʲô�ط���\n"ESC"�뿪",me->get_name(),));
			else
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��л��Ϊ���������Ĺ��ף����Ǹ���Ľ����������䲻�࣬�������ش����һ��Ҫ����Ŷ����\n"ESC"��ȡ����\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),id));
		}
		else if (iStart==2 || time()>iFinish)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����Ѿ�������лл��Ĳ��룡\n"ESC"�뿪",me->get_name(),));
        	break;


        	break;
        case 2:
		if (iStart==2 || time()>iFinish) return;
        	if( objectp( item = present("�߹���", who, 1, MAX_CARRY) ) )
        	{
			orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
			number = who->get_number();
                        orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+5);
        		result = sprintf("���� %s,%d,%s,%s @%s %s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), "", me->get_name(),item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
			item->add_amount(-1);
                        who->add_exp(2000);
                        who->add_potential(50);
                        send_user( who, "%c%s", ';', "���õ���5��ﹱ��2000���顢50Ǳ�ܵĽ���");
			who->add_save("qgl_n",1);
                        orgnpc->add_save("qgl_org_n",1);
			orgnpc->save();
			log_file("qgl_org_n.txt",sprintf("%d ������ %d %s �� %s ���߹��� %d\n",MAIN_D->get_host(),MAIN_D->get_host_type(),who->get_org_name(),short_time(),orgnpc->get_save("qgl_org_n")));
			"/sys/user/cmd"->log_item(result);
			if (orgnpc->get_save("qgl_org_n") > max_org_qgl)
			{
				org_name=who->get_org_name();
				max_org_qgl=orgnpc->get_save("qgl_org_n");
				save();
			}
        	} 
        	break;
        case 3:
        	if ( iStart2 == 0 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������ĺ�������û����ѡ�������㻹�ǵ���ѡ���������ĺ������������Ұɡ���\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
        	if ( who->get_org_name() != org_name )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ǰﲢû�л�ð������ĺ�����������\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
        	if ( who->get_org_time() > iFinish )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ڴ˴λ��������뱾��ģ������콱��\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
        	if ( who->get_save("qgl_org_receive") )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ���ȡ�������ˡ����ɲ�Ҫ̰��Ŷ����\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
		if ( USER_INVENTORY_D->count_empty_carry(who) < 3 )
		{
			send_user(who,"%c%s",'!',"������һ����İ���������ȡ�����ɣ�");
			return ;	
		}
		if ( who->get_org_position() == 9 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϲ����ٻ�������ĺ���������Ϊ���������쵼�з�����Ա�ظ�������ļν���ϣ�����պ��ٽ���������\n"ESC"�뿪",me->get_name(),));
			if ( who->get_cash()+5000000 > who->get_max_cash() )
				who->add_cash(who->get_max_cash()-who->get_cash());
			else
				who->add_cash(5000000);
		}
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϲ����ٻ�������ĺ���������Ϊ��Ա���������ĺ�������Ա�ظ�������ļν���ϣ�����պ��ٽ���������\n"ESC"�뿪",me->get_name(),));

		//�书������
		item = new (BOOK_FILE->get_book_file());
		p = item->move(who,-1);
		item->add_to_user(p);

		//����
		item = new("quest/gift"->get_random_card());
		p = item->move(who,-1);
		item->add_to_user(p);

		//�鲼����
        	item = new("item/std/6003");
		p = item->move(who,-1);
		item->add_to_user(p);
       	
        	who->set_save("qgl_org_receive",time());

        	break;
        case 7:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ȡ�������ĺ��������Ǿ͸Ͽ�������ɣ������һ��������ÿ�������һ�������������ɣ�������ÿλ��Ա�õ�����书������һ�����鲼����һ�����������һ�ţ��᳤�ɵõ�500W��Ϸ�ҡ�������˵Ľ����ɲ�Ҫ���Ŷ����\n"ESC"�뿪",me->get_name(),));
        	break;
        case 8:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ȡ�����޵а�ά���Ǿ͸Ͽ�������ɣ�ɽ����ɽ�������죬�����޵а��ɲ������ǰ�����ڷ������Ľ�����������һ������ȫ���Ľ�������ҲҪλ�е�һ���У������һ���ڣ������޵а����ÿλ��Ա�õ��书������һ�����鲼����һ��������һ�ţ��᳤�ɵõ�1000W��Ϸ�ҡ�������˵Ľ����ɲ�Ҫ���Ŷ����\n"ESC"�뿪",me->get_name(),));
        	break;
        case 9:
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
        	if ( iStart2 == 0 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����޵а�ά��û����ѡ�������㻹�ǵ���ѡ�������޵а�ά�������Ұɡ���\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
        	if ( who->get_org_name() != "���mǰ��" )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ǰﲢû�л�ó����޵а�ά������\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
		if ( orgnpc->get_save("qgl_org_n") < 3000 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ǰﲢû�л�ó����޵а�ά������\n"ESC"�뿪",me->get_name(),));
			return;
        	}
        	if ( who->get_org_time() > iFinish )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ڴ˴λ��������뱾��ģ������콱��\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
        	if ( who->get_save("qgl_org_receive2") )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ���ȡ�������ˡ����ɲ�Ҫ̰��Ŷ����\n"ESC"�뿪",me->get_name(),));
        		return ;        		
        	}
		if ( USER_INVENTORY_D->count_empty_carry(who) < 3 )
		{
			send_user(who,"%c%s",'!',"������һ����İ���������ȡ�����ɣ�");
			return ;	
		}
		if ( who->get_org_position() == 9 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϲ����ٻ񳬼��޵а�ά����Ϊ���������쵼�з�����Ա�ظ�������ļν���ϣ�����պ��ٽ���������\n"ESC"�뿪",me->get_name(),));
			if ( who->get_cash()+10000000 > who->get_max_cash() )
				who->add_cash(who->get_max_cash()-who->get_cash());
			else
				who->add_cash(10000000);
		}
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ϲ����ٻ񳬼��޵а�ά����Ϊ��Ա���������ĺ�������Ա�ظ�������ļν���ϣ�����պ��ٽ���������\n"ESC"�뿪",me->get_name(),));

		//�书������
		item = new (BOOK_FILE->get_book_file());
		p = item->move(who,-1);
		item->add_to_user(p);

		//����
		item = new("quest/gift"->get_random_card());
		p = item->move(who,-1);
		item->add_to_user(p);

		//�鲼����
        	item = new("item/std/6003");
		p = item->move(who,-1);
		item->add_to_user(p);
       	
        	who->set_save("qgl_org_receive2",time());

        	break;
	}
}

void go_there()
{
	object me=this_object();
	
	me->add_to_scene(802,78,43,2);
}

void set_prepare()
{
	iStart = 0;
	save();
}

void set_open()
{
	iStart = 1;
	save();
}

int set_open_time(object who,string arg)
{
	int date1,date2,year1,year2,mon1,mon2,day1,day2;
	if ( sscanf(arg ,"%d-%d",date1,date2) != 2 )
	{
		send_user(who,"%c%s",'!',"����ĸ�ʽ��");	
		return 0;
	}
	year1 = date1 /10000;
	mon1 = date1 % 10000 / 100;
	day1 = date1 % 10000 % 100;
	year2 = date2 /10000;
	mon2 = date2 % 10000 / 100;
	day2 = date2 % 10000 % 100;
	if ( !year1 || !mon1 || !day1 || !year2 || !mon2 || !day2 )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡");	
		return 0;
	}
	iStart = mktime(year1,mon1,day1,0,0,0);	
	iFinish = mktime(year2,mon2,day2,0,0,0);		
	if ( iStart > iFinish )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡��");	
		return 0;
	}
	save();
	return 1;
}


void set_close()
{
	iStart = 2;	
	iFinish = time();
	save();
}

void set_open2()
{
	iStart2 = 1;
	save();
}

void set_close2()
{
	iStart2 = 0;	
	save();
}

