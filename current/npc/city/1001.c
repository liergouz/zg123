
// �Զ����ɣ�/make/npc/make8001

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define EMPEROR_D       "/inh/city/emperor"
#define EMPEROR_2_D     "/inh/city/emperor2"

inherit OFFICER;

void do_policy( string arg );
void do_relation( string arg );
void do_master( string arg );
void do_advice( string arg );

// ��������ȡ��������
int get_char_picid() { return 5101; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����");
	set_real_name("�ｨ");
        set_city_name("���");

        set_2( "talk", ([
                "policy"        : (: do_policy :),
                "relation"      : (: do_relation :),
                "master"        : (: do_master :),
                "advice"        : (: do_advice :),
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",37);
//        set("legend",({32*13+16}));
 	set("mpLegend",([35:({32*13+16}),70:({32*24+7}),100:({32*36+26}),110:({32*45+7})]));
 	set("mpLegend2",([35:({32*13+18,32*13+21,}),70:({32*24+16,32*24+30,32*36+2,32*36+5,}),110:({32*45+9,32*45+12,}),]));
        setup();
}

string get_master() { return CITY_QI->get_master(); }
string get_master_2() { return CITY_QI->get_master_2(); }
string get_master_3() { return CITY_QI->get_master_3(); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( (who->get_level() >= 35 && !who->get_legend(TASK_13,16)) || ( who->get_legend(TASK_13,16) && !who->get_legend(TASK_13,18) ) )
	{
		tmp = sprintf(ESC HIY "ɽ�ֹ���ϸ\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_legend(TASK_13,18) && !who->get_legend(TASK_13,19)) || ( who->get_legend(TASK_13,19) && !who->get_legend(TASK_13,21) ) )
	{
		tmp += sprintf(ESC HIY "������ʹ��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_legend(TASK_13,21) && !who->get_legend(TASK_10,1)) || ( who->get_legend(TASK_10,1) && !who->get_legend(TASK_10,2) ) )
	{
		tmp += sprintf(ESC HIY "���Ÿ�����\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >= 70 && !who->get_legend(TASK_24,7)) || (who->get_legend(TASK_24,15) && !who->get_legend(TASK_24,16)) )
	{
		tmp += sprintf(ESC HIY "���򻨲�\ntalk %x# welcome.7\n",getoid(me));
	}
	if ( who->get_legend(TASK_24,29) && !who->get_legend(TASK_24,30) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.10\n",getoid(me));
	if ( who->get_legend(TASK_36,1) && !who->get_legend(TASK_36,2) )
		tmp += sprintf(ESC HIY "������ʯ\ntalk %x# welcome.12\n",getoid(me));
	if ( (who->get_legend(TASK_36,2) && !who->get_legend(TASK_36,3)) || (who->get_legend(TASK_36,3) && !who->get_legend(TASK_36,5)) )
		tmp += sprintf(ESC HIY "�ռ���ʯ\ntalk %x# welcome.12\n",getoid(me));
	if ( who->get_legend(TASK_36,5) && !who->get_legend(TASK_36,6) )
		tmp += sprintf(ESC HIY "��ҩ\ntalk %x# welcome.12\n",getoid(me));
	if ( who->get_level() >= 100 && !who->get_legend(TASK_36,26) )
		tmp += sprintf(ESC HIY "���������\ntalk %x# welcome.17\n",getoid(me));
	if ( me->get_city_name() == who->get_city_name() )
	{
		if ( who->get_legend(TASK_40,13) && !who->get_legend(TASK_40,14) )
			tmp += sprintf(ESC HIY "������֮�Ž�\ntalk %x# welcome.19\n",getoid(me));
		else if ( who->get_legend(TASK_40,14) && !who->get_legend(TASK_40,15) )
			tmp += sprintf(ESC HIY "��֮�Žǵĵ���\ntalk %x# welcome.19\n",getoid(me));
		else if ( who->get_legend(TASK_40,15) && !who->get_legend(TASK_40,16)&& gone_time(who->get_save("wangzhhj"))>=86400 )
			tmp += sprintf(ESC HIY "��ȡ��֮�Ž�\ntalk %x# welcome.19\n",getoid(me));
	}
	if ( (who->get_level() >= 110 && !who->get_legend(TASK_45,7)) || (who->get_legend(TASK_45,7) && !who->get_legend(TASK_45,9)) )
	{
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.23\n",getoid(me));
	}
	if ( (who->get_legend(TASK_45,9) && !who->get_legend(TASK_45,10)) || (who->get_legend(TASK_45,10) && !who->get_legend(TASK_45,12)) )
	{
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.23\n",getoid(me));
	}
	if ( who->get_legend(TASK_45,12) && !who->get_legend(TASK_45,13) )
	{
		tmp += sprintf(ESC HIY "�����Ҷ\ntalk %x# welcome.23\n",getoid(me));
	}
	if ( who->get("master.type") != 69 && sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		EMPEROR_D->do_look( who, this_object() ); 
	
}
void do_policy( string arg ) { EMPEROR_D->do_policy( this_player(), this_object(), arg ); }
void do_relation( string arg ) { EMPEROR_2_D->do_relation( this_player(), this_object(), arg ); }    // ## 2 ##
void do_master( string arg ) { EMPEROR_D->do_master( this_player(), this_object(), arg ); }

void do_advice( string arg ) { EMPEROR_D->do_advice( this_player(), this_object(), arg ); }

// �����İ���Ʒ
int accept_object( object player, object obj ) 
{
	object who = this_object();
	return TASK_MASTER_D->accept_object( who, player, obj ); 
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if (who->get_level() >= 35 && !who->get_legend(TASK_13,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ȣ�˵����һ��ɽ���徭���ַ����ǣ���Ȼ��ɽ���彮����С�������ǵ�սʿÿ�γ�ս����������������̬���������ǵľ��Ӻ�ǿ����ʹ��˵������ɽ����߽����ϰ��ն�������������ϣ���������ɱ�Ԯ�����ǡ�\n    �����ǵ�̽�ӻر�����һ����ϸ�ѻ�������������ڰ���ׯ�ڵĶ��߽�����������̤�������ܿ�������ׯ�ˣ�ȥ�ɣ�ɱ�����������һ��������ͣ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,16) && !who->get_legend(TASK_13,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������ϸ�ǵ���֮����ͷ�ȴ��£���Ϊʲô��������ʱ���أ����죬֪����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,17) && !who->get_legend(TASK_13,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ͷ�������ˣ����˾Ϳ��Է��Ĵ��������֧Ԯ�����ˣ�����Ǵ󹦳�����\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_13,18) && !who->get_legend(TASK_13,19))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ�����Ѿ�������ɽ�����ϸ�����ǲ�û�н�����Ǹ������������в����Ϊɽ����ȥ�˹���������Ԯ������������Ҳ�ɳ���ʹ�����������£����ڣ�������ʹ���ѽ���������ڣ�����̫����������ЪϢ��������ҳ���������ʹ�������ͷ�󻼣�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_13,19) && !who->get_legend(TASK_13,20))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ù������ʹ�ڰ�ȫ����ɽ���壬��ô���Ǿ��Ǳ�Ϊ�顢��ͨһ���ˣ���������ֵô���ˮ�����֮���ˣ��������������ʹ�ڵ�������þ����ò��ǣ�\n"ESC"�뿪", me->get_name()));
        	else if (who->get_legend(TASK_13,20) && !who->get_legend(TASK_13,21))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ģ���Ȼ���Ѿ�������������ɽ����ļ�ϸ�͹������ʹ�ڣ���ô����Щ�ͽ��������������\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if  ( who->get_legend(TASK_13,21) && !who->get_legend(TASK_10,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ɽ�����ϸ�͹�����ʹ�ڶ��ѱ������������ҹ��Ĵ󹦳���\n    �����ҵ�������ٻ��ڵȴ��ҵ���������ҵ����٣�˵ս����ͣ���������ٻع���\n    ���پ���ˮ鿻���������ǣ���������﹫����ֱ�ӵ�ˮ鿻��������ȥ�ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_10,1) && !who->get_legend(TASK_10,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �㾡��ȥ�ɣ��ɱ����ҵ�������ٵȾ��ˣ�������ˮ鿻�������ڴ���\n"ESC"�뿪", me->get_name()));
        	break;
	case 2:
        	if ( who->get_legend(TASK_13,21) && !who->get_legend(TASK_10,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_10,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,8,"���Ÿ����٣�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ÿ����٣�3��");
        	}
        	break;
	case 3:
        	if (who->get_level() >= 35 && !who->get_legend(TASK_13,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,6,"ɽ�����ϸ��1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ɽ�����ϸ��1��");
        	}
        	break;
        case 4:
        	if ( who->get_legend(TASK_13,17) && !who->get_legend(TASK_13,18) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,18);
			who->add_exp(3800);
			who->add_potential(120);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"ɽ�����ϸ��1�� ���� 3800 Ǳ�� 120 ��Ǯ 3500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,6,"" );        		
			me->do_welcome(1);
        	}
        	break;
	case 5:
        	if (who->get_legend(TASK_13,18) && !who->get_legend(TASK_13,19) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,19);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,7,"������ʹ�ڣ�2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ʹ�ڣ�2��");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_13,20) && !who->get_legend(TASK_13,21) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,21);
			who->add_exp(3900);
			who->add_potential(125);
			who->add_cash(3500);
			send_user(who,"%c%s",';',"������ʹ�ڣ�2�� ���� 3900 Ǳ�� 125 ��Ǯ 3500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,7,"" ); 
			me->do_welcome(1);       		
        	}
        	break;
        case 7:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_24,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ϊ�˳ư��߹��������������ʳ����ζ��ҹ�����ߡ����˸��߱������ڳ��������һ�����򻨲��������ʳ�����ٽ�˯�ߡ���������Ϊһ��֮���ǲ���������뿪�Լ��Ĺ��ҵģ����Ա���������ȥ����������汾��Ѱ���������򻨲裬��ʱ����һ���úó�л��ġ�������ȥ��������Щ�����İ���̸һ̸��\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_24,15) && !who->get_legend(TASK_24,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������Ȼû�п����ˣ���������汾���һ�������Ũ�˱ǵ����򻨲裬���������ֿ���רע����ľ����ڳư��߹��İ�ҵ�ˡ�����˵��һ��Ҫ�úó�л��ģ���ͱ�����ˣ���Щ����Ӧ�õģ�������°ɡ�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
 
        	break;
        case 8:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_24,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_24,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,15,"���򻨲裨1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���򻨲裨1��");
        	}
        	break; 
        case 9:
        	if ( who->get_legend(TASK_24,15) && !who->get_legend(TASK_24,16) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ѩˮ",1) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"���򻨲�",1) != 1 )
        		{
				item = new("item/98/0114");
				if ( !item  )
					return ;
				p = item->move(who,-1);
				if ( !p )
				{
					destruct(item);
					return;
				}
				item->add_to_user(p);
        			return;
        		}
        		TASK_LEGEND_D->give_item(who,"item/product/65075",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_24,16);
			who->add_exp(63000);
			who->add_potential(860);
			who->add_cash(63000);
			send_user(who,"%c%s",';',"���򻨲裨4�� ���� 63000 Ǳ�� 860 ��Ǯ 63000 �Ļ�����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,31,"" );
			me->do_welcome(9);
        	}
        	break;
        case 10:
		if ( who->get_legend(TASK_24,29) && !who->get_legend(TASK_24,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ���ʷ���˱�������������\n"ESC"�������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
	case 11:
		if ( who->get_legend(TASK_24,29) && !who->get_legend(TASK_24,30) )
		{
//			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 2 )
//        			return ;
			if(USER_INVENTORY_D->count_empty_carry(who) < 2 )
			{
			        send_user(who,"%c%s",';',"������û���㹻��λ��");
        			return;
			}
			TASK_LEGEND_D->give_item(who,"item/91/9164",1);
			TASK_LEGEND_D->give_item(who,"item/91/9164",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_24,30);
			who->add_exp(71000);
			who->add_potential(850);
			who->add_cash(55000);
			send_user(who,"%c%s",';',"�������� ���� 71000 Ǳ�� 850 ��Ǯ 55000 ���ĵ� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,44,"" );
        	}
        	break;			
        case 12:
	        if ( who->get_legend(TASK_36,1) && !who->get_legend(TASK_36,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����Ҫ�����Ⱦ�ʯ�����¿��е㼬�֣����ȱ�������ط����ǴӲ���й�ģ��������Ҫ�����ʦΪ����������������Ǩ���븶���ñ�������Ĵ��ۡ�\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
	        else if ( who->get_legend(TASK_36,2) && !who->get_legend(TASK_36,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ã���Ȼ����Ǩͬ����˵�����������Ҳ�Ե�������Ը�������Ⱦ�ʯ�䷽�ܸ��ӣ����ǻ���ԭ�ϱ��������־�ʯ����ȥ����������3��������쾧ʯ��4�������׾�ʯ��3�������ƾ�ʯ�����Ұɡ�\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
	        else if ( who->get_legend(TASK_36,3) && !who->get_legend(TASK_36,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Щ�������϶��Ҳ�������ô�����Ⱦ�ʯҲ��ָ���ˣ���ɲ��뿴������Ǩ�������ֶ���ı���ɡ�\n"ESC"�뿪", me->get_name()));
	        else if ( who->get_legend(TASK_36,4) && !who->get_legend(TASK_36,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Щ������ʯ������������Щ���⸨��ҩ����Ҫ��ȥѰ�ҡ�\n"ESC"�������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
	        else if ( who->get_legend(TASK_36,5) && !who->get_legend(TASK_36,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ռ�����Щ��ʯֻռ�˽�ˮ������λ��Ҫ����ľ�Բ�Ѫ�����������Ⱦ�ʯ��ò������ԣ���ȥ����������5�ݹ�ʯ�ҡ��߿Ŵ�ʯ�������ۻƣ�Ȼ��ǰ���ع�����ʦ��ʦ����ҩʦ����Ȼ������Ը��\n"ESC"��������\ntalk %x# welcome.16\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 13:
        	if ( who->get_legend(TASK_36,1) && !who->get_legend(TASK_36,2) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_36,2);
			who->add_exp(32000);
			who->add_potential(608);
			who->add_cash(30000);
			send_user(who,"%c%s",';',"������ʯ��1�� ���� 32000 Ǳ�� 608 ��Ǯ 30000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,57,"" );
			me->do_welcome(12);
        	}
        	break; 
	case 14:
        	if ( who->get_legend(TASK_36,2) && !who->get_legend(TASK_36,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_36,3);
        		who->delete_save("qwwmzhuhjs");
        		who->delete_save("qwwmbaijs");
        		who->delete_save("qwwmhuangjs");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,51,"������ʯ��2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ʯ��2��");
        	}
        	break;
	case 15:
        	if ( who->get_legend(TASK_36,4) && !who->get_legend(TASK_36,5) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������쾧ʯ",3) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"�����׾�ʯ",4) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0162",3); 
        			return ;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"�����ƾ�ʯ",3) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0162",3); 
				TASK_LEGEND_D->give_item(who,"item/98/0163",4); 
        			return ;
        		}
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_36,5);
        		who->delete_save("qwwmzhuhjs");
        		who->delete_save("qwwmbaijs");
        		who->delete_save("qwwmhuangjs");
			who->add_exp(39000);
			who->add_potential(650);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"������ʯ��2�� ���� 39000 Ǳ�� 650 ��Ǯ 37000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,51,"" );
			me->do_welcome(12);
        	}
        	break;
	case 16:
        	if ( who->get_legend(TASK_36,5) && !who->get_legend(TASK_36,6) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_36,6);
        		who->delete_save("qwgushihui");
        		who->delete_save("qwcishi");
        		who->delete_save("qwxionghuang");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,52,"������ʯ��3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ʯ��3��");
        	}
        	break;
        case 17:
	        if ( who->get_level() >= 100 && !who->get_legend(TASK_36,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ع����������ҹ������Բ��������Ȳ�˵���о�·���೤����·������ţ�����������ݾ͹���Ǻ������˵��ʿ���·Զˮ����������ӭս���Ҿ��������Ե���֮�����������������������������ͬ�����ı�������֮ʦ����ǿ�ʶ����ƣ��֮ʦ����ʱ�����˺Ͷ����ҷ�������Ӯ�����������������������Ǹ�����սʤǿ���ٴ���ҵ��������������գ�������Ϊ�����һ���ӣ����ԸΪ������ҵ��һ�����������Ŷ��궼�����ַ����û����������Ҳ����Ϊ�ḻ����ȥ�������ռ�10������10�ѵ��͵������󽫾����\n"ESC"��������\ntalk %x# welcome.18\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
	case 18:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_36,26) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_36,26);
        		who->delete_save("qwlijian");
        		who->delete_save("qwkuaidao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,58,"���������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���������");
        	}
        	break;
	case 19:
		if ( me->get_city_name() != who->get_city_name() )
			return;
		if ( who->get_legend(TASK_40,13) && !who->get_legend(TASK_40,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ǵģ���͢��Ĺ������԰����㽫��ͨ�ĺŽǼӹ�Ϊ��֮�Žǣ��㽫�Žǽ����ң���������ѯ�¹�����������Ҫ����Щ׼����\n"ESC"�������\ntalk %x# welcome.20\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,14) && !who->get_legend(TASK_40,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����˵����ͨ�ĺŽǵ�����Ϊ��֮�Ž���Ҫ���Ѻܶ����Ĳ��ϣ�����ҪһЩǮ��������Щ���ϣ���������һ���˵������ǲ������ó���ô��Ǯ�ģ�������Ӧ��Ҫ�������е�һ���֣���˵������֮�ŽǶ�����˵Ҳ��һ����ս��������������һ�ĵļӹ��ѣ�ֻ��Ҫ�����100��Ĳ��ϷѾ͹��ˡ�����㻹�������֮�ŽǵĻ����ͽ�Ǯ�����Ұɣ��һ�ת���������ġ�\n    �㽻Ǯ24Сʱ��Ϳ�����������ȡ��֮�Ž��ˣ�����24Сʱ�Ѿ��㹻�ù���������������ˡ�\n"ESC"��������\ntalk %x# welcome.21\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,15) && !who->get_legend(TASK_40,16) && gone_time(who->get_save("wangzhhj"))>=86400 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ͨ���ﵩ�ع���������������֮ǰ����֮�Žǵ������ˣ�����ȥ�����ɡ�\n"ESC"�������\ntalk %x# welcome.22\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 20:
		if ( me->get_city_name() == who->get_city_name() && who->get_legend(TASK_40,13) && !who->get_legend(TASK_40,14) )
		{
        		if (TASK_LEGEND_D->check_task_item(who,"�Ž�",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,14);
			who->add_exp(3000);
			who->add_potential(100);
			who->add_cash(2500);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,13,"" );
			send_user(who,"%c%s",';',"Ѱ������İ��� ���� 3000 Ǳ�� 100 ��Ǯ 2500");
			me->do_welcome(19);
        	}		
		break;
	case 21:
		if ( me->get_city_name() == who->get_city_name() && who->get_legend(TASK_40,14) && !who->get_legend(TASK_40,15) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if ( who->get_cash() < 1000000 )
			{
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ϵ�Ǯ�������ù������������֮�ŽǵĲ��ϣ����������Ǯ�������Ұɡ�\n"ESC"�뿪", me->get_name(),getoid(me)));
				return ;	
			}
			who->add_cash(-1000000);
			who->set_save("wangzhhj",time());
        		who->set_legend(TASK_40,15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,14,"��֮�Žǵĵ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��֮�Žǵĵ���");
        	}		
		break;
	case 22:
		if ( me->get_city_name() == who->get_city_name() && who->get_legend(TASK_40,15) && !who->get_legend(TASK_40,16) && gone_time(who->get_save("wangzhhj"))>=86400 )
		{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;        		
			TASK_LEGEND_D->give_item(who,"item/std/0095",1); 			
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,16);
			who->delete_save("wangzhhj");
			who->add_exp(3000);
			who->add_potential(100);
			who->add_cash(2500);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,14,"" );
			send_user(who,"%c%s",';',"��֮�Žǵĵ��� ���� 3000 Ǳ�� 100 ��Ǯ 2500");
		}
		break;
	case 23:
        	if (who->get_level() >= 110 && !who->get_legend(TASK_45,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֪��ʲô������������ϵ���ҫ������������������ϵ���ҫ�𣿵���������ɣ��Ҹ����㣬�����Ҳ����̫������֪���˲��ǣ�����ȥ�����������10ֻ���꣬�����ҽ�����𰸡�\n"ESC"��������\ntalk %x# welcome.24\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_45,7) && !who->get_legend(TASK_45,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������ʲô���������ϵ���ҫ�Ҳ��ܸ����㰡����Ϊ�ұ������ƥ����������ҫ����ݵ��˲��С�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_45,8) && !who->get_legend(TASK_45,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ţ������㻹���е������ģ������ɣ������ĸ�����ʲô������������ϵ���ҫ���Ǿ��ǡ���Ϊ�������¡�\n"ESC"�������\ntalk %x# welcome.25\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_45,9) && !who->get_legend(TASK_45,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������һ�ֲֹ�����Ҫ�ŵ������ζ������������Ҫô�ͳ�˯���ѣ�Ϊ�˰������ڹ�֮͢��������߶�������Ҫ�����ڹ�֮͢�ж����ֲ���񣬿�������˹��Ĺ��ˣ��������20��������ڰ�����˵�������°ɡ���˵��������������ϲ���ռ��������ȥ������ȡӦ�ú����װ쵽��\n"ESC"��������\ntalk %x# welcome.26\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_45,10) && !who->get_legend(TASK_45,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ʲô���ѵ��㾹Ȼ���ܴӵ���������������ô�����˶�����Ϊʧ�������˵Ĺ�͢�ɲ��Ǻ�����ҫ�������ĵط���\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_45,11) && !who->get_legend(TASK_45,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������Ѿ��������鵽�˹��˸����������ҫ�˰����������˻���������ҫ�������㡣\n"ESC"�������\ntalk %x# welcome.27\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_45,12) && !who->get_legend(TASK_45,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������ǰ��ʱ�����������100βԽ���㣬�����ڱ�ҹ���У�ĸ��ǳ�ϲ����������������Ҳ������ҲҪ����һЩ���������������һ������裬������ɽ���ڣ������е�֮ʿ�뱾���۵�֮ʱ���͵ģ���˵ÿ�겻����10�������������Ե�������������������˰ɡ�\n"ESC"��������\ntalk %x# welcome.28\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
	case 24:
		if (who->get_level() >= 110 && !who->get_legend(TASK_45,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_45,7);
        		who->delete_save("qwjianhun");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,69,"���ϵ���ҫ��1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ϵ���ҫ��1��");
        	}
        	break;
        case 25:
		if ( who->get_legend(TASK_45,8) && !who->get_legend(TASK_45,9) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_45,9);
        		who->delete_save("qwjianhun");
			who->add_exp(51000);
			who->add_potential(780);
			who->add_cash(51000);
			send_user(who,"%c%s",';',"���ϵ���ҫ��1�� ���� 51000 Ǳ�� 780 ��Ǯ 51000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,69,"" );
			me->do_welcome(23);
        	}
        	break;
	case 26:
		if (who->get_legend(TASK_45,9) && !who->get_legend(TASK_45,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_45,10);
        		who->delete_save("qwwenzhu");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,70,"���ϵ���ҫ��2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ϵ���ҫ��2��");
        	}
        	break;
        case 27:
		if ( who->get_legend(TASK_45,11) && !who->get_legend(TASK_45,12) )
        	{
			if (TASK_LEGEND_D->check_task_item(who,"����",20) != 1 )
        			return;        		
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_45,12);
        		who->delete_save("qwwenzhu");
			who->add_exp(55000);
			who->add_potential(830);
			who->add_cash(53000);
			send_user(who,"%c%s",';',"���ϵ���ҫ��2�� ���� 55000 Ǳ�� 830 ��Ǯ 53000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,70,"" );
			me->do_welcome(23);
        	}
        	break;
	case 28:
		if (who->get_legend(TASK_45,12) && !who->get_legend(TASK_45,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;
			TASK_LEGEND_D->give_item(who,"item/98/0224",7); 
        		who->set_legend(TASK_45,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,71,"���ϵ���ҫ��3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ϵ���ҫ��3��");
        	}
        	break;		
	case 99:
 		EMPEROR_D->do_look( who, me); 
 		break;
        }
}