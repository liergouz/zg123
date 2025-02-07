#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>

#define _TEST

inherit OFFICER;
inherit SAVE_F;
int iStart1,iFinish1,year1,year2,mon1,mon2,day1,day2;
// ��������ȡ��������
int get_char_picid() { return 5420; }
void do_welcome(string arg);

string get_save_file()	{ return "data/dodolook"SAVE_EXTENSION;}

// ���������촦��
void create()
{
        restore();
        set_real_name("�߹��λ��");
        set_name("����");
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
string get_short() 
{ 
	if ( stringp(get_real_name()) )
		return get_name() + "|" + get_real_name();
	else
		return get_name();
}
void do_look(object who) { __FILE__->do_look_call(this_object(),who); }
void do_look_call(object me,object who)
{
	int id = getoid(me);
	int iTime=time();
	
	if (MAIN_D->get_host_type()==2)
		return ;
	if ( who->get_birthday() > iStart1 && iTime > iStart1 && iTime < iFinish1 && !who->get_save("dodolook") )	
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ҽк���������һ��ʱ�ա�����Ѱ��һ����dodolook��Ů�����������������\n"ESC"û����\ntalk %x# welcome.2\n"ESC"����\ntalk %x# welcome.3\n"ESC"����к�\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ҽк���������һ��ʱ�ա�����Ѱ��һ����dodolook��Ů�����������������\n"ESC"����к�\ntalk %x# welcome.4\n"ESC"�뿪",me->get_name(),id,));
}

void do_welcome(string arg) { __FILE__->do_welcome_call(this_object(),arg); }

void do_welcome_call( object me,string arg )
{
	int flag, p,iTime,i,size,id,level,iLev;
       	object who, item;
       	string name,*nTmp,tmp;
	mixed *mxTime;  
	
	
	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
	case 2:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ޣ��������������ʱ�򣬻������֪��һ����",me->get_name()));
		break;
	case 3:
		if ( who->get_birthday() < iStart1 )
		{
			send_user(who,"%c%s",'!',"��ڼ䴴���Ľ�ɫ���ܲμ�");
			return ;	
		}
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( who->get_save("dodolook") )
        		return ;
               	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
        	if ( who->get_level() < 10 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��˵������ĵȼ���û�뿪�����ִ�ɡ���������þ��˶�û���������㲻Ҫ��ƭ���ˡ�\n"ESC"�����Լ�����\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),id,));
        		return ;	
        	}
        	
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������ģ���̫���ˣ����ܰ���һ��æô��\n"ESC"Ը��\ntalk %x# welcome.6\n"ESC"�뿪",me->get_name(),id,));
        	break;
	case 4:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����dodolook��ս��ð����һ���ܳ��Ĺ��£��������������ð�վ����������С�������˼��뵽���������������֪�������ϸ�ڣ������ȥzg.mop.com����������һ����ǳ��",me->get_name()));
		break;
	case 5:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    û�й�ϵ��"HIR"���㵽��ʮ�������뿪�����ʱ���������ң���ʱ�ҽ����и�����һ���£�"NOR"Ҳ�����������Ե�������������ڣ�ʮ���Ǳ��������������óԵİɣ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),id,));
		break;
	
	case 6:
        	if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( who->get_save("dodolook") )
        		return ;
               	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
        	if ( who->get_level() < 10 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��˵������ĵȼ���û�뿪�����ִ�ɡ���������þ��˶�û���������㲻Ҫ��ƭ���ˡ�\n"ESC"�����Լ�����\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),id,));
        		return ;	
        	}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����������κ��������dodolook�����٣���ǰȥ��̽һ�¡�����Ѱ�����Ļ������ȥ�ݷ���κ������˵��������κ��������ץ�����ˣ�\n"ESC"�ݷ�κ����\ntalk %x# welcome.8\n"ESC"�뿪",me->get_name(),id,));
		break;
	case 7:
        	if ( who->get_save("dodolook_gift") )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ����ܹ������ˣ�",me->get_name()));
        		return ;	
        	}
        	if ( USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%s",'!',"����һ����İ�����");
			return ;	
		}	
		//�о�ɢ5��
		item = new("item/91/9100");
		item->set_amount(5);
		p = item->move(who,-1);
		item->add_to_user(p);
		//5������
		item = new("item/86/0001");
		item->set_bind(3);
		p = item->move(who,-1);
		item->add_to_user(p);
        	who->set_save("dodolook_gift",1);
        	send_user(who,"%c%s",'!',"��õ����������");
		break;
	case 8:
		if ( time() < iStart1 )
        	{
        		return ;	
        	}
        	if ( who->get_save("dodolook") )
        		return ;
               	if ( time() > iFinish1 )
        	{
        		return ;	
        	}
        	if ( who->get_level() < 10 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��˵������ĵȼ���û�뿪�����ִ�ɡ���������þ��˶�û���������㲻Ҫ��ƭ���ˡ�\n"ESC"�����Լ�����\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),id,));
        		return ;	
        	}
        	who->set_save("dodolook",1);
        	send_user(who,"%c%s",'!',"�õ�����"HIR"�ݷ�κ����");
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_DODOLOOK,"Ѱ��dodolook" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_DODOLOOK, 1, "�ݷ�κ����" );
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
	send_user(who,"%c%s",'!',"Ѱ��dodolook�������");	
	save();
	return 1;
}

int set_close(object who)
{
	iStart1 = 0;	
	iFinish1 = 0;		
	send_user(who,"%c%s",'!',"Ѱ��dodolook��رգ�");	
	save();
	return 1;	
}