#include <npc.h>
#include <city.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <equip.h>
inherit SAVE_F;
inherit OFFICER;

int iStart_n,iFinish_n;
#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"


void do_bonus(string arg);
void do_tiger_bonus(string arg);


// ��������ȡ��������
int get_char_picid() { return 0952; }
string get_save_file()	{ return "data/wg_national_ex"SAVE_EXTENSION;}
// ���������촦��
void create()
{
	restore();
        set_name("�һ���ʹ");

        set_2( "talk", ([
                 "bonus"        : (: do_bonus :),
                 "tiger"	: (: do_tiger_bonus :),
        ]) );
//	iStart_n = mktime(2007,9,27,11,0,0);	
//	iFinish_n = mktime(2007,10,8,0,0,0);
        setup();
}

void do_look( object who )
{
	__FILE__->do_look_2(who, this_object());
}

void do_look_2( object who, object me )
{
	int id, iTime;
	string tiger_str = "",national="",ssss,national2="";
	id = getoid(me);
	iTime = get_party_time();
	if(GUESS_TRUE_TIGER->is_active_open()) {
		tiger_str = sprintf(ESC"��ٻ���\ntalk %x# tiger.1\n",id);
	}
	ssss=":\n    ����ɶ������������Խ����Ҷһ���Ʒ�ޡ������ｱƷ�ɷ���ˣ�\n";

	if(iTime<iFinish_n && iTime>iStart_n)
	{
		national2 = sprintf(ESC HIY"�������������\ntalk %x# bonus.43\n",id);
		national = sprintf(ESC HIY"��ȡè�˴��ӻ����ʹ����\ntalk %x# bonus.34\n"
				   ESC HIY"��ȡУ���������ʹ����\ntalk %x# bonus.34\n"
				   ESC HIY"��ȡ�ٷ������������\ntalk %x# bonus.34\n",id,id,id);
//		national += sprintf(ESC"��ȡ������Ϊ��\ntalk %x# bonus.36\n",id);
	}

	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		me->get_name()+ssss
		+ tiger_str + national+ national2
		+ sprintf(ESC"��ɫ��\ntalk %x# bonus.1\n"
			  ESC"�ƽ�ʥ�³ƺŶһ�\ntalk %x# bonus.32\n"
			  ESC"�鿴�ҵ��������\ntalk %x# bonus.33\n"
			  ESC"�뿪", id,id,id) );
}

//	��ٻ����������ȡ
void do_tiger_bonus(string arg) {
	__FILE__->do_tiger_bonus_reflash(this_object(),arg);	
}

//	��ٻ��������ȡ�����߸���
void do_tiger_bonus_reflash(object me,string arg) {
	object who;
	string say_word;
	string *active_bonus;
	int level,flag,id;
	who  = this_player();
	id   = getoid(me);
	flag = to_int(arg);
	level= who->get_save("guess_true_tiger");
	if(who->get_save("guess_true_tiger_fight")) {
		GUESS_TRUE_TIGER->delete_tigers_on_player(who);
		who->delete_save("guess_true_tiger");
		level = 0;
	}
	switch(flag) {
		case 1:
			if(level>0) {
				if(level >= 6 ) {
					say_word = "��̫�����ˣ���Ȼ����6�أ�������ȡ100��ս��������������뷨���ƺŵĽ�����";
				} else {
					active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
					if(level > 1) {
						say_word = sprintf("��һ������%d�أ�������ȡ%sս���Һ͡�"HIR"%s"NOR"���ƺŵĽ�����",level,active_bonus[2],active_bonus[1]);
					} else {
						say_word = sprintf("��һ������%d�أ�������ȡ��"HIR"%s"NOR"���ƺŵĽ�����",level,active_bonus[1]);
					}
				}
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n%s\n"
					ESC"��ȡ����\ntalk %x# tiger.2\n"
					ESC"�뿪",me->get_name(),say_word,id
				));
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n��Ϊʲô������ȥ����������ص���Ϸ�أ�\n"ESC"�뿪",me->get_name()));
			}
			break;
		case 2:
			if(level>0) {
				active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);				
				who->add_cash(to_int(replace_string(active_bonus[2],",","")));
				if(level >1) {
					send_user( who, "%c%s", '!', sprintf(HIY"���Ľ�Ǯ������ %s��",active_bonus[2]));
				}				
				who->delete_save("guess_true_tiger");
				if(who->have_title(active_bonus[0])) {
					send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ��������ĳƺ��ˣ�\n"ESC"�뿪",me->get_name()));
					return ;
				}
				who->add_title(active_bonus[0]);
				who->show_title(active_bonus[0]);
				send_user( who, "%c%s", ';', sprintf(HIY"���һ���%s�ĳƺš�",who->get_title()));
			}
			break;
	}
}

void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_object(),arg);
}

void do_bonus_2(object me , string arg)
{
	int flag, p,iTime,i,j,size,id,x,y,z,level,rate,amount,count;
       	object who,item,*nTeam,member,npc,map,item_q,item_q2,item_q3,item_q4,*inv,*inv2;
       	string name,*nTmp,tmp,result="",result2="",cTmp,national2,ssss;
        string result_key="", *key=({});
	mixed *mxTime;  
	int *armor=({101,102,104,105,106});
	iTime = get_party_time();

	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);

        switch(flag)
        {
        case 1:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ս���ĸ�·��ħ���æ�Ĳ����ֺ������ڻ���׼����չְҵ�����������������Ǳ����ĳ����ƻ��˺ܶ�ս�����յ������Ϊһ��ս���е���ʿ���������������Թۣ���֪����ʿ͸¶��Ϊ�˱�ս������ÿ�����ﶼ����Я�����������ţ�ֻҪ���ǽ����ǵ�����������������Ӱ�����ǵı������������յ���أ�\n    ������л�����졢�������򶼿����������Ҷһ���Ʒ��������Լ�ѡ��һ���ʽ��\n"
			ESC"����һ�����\ntalk %x# bonus.2\n"
			ESC"����һ�����\ntalk %x# bonus.7\n"
			ESC"����һ�����\ntalk %x# bonus.12\n"
			ESC"����һ�����\ntalk %x# bonus.17\n"
			ESC"��ֻ��(��+��)�һ�2�Ųر�ͼ\ntalk %x# bonus.22\n"
			ESC"��ֻ��(��+��+��)�һ��ϲε�\ntalk %x# bonus.24\n"
			ESC"��ֻ��(��+��+��+��)�һ���ɫװ��\ntalk %x# bonus.26\n"
			ESC"��ֻ��(��+��)�һ������Ʒ\ntalk %x# bonus.28\n"
			ESC"��ֻ��(��+��+��)�һ������Ʒ\ntalk %x# bonus.30\n"
			ESC"�뿪",me->get_name(),id,id,id,id,id,id,id,id,id));
        	break;
        case 2:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������һֻ����һ����½�����\n"
			ESC"һֻ����һ�5�Żذ��\ntalk %x# bonus.3\n"
			ESC"һֻ����һ�10�ŷ��з�\ntalk %x# bonus.5\n"
			ESC"�뿪",me->get_name(),id,id));
        	break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ�5�Żذ����\n"
			ESC"ȷ��\ntalk %x# bonus.4\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 4:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/0410");//�ذ��
		item->set_amount(5);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ����һ���5�Żذ��");
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ�10�ŷ��з���\n"
			ESC"ȷ��\ntalk %x# bonus.6\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 6:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/0409");//���з�
		item->set_amount(10);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ����һ���10�ŷ��з�");
        	break;
        case 7:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������һֻ����һ����½�����\n"
			ESC"һֻ����һ�1�Ųر�ͼ\ntalk %x# bonus.8\n"
			ESC"һֻ����һ�10�Ż�����\ntalk %x# bonus.10\n"
			ESC"�뿪",me->get_name(),id,id));
        	break;
        case 8:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ�1�Ųر�ͼ��\n"
			ESC"ȷ��\ntalk %x# bonus.9\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 9:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/8000");//�ر�ͼ
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ����һ���1�Ųر�ͼ");
        	break;
        case 10:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ�10�Ż�������\n"
			ESC"ȷ��\ntalk %x# bonus.11\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 11:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/91/9101");//������
		item->set_amount(10);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ����һ���10�Ż�����");
        	break;
        case 12:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������һֻ����һ����½�����\n"
			ESC"һСʱ��������Ѫ����200��\ntalk %x# bonus.13\n"
			ESC"һСʱ�����ӷ�������200��\ntalk %x# bonus.15\n"
			ESC"�뿪",me->get_name(),id,id));
        	break;
        case 13:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ���һСʱ��������Ѫ����200�㡱����ʱЧ����\n"
			ESC"ȷ��\ntalk %x# bonus.14\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 14:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_HP) )
		{
			send_user(who, "%c%s", ';', "���Ѿ�ӵ�и���ʱЧ���ˡ�");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_HP, 3600);//+HP
	        USER_ENERGY_D->count_max_hp(who);
		send_user( who, "%c%w%w%c", 0x81, 0443, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "����һֻ����һ��ˡ�һСʱ��������Ѫ����200�㡱����ʱЧ��");
        	break;
        case 15:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ���һСʱ�����ӷ�������200�㡱����ʱЧ����\n"
			ESC"ȷ��\ntalk %x# bonus.16\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 16:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_MP) )
		{
			send_user(who, "%c%s", ';', "���Ѿ�ӵ�и���ʱЧ���ˡ�");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_MP, 3600);//+MP
	        USER_ENERGY_D->count_max_mp(who);
		send_user( who, "%c%w%w%c", 0x81, 0444, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "����һֻ����һ��ˡ�һСʱ�����ӷ�������200�㡱����ʱЧ��");
        	break;
        case 17:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������һֻ����һ����½�����\n"
			ESC"һСʱ��������������100��\ntalk %x# bonus.18\n"
			ESC"һСʱ�����ӷ���������100��\ntalk %x# bonus.20\n"
			ESC"�뿪",me->get_name(),id,id));
        	break;
        case 18:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ���һСʱ��������������100�㡱����ʱЧ����\n"
			ESC"ȷ��\ntalk %x# bonus.19\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 19:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_AP) )
		{
			send_user(who, "%c%s", ';', "���Ѿ�ӵ�и���ʱЧ���ˡ�");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_AP, 3600);//+AP
	        USER_ENERGY_D->count_ap(who);
		send_user( who, "%c%w%w%c", 0x81, 0445, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "����һֻ����һ��ˡ�һСʱ��������������100�㡱����ʱЧ��");
        	break;
        case 20:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ�������һ���һСʱ�����ӷ���������100�㡱����ʱЧ����\n"
			ESC"ȷ��\ntalk %x# bonus.21\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 21:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_CP) )
		{
			send_user(who, "%c%s", ';', "���Ѿ�ӵ�и���ʱЧ���ˡ�");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_CP, 3600);//+CP
	        USER_ENERGY_D->count_cp(who);
		send_user( who, "%c%w%w%c", 0x81, 0446, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "����һֻ����һ��ˡ�һСʱ�����ӷ���������100�㡱����ʱЧ��");
        	break;
        case 22:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ������һֻ�������һ�2�Ųر�ͼ��\n"
			ESC"ȷ��\ntalk %x# bonus.23\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 23:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item = new ("item/std/8000");//�ر�ͼ
		p = item->move(who,-1);
		item->add_to_user(p);	
		item = new ("item/std/8000");//�ر�ͼ
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ������һֻ����һ���2�Ųر�ͼ");
        	break;
        case 24:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ����һֻ������һֻ�������һ��ϲε���\n"
			ESC"ȷ��\ntalk %x# bonus.25\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 25:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);
		item = new ("item/91/9167");//�ϲε�
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "����һֻ����һֻ������һֻ����һ����ϲε�");
		CHAT_D->sys_channel( 0, CHAT+sprintf("��ϲ"HIR"%s"NOR"��ý�Ʒ"HIR"%s" ,who->get_name(),item->get_name())); 
        	break;
        case 26:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ�úڡ������졢�����һֻ���һ���ɫװ����\n"
			ESC"ȷ��\ntalk %x# bonus.27\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 27:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q4 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);
		item_q4->add_amount(-1);
		level=who->get_level();
		if (level>120) level=120;
		if (level>50 && who->get_fam_name()=="") level=50;
		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),level,armor[random(5)]);
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return ;
		item = new(tmp);
		item->set_record(1);
		ITEM_EQUIP_D->init_equip_prop_3(item);
		if (item->get_item_color() != 2) 
		{
			item->set_item_color(2);
			item->set_bind(1);
		}
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who,"%c%s",';',sprintf("���úڡ������졢�����һֻ�һ��˽�ɫװ���� %s",item->get_name()));
		CHAT_D->sys_channel( 0, CHAT+sprintf("��ϲ"HIR"%s"NOR"��ý�Ʒ"HIR"%s" ,who->get_name(),item->get_name())); 
        	break;
        case 28:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ����ֻ��ͬ�����򣨺�+�������һ������Ʒ��\n"
			ESC"ȷ��\ntalk %x# bonus.29\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 29:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);

		rate = random(10000);
		if (rate<3000)
		{
			amount = 5000+random(10001);
			who->add_cash(amount);
			result = result + sprintf(HIR"%d��",amount);
		}
		else if (rate>=3000 && rate<6000)
		{
			amount = 5000+random(5001);
			who->add_exp(amount);
			result = result + sprintf(HIR"%d����",amount);
		}
		else if (rate>=6000 && rate<9000)
		{
			amount = 100+random(200);
			who->add_potential(amount);
			result = result + sprintf(HIR"%dǱ��",amount);
		}
		else if (rate>=9000 && rate<9300)
		{
	        	item = new("item/std/6003");		//�鲼����
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9300 && rate<9600)
		{
	        	item = new("item/44/4488");		//������＼�ܵ�
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9600 && rate<9800)
		{
	        	item = new("item/91/9125");		//������
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9800 && rate<9900)
		{
	        	item = new("item/91/9160");		//������
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9900 && rate<10000)
		{
	        	item = new("item/91/9161");		//���쵤
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		if ( item )
		{
			p = item->move(who,-1);
			item->add_to_user(p);	
		}
		send_user(who, "%c%s", ';', sprintf("����һֻ������һֻ����һ���%s",result));
		if (result2 != "") CHAT_D->sys_channel( 0, CHAT+sprintf("��ϲ"HIR"%s"NOR"��ý�Ʒ"HIR"%s" ,who->get_name(),result2)); 
        	break;
        case 30:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��һֻ����һֻ������һֻ�������һ������Ʒ��\n"
			ESC"ȷ��\ntalk %x# bonus.31\n"
			ESC"�뿪",me->get_name(),id));
        	break;
        case 31:
        	if( !objectp( item_q = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("����", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ������Զһ��ý�Ʒ�����������ռ��������������Ұɣ�\n"ESC"�뿪",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ���Ʒ�ɡ�\n"ESC"�뿪",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);

		rate = random(10000);
		if (rate<3600)
		{
			cTmp = BOOK_FILE->get_book_file();
			item = new (cTmp);//������ɼ��ܽ�����
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=3600 && rate<5000)
		{
			item = new ("item/91/9167");//�ϲε�
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=5000 && rate<6100)
		{
			item = new ("item/91/9162");//��ңɢ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=6100 && rate<7200)
		{
			item = new ("item/91/9163");//��ɣɢ
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=7200 && rate<8300)
		{
			item = new ("item/91/9164");//���ĵ�
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=8300 && rate<9400)
		{
			item = new ("item/91/9165");//��Ԫ��
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9400 && rate<10000)
		{
			level=who->get_level();
			if (level>120) level=120;
			if (level>50 && who->get_fam_name()=="") level=50;
			nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),level,armor[random(5)]);
			tmp = nTmp[random(sizeof(nTmp))];
			if ( !stringp(tmp) )
				return ;
			item = new(tmp);
			item->set_record(1);
			ITEM_EQUIP_D->init_equip_prop_3(item);
			if (item->get_item_color() != 2) 
			{
				item->set_item_color(2);
				item->set_bind(1);
			}
		}
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', sprintf("����һֻ����һֻ������һֻ����һ���%s",item->get_name()));
		CHAT_D->sys_channel( 0, CHAT+sprintf("��ϲ"HIR"%s"NOR"��ý�Ʒ"HIR"%s" ,who->get_name(),item->get_name())); 
//		USER_D->user_channel(result);	
        	break;
        case 32:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������Խ�࣬���ܹ��һ����ĳƺ�Խ�߼���\n"
		ESC"5������һ�����ͭʥ��ʿ���ƺ�\ntalk %x# bonus.1005\n"
		ESC"10������һ�������ʥ��ʿ���ƺ�\ntalk %x# bonus.1010\n"
		ESC"50������һ����ƽ�ʥ��ʿ���ƺ�\ntalk %x# bonus.1050\n"
		ESC"100������һ�������ʥ��ʿ���ƺ�\ntalk %x# bonus.1100\n"
		ESC"�뿪",me->get_name(),id,id,id,id,));
        	break;
        case 33:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����������Ϊ%d�֡�\n"ESC"�뿪",me->get_name(),who->get_save("warrior_title")));
        	break;
        case 34:
		if (who->get_level()>=40||who->get_level()<10)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ε���Ʒ��ר��������ֵģ����ֻ��"HIR"10����39��"NOR"����Ҳ�����ȡ��Щ���\n"ESC"�뿪\n",me->get_name()));
			return;
		}
		if (who->get_save("wg_national_new"))
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ô����ʯ��Ч������ɡ���������������������֮���Ч��һ������ߡ�\n"ESC"�뿪\n",me->get_name()));
			return;
		}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ʮ���ˣ�������װ�������в�ͬ��Ҫ���ˣ��Ҿ�������4�ſ��Ը�����װ���������Ե�"HIR"��ʯ"NOR"������㰴�մӵ͵��ߵĵȼ�˳�����ν�������ͬ���Ե�2�ž�ʯ�������������߷����ϣ���ῴ�����ǵĹ�����ǿ����Ŷ����ס����Щ��ʯ"HIR"ֻ��20������"NOR"��װ����Ч��\n    ������Щ��ʯ�⣬��λ�ɰ���˫��С������14���ڶ����������Ŷ��\n"ESC"��ȡ\ntalk %x# bonus.35\n",me->get_name(),id));
        	break;
        case 35:
		if( iTime<iFinish_n && iTime>iStart_n && !who->get_save("wg_national_new") && who->get_level()<40 && who->get_level()>=10 )
		{
			if(USER_INVENTORY_D->count_empty_carry(who) < 5 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������û���㹻�Ŀ�λ������һ��������ȡ�ɡ�\n"ESC"�뿪",me->get_name()));
		    		return;
			}
			item = new ("item/08/0831");//˫�����
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9343");//��������ʯ
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9345");//���ֻ�ʯ
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9343");//��������ʯ
			item->set_level(2);
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9345");//���ֻ�ʯ
			item->set_level(2);
			p = item->move(who,-1);
			item->add_to_user(p);
			who->set_save("wg_national_new",1);
			send_user(who, "%c%s", ';', "����ȡ���Ŀž�ʯ��һ��˫�����");
		}
        	break;
//        case 36:
//		if (who->get_save_2("online_rank.level")<27 )
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������Ϊ�ȼ�������27�����ﵽ27��֮��������ȡ�ɡ�\n"ESC"�뿪\n",me->get_name()));
//			return;
//		}
//		if (who->get_save("wg_national_new"))
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ���ȡ��˫�������\n"ESC"�뿪\n",me->get_name()));
//			return;
//		}
//		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    Ϊ�˻�������ҶԴ�ս����֧�֣�ֻҪ��Ϊ�ȼ��ﵽ��27�������������������ȡһֻ�����˫�������ͳ��\n"ESC"��ȡ\ntalk %x# bonus.37\n",me->get_name(),id));
//        	break;
//        case 37:
//		if( iTime<iFinish_n && iTime>iStart_n && !who->get_save("wg_national_new") && who->get_save_2("online_rank.level")>=27 )
//		{
//			if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
//			{
//				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������û���㹻�Ŀ�λ������һ��������ȡ�ɡ�\n"ESC"�뿪",me->get_name()));
//		    		return;
//			}
//			item = new ("item/08/0831");//˫�����
//			p = item->move(who,-1);
//			item->add_to_user(p);	
//			who->set_save("wg_national_new",1);
//			send_user(who, "%c%s", ';', "����ȡ��һ��˫�����");
//		}
//        	break;
        case 38:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����������Ʒ��һ���ɽ���ʯ��һ�����޿���һ��³�౦ʯ��һ���Ͻ�Կ�ס�һ�������������һ�ű��׷���һ��ս���һ��֥�鿪�š�һ���������һ���з�������һ���˲�����һ�����Һ�һ��ħ������ͬʱ����һ���ں�200Ԫ���Ĵ�����\n    Ҫ��ȡ�����������һ���ȡ��390Ԫ������ȷ����Ҫ��\n"
			ESC"��Ȼ�ﳬ��ֵ����Ҫ���Ϲ���\ntalk %x# bonus.42\n"
			ESC"���ȿ���һ��",me->get_name(),id));
        	break;
        case 39:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ������������Ʒ�����󶨣������͸����ѣ���������ѿ��Ժ���һ�𻶶ȹ��졣ͬʱҲ���Խ��׺Ͱ�̯����Ŷ����Ϊ�Ǻ������������ֻ���ڹ����ڼ��ڳ��ۡ�\n"
			ESC"��������",me->get_name()));
        	break;
        case 40:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����������Ʒ��һ���ɽ���ʯ��һ�����޿���һ��³�౦ʯ��һ���Ͻ�Կ�ס�һ�������������һ�ű��׷���һ��ս���һ��֥�鿪�š�һ���������һ���з�������һ���˲�����һ�����Һ�һ��ħ������һ���ں�200��Ԫ���ĺ����\n"
			ESC"����������ܷḻŶ",me->get_name()));
        	break;
        case 41:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��Ŷ�����������ֻ�ڹ����ڼ����Ŷ������˾�̫��ϧ�ˡ�Ҫ��Ҫ��͵͵Ϊ��Ԥ��һ�ݣ��ٺ٣�\n"
			ESC"�뿪",me->get_name()));
        	break;
        case 42:
		if (who->get_pay_money_buy_item()>0)
		{
			send_user(who,"%c%s",'!',"�����������ڴ����У����Ժ�");
			return ;
		}
		who->set_pay_money_buy_item(1);    // ��ѯ���
		who->set_pay_type(8);
		who->set_buy_item_cmd_string( sprintf("%x# bonus", getoid(me) ) );
		db_user_pay( who, sprintf( "%s:80\n"
			"GET http:/""/%s/querybalance.php?t=%s&u=%d\r\n", MAIN_D->get_php_ip(),
			MAIN_D->get_php_ip(), short_time_2(), who->get_acountid() ) );
        	break;
	case 43:
		ssss=":\n    ��ɫ��Ũ��ϲ�콥�֡��������ո������۵���ζ�жȹ��ˣ������������ֵ������������ˡ��ڴ�����ͬ����������ս����������������ַǷ���Ϊʲô�أ�����Ϊ�����������������������ر�������ػݵļ۸�ÿ�״��������390Ԫ���������ﳬ��ֵ��ιιι����Ҫ����Ҫ�����Ŷ�һ��һ����Ŷ��\n";
		national2 = sprintf(ESC HIY"�ֿ��������ޣ����ϵ�����빺��\ntalk %x# bonus.38\n"
				    ESC"�����˽����ϸ�����\ntalk %x# bonus.39\n"
				    ESC"���뿴һ�´��������ʲô����Ŷ\ntalk %x# bonus.40\n"
				    ESC"���ҳ�ֵ����˵\ntalk %x# bonus.41\n",id,id,id,id);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��"+ssss+national2+
			ESC"�뿪",me->get_name()));
		break;


        case 1005:
        case 1010:
        case 1050:
        case 1100:
        	count = flag - 1000;
        	if ( count == 5 )
        		tmp = "A009";
        	else if ( count == 10 )
        		tmp = "A010";
        	else if ( count == 50 )
        		tmp = "A011";
        	else if ( count == 100 )
        		tmp = "A012";
		if ( who->have_title(tmp) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ѿ��������ĳƺ��ˣ�\n"ESC"�뿪",me->get_name()));
			return ;
		} 
		amount = who->get_save("warrior_title");
		if ( amount < count )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���Ļ��ֲ����Զһ��óƺ�\n"ESC"�뿪",me->get_name()));
			return ;	
		}
		who->add_save("warrior_title",-count);
		who->add_title(tmp);
		who->show_title(tmp);
		send_user( who, "%c%s", ';', sprintf(HIY"���һ���%s�ĳƺš�",who->get_title()) );
		break;
	}
}

// ��������ȡ����(����)
string get_loop_desc1( object me )
{
        return "һСʱ��������Ѫ����200��\n";
}

string get_loop_desc2( object me )
{
        return "һСʱ�����ӷ�������200��\n";
}

string get_loop_desc3( object me )
{
        return "һСʱ������������100��\n";
}

string get_loop_desc4( object me )
{
        return "һСʱ�����ӷ�������100��\n";
}

//��������
void set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2;
	if ( sscanf(arg ,"%s-%s",cTmp1,cTmp2) != 2 )
	{
		send_user(who,"%c%s",'!',"����ĸ�ʽ��");	
		return 0;
	}
	//20070518 2000
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart_n = mktime(year,mon,day,hour,min,0);	//���ʼʱ��

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish_n = mktime(year,mon,day,hour,min,0);	//����ʱ��

	if ( !iStart_n || !iFinish_n )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡");	
		return 0;
	}
	if ( iStart_n > iFinish_n || iFinish_n < time() )
	{
		send_user(who,"%c%s",'!',"�����ʱ�䣡��");	
		return 0;
	}
	tell_user(who,"��������������%s��",arg);	
	send_user(who,"%c%s",'!',"��������������");
	save();
}

//�ر�����
void set_close(object who)
{
	iStart_n = 0;
	iFinish_n = 0;
	send_user(who,"%c%s",'!',"���������رգ�");
	save();
}
//�Ƿ������
int is_open()
{
	int iHour = time();
	if(!iStart_n || !iFinish_n)
	{
		return 0;
	}
	if(iHour >= iStart_n && iHour < iFinish_n)
	{
		return 1;
	}
	else if(iHour >= iFinish_n)
	{
		return 0;
	}	
}