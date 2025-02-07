#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <city.h>

inherit OFFICER;
inherit SAVE_F;

string get_save_file()	{ return "data/org_buchang"SAVE_EXTENSION;}

mapping mpOrg = ([]);

// ��������ȡ��������
int get_char_picid() { return 5502; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���ɲ���Ա");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
        
        restore();
        if ( !mapp(mpOrg) ) mpOrg= ([]);
}

void do_look(object who)
{
	object me=this_object();
	string name;
	int id = getoid(me),iHost;
	int Gold,iFavour,iStable,iStore;
	object orgnpc;
	if (MAIN_D->get_host_type()!=2)
		return ;
	iHost = MAIN_D->get_host();
//	if ( iHost == 1 || iHost == 4501 )	//����,�ɻ�������
//		return ;
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	switch(orgnpc->get_grade())
	{
		default:
			break ;
		case 2:
			Gold=5000000; iFavour=1000;iStable=1000;iStore=450;
			break;
		case 3:
			Gold=10000000; iFavour=2000;iStable=2000;iStore=700;
			break;
		case 4:
			Gold=20000000; iFavour=3000;iStable=3000;iStore=1100;
			break;
		case 5:
			Gold=40000000; iFavour=4000;iStable=4000;iStore=1500;
			break;									
	}
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("%s��\n    ���κϲ��������Դ����ɵĲ���������б�Ǹ��Ϊ�˲����󷽵���ʧ��ֻҪ���ǰ��ɵİ������������������ȡһ����Ϊ������������⳥��Ʒ�����ںϲ�������֮��ֻҪ�������ߴ���һ�����ɣ�ֱ��ʹ����������ڰ����ġ������ʽ𡯡��������������������롮���������ת�Ƶ��µİ����С�\n    ���ű����ɹ�ģ�ȼ�Խ�ߣ���ȡ�Ĳ������Խ�࣬����1���İ������ǲ�������κβ����ġ�\n    ��ǰ���ɿ�����ȡ"HIR"%d�����ʽ�"NOR" ��"HIR"%d��������"NOR"��"HIR"%d���ɰ���"NOR"��"HIR"%d���ɴ���"NOR"����ȷ��Ҫ������ȡ������\n"ESC"�ǵģ���Ҫ������ȡ��\ntalk %x# welcome.1\n"ESC"�����´ΰɡ�",me->get_name(),Gold,iFavour,iStable,iStore,id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,iTime,iGrade,iHost;
       	object who, orgnpc,item;
	int Gold,iFavour,iStable,iStore;
       	string name;
	mixed *mxTime;    

	if (MAIN_D->get_host_type()!=2)
		return ;
	iHost = MAIN_D->get_host();
//	if ( iHost == 1 || iHost == 4501 )	//����,�ɻ�������
//		return ;
        who = this_player();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	switch((iGrade=orgnpc->get_grade()))
	{
		default:
			break ;
		case 2:
			Gold=5000000; iFavour=1000;iStable=1000;iStore=450;
			break;
		case 3:
			Gold=10000000; iFavour=2000;iStable=2000;iStore=700;
			break;
		case 4:
			Gold=20000000; iFavour=3000;iStable=3000;iStore=1100;
			break;
		case 5:
			Gold=40000000; iFavour=4000;iStable=4000;iStore=1500;
			break;									
	}		 
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_org_position() != ORG_MASTER )        	
		{
			send_user(who,"%c%s",'!',"�㲻�ǰ������޷���ȡ�⳥��");
			return ;	
		}
		if ( iGrade < 2 )        	
		{
			send_user(who,"%c%s",'!',"��İ��ɹ�ģ����2�����޷���ȡ�⳥��");
			return ;	
		}
		if ( mpOrg[name] )
		{
			send_user(who,"%c%s",'!',"��İ����Ѿ���ȡ�����⳥���޷��ٴ���ȡ��");
			return ;	
		}
		if ( TASK_LEGEND_D->can_carry_amount(who,2) != 1 )
				return ;
		TASK_LEGEND_D->give_item(who,"item/std/0095",1); 
		item = new("item/04/0418");	
		if ( !item )
			return ;
		item->set("special",sprintf("%d|%d|%d|%d",Gold,iFavour,iStable,iStore));
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
			send_user(who,"%c%s",'!',"��İ������������ܵõ��⳥������պ�������");
			return;	
		}
		item->add_to_user(p);
		mpOrg[name] = 1 ;
		save();
		send_user(who,"%c%s",'!',"����ȡ�˰����������֮�Žǡ�");
		log_file("org_buchang.txt",sprintf("%s %s %d\n",short_time(),who->get_name(),who->get_number()));
        	break;
        }

}
