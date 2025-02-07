#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>
#include <effect.h>

inherit OFFICER;
inherit SAVE_F;

int iStart,iFinish;
int mlz;
// ��������ȡ��������
int get_char_picid() { return 8113; }
string get_save_file()	{ return "data/milizhu"SAVE_EXTENSION;}

void do_visit( string arg );
void do_welcome(string arg);
void do_dodolook(string arg);
void do_accept(string arg);
void ask_bonus(object who,string arg);

//int accept_object(object who, object item)
// ���������촦��
void create()
{
	restore();
        set_name("dodolook");
        set_2( "talk", ([
		"visit"		   : (: do_visit :),
                 "welcome"         : (: do_welcome :),
		"dodolook"         : (: do_dodolook :),
                 "accept"          : (: do_accept :),
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
	if (MAIN_D->get_host_type()==2)
		return ;
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ô����ء���\n"
		ESC"�߹������ϴ�\ntalk %x# visit.1\n"
		ESC"Ե�ֶԶ����\ntalk %x# visit.2\n"
		ESC"Ե�ֶԶ����콱\ntalk %x# visit.3\n"
		ESC"�뿪",
		me->get_name(),id,id,id));
}

void do_visit( string arg )
{
        object me = this_object();
        __FILE__ ->do_visit2(me, arg);
}

void do_visit2( object me, string arg )
{
	object who=this_player();
	int id = getoid(me);
        int flag = to_int(arg);
	if (MAIN_D->get_host_type()==2)
		return ;
        switch(flag)
        {
	case 1:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ʿ��ã��ҽ�dodolook��������һ�����磡�������ʱ����ʱ���Ѿ�̫���ˣ�����Ҳ������ҵ�ʱ���Ļ���Ҳ���Ҿ���Զ�ز�ȥ�ˡ�����Ҫ��İ����������ռ��߹��Խ��Խ�ã�ֻҪӵ���㹻���߹���Ҿ��лص�ԭ������Ŀ��ܣ���Ȼ����Ҳ���л��ġ��Ҵ���ʵ���������һЩ�ر������������Ϊл�񣡲�ͬ������������Ӧ��ͬ�������Ȼ����Խ�࣬����Ҳ��Խ���ˣ�\n"
			ESC"�����߹���\ntalk %x# welcome.1\n"
			ESC"�߹���һ�������Ʒ\ntalk %x# welcome.2\n"
			ESC"�鿴�ѽ�������Ŀ\ntalk %x# welcome.7\n"
			ESC"������Ի���߹���\ntalk %x# welcome.8\n"
			ESC"�߹������\ntalk %x# welcome.9\n"
			ESC"�뿪",
			me->get_name(),id,id,id,id,id));
		break;
	case 2:
		if ( who->get_save_2("dodolook_task.finish") )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    Ե����ע���������ڸ���Ŷ��������һ����������Ե�ֵĻ��ᣬ����Ը�������������Ƕ�������׼���˰ɣ���Ȼ��ˣ�Ե�ֵĲ��Ծ�Ҫ��ʼ��Ŷ��\n"ESC"��ȡԵ�ֳ���\ntalk %x# welcome.101\n"ESC"ע������\ntalk %x# welcome.102\n"ESC"���Ե������\ntalk %x# welcome.107\n"ESC"����ȥԵ����վ\ntalk %x# welcome.108\n"ESC"�뿪",me->get_name(),id,id,id,id));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    Ե����ע���������ڸ���Ŷ��������һ����������Ե�ֵĻ��ᣬ����Ը�������������Ƕ�������׼���˰ɣ���Ȼ��ˣ�Ե�ֵĲ��Ծ�Ҫ��ʼ��Ŷ��\n"ESC"��ȡԵ�ֳ���\ntalk %x# welcome.101\n"ESC"ע������\ntalk %x# welcome.102\n"ESC"����Ե������\ntalk %x# welcome.103\n"ESC"����ȥԵ����վ\ntalk %x# welcome.108\n"ESC"�뿪",me->get_name(),id,id,id,id));	
		break;
	case 3:
		ask_bonus(me,"");
		break;
        }

}

/*
void do_look_call(object me,object who)
{
	int id = getoid(me);
	if (MAIN_D->get_host_type()==2)
		return ;
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ʿ��ã��ҽ�dodolook��������һ�����磡�������ʱ����ʱ���Ѿ�̫���ˣ�����Ҳ������ҵ�ʱ���Ļ���Ҳ���Ҿ���Զ�ز�ȥ�ˡ�����Ҫ��İ����������ռ��߹��Խ��Խ�ã�ֻҪӵ���㹻���߹���Ҿ��лص�ԭ������Ŀ��ܣ���Ȼ����Ҳ���л��ġ��Ҵ���ʵ���������һЩ�ر������������Ϊл�񣡲�ͬ������������Ӧ��ͬ�������Ȼ����Խ�࣬����Ҳ��Խ���ˣ�\n"
		ESC"�����߹���\ntalk %x# welcome.1\n"
		ESC"�߹���һ�������Ʒ\ntalk %x# welcome.2\n"
		ESC"�鿴�ѽ�������Ŀ\ntalk %x# welcome.7\n"
		ESC"������Ի���߹���\ntalk %x# welcome.8\n"
		ESC"�߹������\ntalk %x# welcome.9\n"
		ESC"�뿪",
		me->get_name(),id,id,id,id,id));
}*/

void do_welcome(string arg) { __FILE__->do_welcome_call(this_object(),arg); }

void do_welcome_call( object me,string arg )
{
	int flag, p,iTime,i,j,size,id,x,y,z,level,rate,amount;
       	object who, item,*nTeam,member,npc,map,item_q,*inv,*inv2;
       	string name,*nTmp,tmp,result="",result2="",cTmp;
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
		if (iStart==0 || time()<iStart)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���û��ʼ�أ�������鿴�ٷ���վ(zg.mop.com)���档\n"ESC"�뿪",me->get_name(),));
		else if (iStart==1 || (time()>iStart && time()<iFinish))
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ռ����߹������𣿺Ǻǡ���������������ֻ��Ҫ������lt+�Ǽ��������ָ���ң������Ϳ��Ը����ˣ������յ�����߹����ġ��ѽ�������������֮�ۼ����ӣ����ˣ�˵�������ˡ�лл��İ���Ŷ����\n"ESC"�뿪",me->get_name(),));
		else if (iStart==2 || time()>iFinish)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����Ѿ�������лл��Ĳ��룡\n"ESC"�뿪",me->get_name(),));
        	break;
        case 2:
		if (iStart==0 || time()<iStart)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���û��ʼ�أ�������鿴�ٷ���վ(zg.mop.com)���档\n"ESC"�뿪",me->get_name(),));
		else if (iStart==1 || (time()>iStart && time()<iFinish))
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ʵ���߹��Щ�Լ���Ҫ��һЩ����Ʒ����ʵҲ�Ǹ������ѡ��Ŷ�����ٸ�����һ�����ܣ�ѡ������Խ��Ķһ������õ���ƷԽ�����ˡ����������ڶһ���Ʒ���߹�����������ġ��ѽ�����������������Ҫ�����Ŷ����\n"
				ESC"��һ���߹���һ�\ntalk %x# welcome.3\n"
				ESC"�������߹���һ�\ntalk %x# welcome.4\n"
				ESC"������߹���һ�\ntalk %x# welcome.5\n"
				ESC"�뿪",me->get_name(),id,id,id));
		else if (iStart==2 || time()>iFinish)
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����Ѿ�������лл��Ĳ��룡\n"ESC"�뿪",me->get_name(),));
        	break;
        case 3:
        	if( !objectp( item_q = present("�߹���", who, 1, MAX_CARRY) ) )
        	{
        		send_user( who, "%c%s", '!', "����߹�����Զһ���Ӧ��Ʒ��");
        		return;
        	}  
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
		        send_user(who,"%c%s",';',"������һ����İ����������һ���Ʒ�ɣ�");
	    		return;
		}
		item_q->add_amount(-1);
		result2 = sprintf(HIR"%s���"NOR"���߹��λ�У����߹���һ�����"HIR, who->get_name());
		rate = random(1000);
		if (rate<125)
		{
			item = new ("item/std/8000");//�ر�ͼ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=125 && rate<250)
		{
			who->add_cash(10000);
			result = result + HIR"10000��";
		}
		else if (rate>=250 && rate<375)
		{
			who->add_exp(1000);
			result = result + HIR"1000����";
		}
		else if (rate>=375 && rate<500)
		{
			who->add_potential(100);
			result = result + HIR"100Ǳ��";
		}
		else if (rate>=500 && rate<625)
		{
			item = new ("item/91/9161");//���쵤
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=625 && rate<750)
		{
			item = new ("item/91/9162");//��ңɢ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=750 && rate<875)
		{
			item = new ("item/91/9163");//��ɣɢ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=875 && rate<1000)
		{
			item = new ("item/91/9164");//���ĵ�
			result = result + sprintf(HIR"%s",item->get_name());
		}
		if ( item )
		{
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
                		send_user( who, "%c%s", '!', "������һ����İ����������һ���Ʒ�ɣ�");
                		return;
			}
			else
			{
				item->add_to_user(p);	
			}
		}
		send_user(who,"%c%s",'!',"�õ� "+result);
		result += NOR"�������Ǵ�ұ�ʾף�أ�";
//		if (result !="") send_user(USER_D->get_user(), "%c%s", 0xA3, result2+result);
//		USER_D->user_channel(result);	

        	break;
        case 4:
		inv = all_inventory(who, 1, MAX_CARRY);
		
		if( !objectp( item_q = present("�߹���", who, 1, MAX_CARRY) ) )
		{
			send_user(who,"%c%s",'!',"����߹�����?");
			return;	
		}			
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "�߹���" )
				continue;
			amount += inv[i]->get_amount();		
		}
		if ( amount < 2 )
		{
			send_user(who,"%c%s",'!',"����߹�����Զһ���Ӧ��Ʒ��");
			return;	
		}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
		        send_user(who,"%c%s",';',"������һ����İ����������һ���Ʒ�ɣ�");
	    		return;
		}
	        j = 2;
		inv2 = all_inventory(who, 1, MAX_CARRY);
	
		for(i=0,size=sizeof(inv2);i<size;i++)
		{
			if ( !objectp(inv2[i]) )
				continue;
			if ( inv2[i]->get_name() != "�߹���" )
				continue;
	        	if ( inv2[i]->get_amount() <= j )
	        	{
	        		j -= inv2[i]->get_amount();
                		inv2[i]->remove_from_user();
                		destruct(inv2[i]);
                	}
                	else
                	{
                		inv2[i]->set_amount(inv2[i]->get_amount()-j);
                		j = 0;
                	}     
                	if ( j == 0 )
                		break;

		}
		result2 = sprintf(HIR"%s���"NOR"���߹��λ�У����߹���һ�����"HIR, who->get_name());
		rate = random(1000);
		if (rate<100)
		{
			who->add_cash(20000);
			result = result + HIR"20000��";
		}
		else if (rate>=100 && rate<300)
		{
			who->add_exp(5000);
			result = result + HIR"5000����";
		}
		else if (rate>=300 && rate<425)
		{
			who->add_potential(500);
			result = result + HIR"500Ǳ��";
		}
		else if (rate>=425 && rate<625)
		{
			item = new ("item/91/9165");//��Ԫ��
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=625 && rate<750)
		{
			item = new ("item/91/9125");//������
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=750 && rate<875)
		{
			item = new ("item/91/9150");//����ɢ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=875 && rate<1000)
		{
			item = new ("item/91/9160");//������
			result = result + sprintf(HIR"%s",item->get_name());
		}
		if ( item )
		{
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
                		send_user( who, "%c%s", '!', "������һ����İ����������һ���Ʒ�ɣ�");
                		return;
			}
			else
			{
				item->add_to_user(p);	
			}
		}
		send_user(who,"%c%s",'!',"�õ� "+result);
		result += NOR"�������Ǵ�ұ�ʾף�أ�";
//		if (result !="") send_user(USER_D->get_user(), "%c%s", 0xA3, result2+result);
//		USER_D->user_channel(result);	

        	break;
        case 5:
		inv = all_inventory(who, 1, MAX_CARRY);
		
		if( !objectp( item_q = present("�߹���", who, 1, MAX_CARRY) ) )
		{
			send_user(who,"%c%s",'!',"����߹�����?");
			return;	
		}			
		for(i=0,size=sizeof(inv);i<size;i++)
		{
			if ( !objectp(inv[i]) )
				continue;
			if ( inv[i]->get_name() != "�߹���" )
				continue;
			amount += inv[i]->get_amount();		
		}
		if ( amount < 5 )
		{
			send_user(who,"%c%s",'!',"����߹�����Զһ���Ӧ��Ʒ��");
			return;	
		}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
		        send_user(who,"%c%s",';',"������һ����İ����������һ���Ʒ�ɣ�");
	    		return;
		}
	        j = 5;
		inv2 = all_inventory(who, 1, MAX_CARRY);
	
		for(i=0,size=sizeof(inv2);i<size;i++)
		{
			if ( !objectp(inv2[i]) )
				continue;
			if ( inv2[i]->get_name() != "�߹���" )
				continue;
	        	if ( inv2[i]->get_amount() <= j )
	        	{
	        		j -= inv2[i]->get_amount();
                		inv2[i]->remove_from_user();
                		destruct(inv2[i]);
                	}
                	else
                	{
                		inv2[i]->set_amount(inv2[i]->get_amount()-j);
                		j = 0;
                	}     
                	if ( j == 0 )
                		break;

		}

//		result2 = sprintf(HIR"%s���"NOR"���߹��λ�У����߹���һ�����"HIR, who->get_name());
		rate = random(10000);
		if (rate<2400)
		{
			who->add_cash(30000);
			result = result + HIR"30000��";
		}
		else if (rate>=2400 && rate<4999)
		{
			who->add_exp(10000);
			result = result + HIR"10000����";
		}
		else if (rate>=4999 && rate<7499)
		{
			who->add_potential(1000);
			result = result + HIR"1000Ǳ��";
		}
		else if (rate>=7499 && rate<7899)
		{
			cTmp = BOOK_FILE->get_book_file_2();
			item = new (cTmp);//������ɼ����ؼ�
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=7899 && rate<8899)
		{
			
			item = new (sprintf("item/std/800%d",random(4)+1));//��ȱ�ر�ͼ���һ��
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=8899 && rate<9899)
		{
			cTmp = BOOK_FILE->get_book_file();
			item = new (cTmp);//������ɼ��ܽ�����
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9899 && rate<9999)
		{
			if( random(2) ) //�����װ
				item = new( ARMOR_FILE->get_armor_file_2( who->get_level()+10) );
			else
				item = new( WEAPON_FILE->get_weapon_file_2( who->get_level()+10) );
			ITEM_EQUIP_D->init_equip_prop_3(item);
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate==9999 && mlz<10)
		{
			item = new ("item/08/0811");//������
			result = result + sprintf(HIR"%s",item->get_name());
			mlz ++;
			save();
		}
		else if (rate==9999 && mlz>=10)
		{
			who->add_exp(10000);
			result = result + HIR"10000����";
		}
		if ( item )
		{
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
                		send_user( who, "%c%s", '!', "������һ����İ����������һ���Ʒ�ɣ�");
                		return;
			}
			else
			{
				item->add_to_user(p);	
				send_user(USER_D->get_user(), "%c%s", 0xA3, sprintf(HIR"%s���"NOR"���߹��λ�У����߹���һ�����"HIR"%s"NOR"�������Ǵ�ұ�ʾף�أ�",who->get_name(),item->get_name()));
			}
		}
		send_user(who,"%c%s",'!',"�õ� "+result);
//		result += NOR"�������Ǵ�ұ�ʾף�أ�";
//		USER_D->user_channel(result);	

        	break;
        case 7:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ĿǰΪֹ�����Ѿ�������%d���߹����ˣ�лл��Ŷ�����������ٽ���������������Ŷ����\n"ESC"�뿪",me->get_name(),who->get_save("qgl_n")));
        	break;
        case 8:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����߹���ķ����кܶ���Ŷ��������ͨ���������Ի���߹����⣬�㻹����ȥ����������ȼ���Ӧ�Ĺ�������ã�������һ���ļ���Ŷ�������⣬�㻹��ע��һ�㣺20�����ϵĹ������ϲ���Я���߹�����ң�ֻ�д������������5�����ڵĹ���ſ��ܻ�ȡ�����һ���һ��С����Ҫ������Ŷ����������߹��������������߹����ռ�Ա������������ӡ��ѽ���������֮�⣬�����Ի����Ӧ�İﹱ���Ǻǡ�����ǰ���ǣ�����������ɲ��У����ˡ���˵�������ˡ�ȥ��ʼ���ս��ð�հɡ���\n"ESC"�뿪",me->get_name(),));
        	break;
        case 9:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �߹������ֱ�����ҽ��жһ����һ�һЩ��Ϸ������Ʒ������һ�����ϡ�����ġ�������С�����ô��϶����Գ�Ϊ��������ע�Ľ��㡣���������߹���һ����߹���������ۻ�����ġ��ѽ��߹�������У�ֻ��ֱ�Ӹ�����߹������������ġ��ѽ��߹����������ȫ�������߹���������ң�������Ҵ��ִ�������ʵ��󽱡�������ϸ��Ϣ������Ĺ���zg.mop.com�ר���������Ϣ��һ�����Եõ����������Ϣ���һ���һ��С����Ҫ������Ŷ����������߹��������������߹����ռ�Ա������������ӡ��ѽ���������֮�⣬�����Ի����Ӧ�İﹱ���Ǻǡ�����ǰ���ǣ�����������ɲ��У����ˡ���˵�������ˡ�ȥ��ʼ���ս��ð�հɡ���\n"ESC"�뿪",me->get_name(),));
        	break;
	case 101..108:
        case 10091:
        case 10101:	
		"/npc/party/dodolook"->do_welcome_call(me,arg);
		break;
	case 101204:
	case 101205:
		ask_bonus(me,arg);
		break;
	}
}

void do_dodolook(string arg)  { "/npc/party/dodolook"->do_welcome_call(this_object(),arg); }

int accept_object(object me, object item,int amount)
{

	return __FILE__->accept_object2(me, this_object(), item,amount);
}

int accept_object2(object me, object who, object item2,int amount)
{
	if (item2->get_name()!="�߹���"||iStart == 0||iStart == 2|| time()<iStart|| time()>iFinish)
		return 0;
	else
	{
		me->add_save("qgl_n",amount);
		return 1;
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
	tell_user(who,"�������%s��",arg);	
	send_user(who,"%c%s",'!',"���ϴ򱦻������");	
	save();
	return 1;
}

void set_close()
{
	iStart = 2;
	iFinish = time();
	save();
}

//�콱
void ask_bonus(object who,string arg)
{
	int i, flag, type, p, count, status, id, bonus;
	object me;
       	string *nTmp,tmp;
	me = this_player();
	flag = to_int(arg);
	status = me->get_pay_money_buy_item();
	id = getoid(who);
	bonus = me->get_save("phpbonus");
	if (bonus>0)
	{
		me->delete_save("phpbonus");
		__FILE__->give_bonus(me, bonus);
		return;
	}

	if (status==0)
	{
		if ( me->get_beast_amount() >= me->get_beast_max_amount() )
		{
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
				who->get_name()+":\n    ��ĳ���̫���ˣ�������һ���������Ұɡ���\n"
				ESC"�뿪" );
                        return ;
                }	
		count = 2;			
                if( sizeof_inventory(me, 1, MAX_CARRY) > MAX_CARRY - count )
                {
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
				who->get_name()+":\n    ��İ���������������һ����İ����������Ұɡ���\n"
				ESC"�뿪" );
                        return ;
                }	
                flag = 1013;      
                arg = "1013";          
                me->set("phpnum", flag);
		me->set_pay_money_buy_item(1);
		me->set_pay_type(4);
		me->set_buy_item_cmd_string( sprintf("%x# welcome.", getoid(who) ) );
		db_user_pay( me, sprintf( "%s:80\n"
               		"GET http:/""/%s/getgoods.php?t=%s&u=%d&o=%d&n=%s&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
               		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), arg, get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
log_file("php.dat", sprintf( "%s:80\n"
               		"GET http:/""/%s/getgoods.php?t=%s&u=%d&o=%d&n=%s&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
               		MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), arg, get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
		log_file("getitem.txt",sprintf("%s %s %d %s\n",short_time(),me->get_id(),me->get_number(),arg ));
		return ;
	}
	if (status!=8)
	{
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
			who->get_name()+":\n    �����������ڴ����У����Ժ�\n"
			ESC"�뿪" );
	        return ;
	}
	switch(flag)
	{
	case 101204:
		count = 2;
		break;
	case 101205:
		count = 1;
		break;
	}
	if( sizeof_inventory(me, 1, MAX_CARRY) > MAX_CARRY - count )
	{
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
			who->get_name()+":\n    ��İ���������������һ����İ����������Ұɡ���\n"
			ESC"�뿪" );
		me->set_save("phpbonus", flag);
	        return ;
	}
	if ( me->get_beast_amount() >= me->get_beast_max_amount() )
	{
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
			who->get_name()+":\n    ��ĳ���̫���ˣ�������һ���������Ұɡ���\n"
			ESC"�뿪" );
		me->set_save("phpbonus", flag);
	        return ;
	}	
	me->set_pay_money_buy_item(0);
	__FILE__->give_bonus(me, flag);
}

void give_bonus(object who, int type)
{
	int i, p, total, count;
	string cName, *nTmp, tmp;
	object item,pet;
	object me = this_object();
	switch(type)
	{
	case 101204:
		count = 2;
		break;
	case 101205:
		count = 1;
		break;
	default:
		return ;	
	}
	if( sizeof_inventory(who, 1, MAX_CARRY) > MAX_CARRY - count )
	{
		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			get_name()+":\n    ��İ���������������һ����İ����������Ұɡ���\n"
			ESC"�뿪" );
		who->set_save("phpbonus", type);
	        return ;
	}
	if ( type == 101205 && who->get_beast_amount() >= who->get_beast_max_amount() )
	{
		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			get_name()+":\n    ��ĳ���̫���ˣ�������һ���������Ұɡ���\n"
			ESC"�뿪" );
		who->set_save("phpbonus", type);
	        return ;
	}
	log_file("getitem.txt",sprintf("%s %s %d ��ȡ%d�ɹ�\n",short_time(),who->get_id(),who->get_number(),type ));
	switch(type)
	{
        case 101204:	
        	item = new("item/std/8000");
		p = item->move(who,-1);
		item->add_to_user(p);
		item = new("item/std/6003");
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', "���òر�ͼһ�š��鲼����һ��" );
        	break;
        case 101205:
        	nTmp = "quest/pet"->get_level_pet(who->get_level());
        	if ( !sizeof(nTmp) )
        		return ;
        	cName = nTmp[random(sizeof(nTmp))];
        	p = "quest/pet"->get_pet_picid(cName);
        	if ( !p )
        		return ;
        	pet = USER_BEAST_D->give_pet(who,cName,1,0,p,0);
        	pet->send_info();
		item = new("item/std/6003");
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', "����"+cName+"����һֻ���鲼����һ��" );
        	break;
        }
        
}