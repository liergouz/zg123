#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>

inherit OFFICER;
inherit SAVE_F;
int iStart1,iFinish1,year1,year2,mon1,mon2,day1,day2;
// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome(string arg);

string get_save_file()	{ return "data/51cuanyue"SAVE_EXTENSION;}

//�������
void check_date(object player)
{
	mixed *mixTime;
	mixTime = localtime(time());
	if (mixTime[TIME_YDAY]!=player->get_save_2("51cuanye.day"))
	{
		player->set_save_2("51cuanye.day", mixTime[TIME_YDAY]);	
	        player->set_save_2("51cuanye.count", 0);
	}
	if (mixTime[TIME_YDAY]!=player->get_save_2("51tiandao.day"))
	{
		player->set_save_2("51tiandao.day", mixTime[TIME_YDAY]);	
	        player->set_save_2("51tiandao.count", 0);
	}		
}

// ���������촦��
void create()
{
	restore();
        set_name("��һ�ָ��Ա");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
	set("mpLegend",([0:({32}),]));
	if ( !iStart1 || !iFinish1 )
	{
		iStart1 = mktime(2007,5,1,0,0,0);	
		iFinish1 = mktime(2007,5,8,0,0,0);	
	}
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
	if ( iTime > iStart1 && iTime < iFinish1 )
	{
		if ( who->get_save_2("51cuanye.time") )	
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    ��һ�ڼ�����Ϊ���׼���˷ḻ�����ϻ��������ȡ��ս���Ͷ����¡������л���һ���ɫװ���������ν�����Ʒ��\n    �������������Ȼƽ��ܣ����ϸ��Ϣ���ѯhttp:/""/zg.mop.com�ר����\n"ESC"�������\ntalk %x# welcome.2\n"ESC"ս���Ͷ����¶ҽ�\ntalk %x# welcome.5",me->get_name(),id,id));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    ��һ�ڼ�����Ϊ���׼���˷ḻ�����ϻ��������ȡ��ս���Ͷ����¡������л���һ���ɫװ���������ν�����Ʒ��\n    �������������Ȼƽ��ܣ����ϸ��Ϣ���ѯhttp:/""/zg.mop.com�ר����\n"ESC"���޴�Խ\ntalk %x# welcome.0\n"ESC"�������\ntalk %x# welcome.2\n"ESC"ս���Ͷ����¶ҽ�\ntalk %x# welcome.5",me->get_name(),id,id,id));
	}
	else
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��һ�����֣�ս���ַ��죡\n    ��һ�ڼ�����Ϊ���׼���˷ḻ�����ϻ��������ȡ��ս���Ͷ����¡������л���һ���ɫװ���������ν�����Ʒ��\n    �������������Ȼƽ��ܣ����ϸ��Ϣ���ѯhttp:/""/zg.mop.com�ר����\n"ESC"ս���Ͷ����¶ҽ�\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,i,size,id,iTime,count,amount,count1,rate;
       	object who, item,*nTeam,*inv;
        string *nTmp,tmp;
	string *nFamily = ({"�һ�Դ","��ɽ","������","����","éɽ","����ɽ","������"});
	 
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 0:
        	if ( who->get_save_2("51cuanye.time") )
        		return ;
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
		if ( !who->is_leader() )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ������ܽ�������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( who->get_level() >= 30 )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ĵȼ��ƺ���̫�ʺ�������������ޡ���������Կ��ǰ����ͼ����������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( who->get_save_2("51cuanye.count") == 0 )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    30�����µ����ע���ˣ������������ر�Ϊ������Ƶ�Ŷ������������Ҫ˳�����ﴫ˵�еĶ��������벻���߼���ҵİ�����������ԥʲô���Ͻ�����������������ɣ���������ѯhttp:/""/zg.mop.com�ר����\n    �ú����š����޴�Խ֤���顱��ȥ�����������������ļ��޴�Խ���٣�������õ�������Ľ����ˣ�\n    �������ÿ����ظ���ȡ5��Ŷ��\n"ESC"��ȡ����\ntalk %x# welcome.1\n"ESC"�뿪",me->get_name(),id,));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    30�����µ����ע���ˣ������������ر�Ϊ������Ƶ�Ŷ������������Ҫ˳�����ﴫ˵�еĶ��������벻���߼���ҵİ�����������ԥʲô���Ͻ�����������������ɣ���������ѯhttp:/""/zg.mop.com�ר����\n    �ú����š����޴�Խ֤���顱��ȥ�����������������ļ��޴�Խ���٣�������õ�������Ľ����ˣ�\n    ��������㻹������%d��Ŷ��\n"ESC"��ȡ����\ntalk %x# welcome.1\n"ESC"�뿪",me->get_name(),5-who->get_save_2("51cuanye.count"),id,));
		
        	break;
        case 1:
        	if ( who->get_save_2("51cuanye.time") )
        		return ;
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
		if ( !who->is_leader() )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㲻�Ƕӳ������ܽ�������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( who->get_level() >= 30 )
       		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ĵȼ��ƺ���̫�ʺ�������������ޡ���������Կ��ǰ����ͼ����������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		nTeam = who->get_team();
		nTeam -= ({0});
		size = sizeof(nTeam);
		if ( !is_god(who) && size < 2 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �㵥ǹƥ�����ȥ���������������ˣ����Ƕ�м������������Ұɣ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ���̫���ˣ�������һ������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		for(i=0;i<size;i++)
		{
			if ( !objectp(nTeam[i]) )
				continue;
			if ( !inside_screen_2(nTeam[i],me) )
				continue;
			if ( nTeam[i]->get_save_2("51cuanye.time") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����е�"HIR+nTeam[i]->get_name()+NOR"����Ѿ���ȡ�˼��޴�Խ����\n"ESC"�뿪",me->get_name(),));
				return ;
			}
			check_date(nTeam[i]);
			if ( nTeam[i]->get_save_2("51cuanye.count") >= 5 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ÿ��ֻ����ȡ5�θ�����"HIR+nTeam[i]->get_name()+NOR"��������������Ѵﵽ��\n"ESC"�뿪",me->get_name(),));
				return ;
			}
		}
		item = new("item/04/0439");
		if ( !item )
			return ;
		p = item->move(who,-1);
		item->add_to_user(p);
		iTime = time();

		for(i=0;i<size;i++)
		{
			if ( !objectp(nTeam[i]) )
				continue;
			if ( !inside_screen_2(nTeam[i],me) )
				continue;
			nTeam[i]->set_save_2("51cuanye.time",iTime);
			nTeam[i]->add_save_2("51cuanye.count",1);
	                send_user( nTeam[i], "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"��һ�" );     
	                send_user( nTeam[i], "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,1,"���޴�Խ" );                  		
	                send_user( nTeam[i], "%c%s",';',"�������Ķ����Ѿ��ɹ���ȡ�ˡ����޴�Խ�����񣬸Ͻ������ɣ�");
		}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������Ѿ���ȡ�˼��޴�Խ���������ھͺ����Ķ���һ��ȥѰ�Ҵ�˵�еĶ������ɣ�\n    Խ�쵽��Ŀ�ĵأ��õ��Ľ�����Խ�࣡\n"ESC"�뿪",me->get_name(),));
        	break;
        case 2:
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
        	if ( !who->get_save_2("51tiandao.accept") )	//û��
       		{
			check_date(who);
			if ( who->get_save_2("51tiandao.count") == 0 )
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    һ�ָ��ţ�һ���ջ�ֻҪ�����Ͷ��ͻ��ջ��˶�Ĺ�ʵ��������ھ��Ǹ����͵���ר����Ƶ������������Ϳ��Ի�����صġ�ս���Ͷ����¡���\n    ����ܼ򵥣�ֻҪ�������������ʯ��ȥɱ��100ֻ�����Լ��ȼ�5��֮�ڵĹ֣���Ϳ��Ի���������ȡ�����ˡ��������ÿ����ظ���ȡ5��Ŷ��\n    ���ϸ��Ϣ���ѯhttp:/""/zg.mop.com�ר����\n"ESC"��ȡ����\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),id,));
			else
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    һ�ָ��ţ�һ���ջ�ֻҪ�����Ͷ��ͻ��ջ��˶�Ĺ�ʵ��������ھ��Ǹ����͵���ר����Ƶ������������Ϳ��Ի�����صġ�ս���Ͷ����¡���\n    ����ܼ򵥣�ֻҪ�������������ʯ��ȥɱ��100ֻ�����Լ��ȼ�5��֮�ڵĹ֣���Ϳ��Ի���������ȡ�����ˡ���������㻹������%d��Ŷ��\n    ���ϸ��Ϣ���ѯhttp:/""/zg.mop.com�ר����\n"ESC"��ȡ����\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),5-who->get_save_2("51tiandao.count"),id,));
			return ;
		}
		else if ( who->get_save_2("51tiandao.amount") >= 100 )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����������������ս���Ͷ����¹����ˣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),id,));
        	else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������ҿ��ò�������Ŷ�������˸����������ٻ������Ұɡ�\n"ESC"�뿪",me->get_name(),));
        	break;
        case 3:
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
        	if ( who->get_save_2("51tiandao.accept") )
        		return ;
		check_date(who);
		if ( who->get_save_2("51tiandao.count") >= 5 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ÿ��ֻ����ȡ5�θ���������������������Ѵﵽ��\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ���̫���ˣ�������һ������������\n"ESC"�뿪",me->get_name(),));
			return ;
		}
		item = new("item/04/0441");
		p = item->move(who,-1);
		item->add_to_user(p);
		who->set_save_2("51tiandao.accept",time());
		who->add_save_2("51tiandao.count",1);
                send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_WUYIHUODONG,"��һ�" );     
                send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"�������" );                  		
        	break;
        case 4:
        	if ( who->get_save_2("51tiandao.amount") < 100 )
        		return ;
		if ( !objectp(item = present("����ʯ", who, 1, MAX_CARRY)) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������ʯ�أ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}     
		item->remove_from_user();
		destruct(item);
        	who->delete_save_2("51tiandao.amount");
        	who->delete_save_2("51tiandao.accept");
        	item = new("item/04/0438");
		item->set_amount(3);
		p = item->move(who,-1);
		item->add_to_user(p);
                send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_WUYIHUODONG,2,"" );                  		
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ͬ������ս���Ͷ����¿��Ի�ȡ��ͬ�Ľ�Ʒ������Խ�࣬��ƷԽ���\n"ESC"1ö���¶һ���Ʒ\ntalk %x# welcome.1001\n"ESC"5ö���¶һ���Ʒ\ntalk %x# welcome.1005\n"ESC"20ö���¶һ���Ʒ\ntalk %x# welcome.1020\n"ESC"50ö���¶һ���Ʒ\ntalk %x# welcome.1050\n"ESC"100ö���¶һ���Ʒ\ntalk %x# welcome.1100\n"ESC"300ö���¶һ���Ʒ\ntalk %x# welcome.1300\n"ESC"30ö���¶һ�һ���ƺ�\ntalk %x# welcome.2030\n"ESC"60ö���¶һ������ƺ�\ntalk %x# welcome.2060\n"ESC"120ö���¶һ������ƺ�\ntalk %x# welcome.2120\n"ESC"�뿪",me->get_name(),id,id,id,id,id,id,id,id,id,));
        	break;
        case 1001:
        case 1005:
        case 1020:
        case 1050:
        case 1100:
        case 1300:
		if ( USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
        	count = flag - 1000;
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��%döս���Ͷ��������һ���Ʒ��\n"ESC"ȷ��\ntalk %x# welcome.%d\n"ESC"�뿪",me->get_name(),count,id, 2000+flag));
        	
        	break;
        case 2030:
        case 2060:
        case 2120:
        	count = flag - 2000;
        	if ( count == 30 )
        		tmp = "�Ͷ������";
        	else if ( count == 60 )
        		tmp = "���͵�С�۷�";
        	else if ( count == 120 )
        		tmp = "��ǿ��ս����ģ";
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��%döս���Ͷ��������һ�"HIR"��%s��"NOR"�ĳƺ���\n"ESC"ȷ��\ntalk %x# welcome.%d\n"ESC"�뿪",me->get_name(),count,tmp,id, 2000+flag));
        	break;
        case 4030:
        case 4060:
        case 4120:
        	count = flag - 4000;
        	if ( count == 30 )
        		tmp = "A003";
        	else if ( count == 60 )
        		tmp = "A004";
        	else if ( count == 120 )
        		tmp = "A005";
		if ( who->have_title(tmp) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ��������ĳƺ��ˣ�\n"ESC"�뿪",me->get_name(),));
			return ;
		} 
        	inv = all_inventory(who, 1, MAX_CARRY);
        	for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "ս���Ͷ�����" )
				continue;
			amount += inv[i]->get_amount();		
		}
		if ( amount < count )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ�ս���Ͷ�������������%d������������������������������Ұɣ�\n"ESC"�뿪",me->get_name(),count));
			return ;	
		}
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "ս���Ͷ�����" )
				continue;
			amount = inv[i]->get_amount();
			if ( count >= amount )
			{
				inv[i]->remove_from_user();
				destruct(inv[i]);
				count -= amount;
			}
			else
			{
				inv[i]->add_amount(-count);
				count = 0;	
			}
			if ( count <= 0 )
				break;
		}
		who->add_title(tmp);
		who->show_title(tmp);
		break;
        case 3001:
        case 3005:
        case 3020:
        case 3050:
        case 3100:
        case 3300:
        	if ( USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name(),));
			return ;
		}
        	count = flag - 3000;
		count1 = count;
        	inv = all_inventory(who, 1, MAX_CARRY);
        	for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "ս���Ͷ�����" )
				continue;
			amount += inv[i]->get_amount();		
		}
		if ( amount < count )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ�ս���Ͷ�������������%d������������������������������Ұɣ�\n"ESC"�뿪",me->get_name(),count));
			return ;	
		}
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "ս���Ͷ�����" )
				continue;
			amount = inv[i]->get_amount();
			if ( count >= amount )
			{
				inv[i]->remove_from_user();
				destruct(inv[i]);
				count -= amount;
			}
			else
			{
				inv[i]->add_amount(-count);
				count = 0;	
			}
			if ( count <= 0 )
				break;
		}
		count = count1;
		rate = random(10000);
		if ( count == 1 )
		{
			if ( rate < 3500 )
				item = new("item/91/9100");
			else if ( rate < 7000 )
				item = new("item/91/9110");
			else if ( rate < 8500 )
				item = new("item/91/9101");
			else
				item = new("item/91/9111");
			item->set_amount(5);
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
		else if ( count == 5 )
		{
			if ( rate < 2500 )
			{
				item = new("item/91/9100");
				item->set_amount(10);
			}
			else if ( rate < 5000 )
			{
				item = new("item/91/9110");
				item->set_amount(10);
			}
			else if ( rate < 6500 )
			{
				item = new("item/91/9101");
				item->set_amount(10);
			}
			else if ( rate < 8000 )
			{
				item = new("item/91/9111");
				item->set_amount(10);
			}
			else if ( rate < 9000 )
			{
				item = new("item/std/6003");
			}			
			else 
			{
				item = new("item/std/8000");
			}			
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
		else if ( count == 20 )
		{
			if ( rate < 2500 )
			{
				item = new("item/91/9101");
				item->set_amount(10);
			}
			else if ( rate < 5000 )
			{
				item = new("item/91/9111");
				item->set_amount(10);
			}
			else if ( rate < 7000 )
			{
				item = new("item/std/6003");
			}			
			else if ( rate < 9000 )
			{
				item = new("item/std/8000");
			}
			else if ( rate < 9800 )
			{
				item = new("item/44/4488");
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else
			{
				nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,HEAD_TYPE+random(6));
	        		tmp = nTmp[random(sizeof(nTmp))];
	        		if ( !stringp(tmp) )
	        			return ;
	        		item = new(tmp);
	        		ITEM_EQUIP_D->init_equip_prop_1(item);
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}			
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
		else if ( count == 50 )
		{
			if ( rate < 3500 )
			{
				item = new("item/std/8000");
			}
			else if ( rate < 6500 )
			{
				item = new("item/44/4488");
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else if ( rate < 9000 )
			{
				nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,HEAD_TYPE+random(6));
	        		tmp = nTmp[random(sizeof(nTmp))];
	        		if ( !stringp(tmp) )
	        			return ;
	        		item = new(tmp);
	        		ITEM_EQUIP_D->init_equip_prop_1(item);
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else
			{
				item = new(sprintf("item/std/%d",8001+random(4)));	
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}			
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
		else if ( count == 100 )
		{
			if ( rate < 3500 )
			{
				item = new("item/44/4488");
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else if ( rate < 6500 )
			{
				nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,HEAD_TYPE+random(6));
	        		tmp = nTmp[random(sizeof(nTmp))];
	        		if ( !stringp(tmp) )
	        			return ;
	        		item = new(tmp);
	        		ITEM_EQUIP_D->init_equip_prop_1(item);
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else if ( rate < 8500 )
			{
				item = new(sprintf("item/std/%d",8001+random(4)));	
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}	
			else
			{
				item = new("item/91/9167");
				p = item->move(who,-1);
				item->add_to_user(p);
				item = new("item/91/9167");
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}		
			p = item->move(who,-1);
			if ( p )
				item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
		else if ( count == 300 )
		{
			if ( rate < 6000 )
			{
				item = new(sprintf("item/std/%d",8001+random(4)));	
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}	
			else if ( rate < 9700 )
			{
				item = new("item/91/9167");
				p = item->move(who,-1);
				item->add_to_user(p);
				item = new("item/91/9167");
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else if ( rate < 9800 )
			{
				nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),WEAPON_TYPE);
	        		tmp = nTmp[random(sizeof(nTmp))];
	        		if ( !stringp(tmp) )
	        			return ;
	        		item = new(tmp);
	        		ITEM_EQUIP_D->init_equip_prop_3(item);
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}
			else 
			{
				nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),ARMOR_TYPE);
	        		tmp = nTmp[random(sizeof(nTmp))];
	        		if ( !stringp(tmp) )
	        			return ;
	        		item = new(tmp);
	        		ITEM_EQUIP_D->init_equip_prop_3(item);
				CHAT_D->sys_channel(0,sprintf(HIR"��ϲ%s��һ�ý�Ʒ%s",who->get_name(),item->get_name()));
			}		
			p = item->move(who,-1);
			if ( p )
				item->add_to_user(p);
			send_user(who,"%c%s",';',sprintf("����%döս���Ͷ����¶һ���%s",count,item->get_name()));
		}
        	break;
        	
	}

}

void go_there()
{
	object me=this_object();
	
	me->add_to_scene(802,78,43,2);
}

int set_open(object who,string arg)
{
	int date1,date2;
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
	iStart1 = mktime(year1,mon1,day1,0,0,0);	
	iFinish1 = mktime(year2,mon2,day2,0,0,0);		
	if ( iStart1 > iFinish1 )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡��");	
		return 0;
	}
	tell_user(who,"�������%s��",arg);	
	send_user(who,"%c%s",'!',"51�������");	
	save();
	return 1;
}

int set_close(object who)
{
	iStart1 = 0;	
	iFinish1 = 0;		
	send_user(who,"%c%s",'!',"51��رգ�");	
	save();
	return 1;	
}