
// �Զ����ɣ�/make/npc/make8020

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0450; }
void do_welcome(string arg);

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("�ع�����");
        set_real_name("����61~80");
        set_city_name("�ع�");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",67);
//	set("legend",({32*21+3}));
	set("mpLegend",([65:({32*21+3}),105:({32*39+3,}),110:({32*43+23})]));
	set("mpLegend2",([65:({32*21+7,32*21+12,}),110:({32*43+25})]));
	set_skill(0620, 39);
        set_2( "good", ([
                "01" : "/item/product/62050",
                "02" : "/item/product/62051",
                "03" : "/item/product/62052",
                "04" : "/item/product/62053",
                "05" : "/item/product/62054",
                "06" : "/item/product/62055",
                "07" : "/item/product/62056",
                "08" : "/item/product/62057",
                "09" : "/item/product/62058",
                "10" : "/item/product/62059",
                "11" : "/item/product/62060",
                "12" : "/item/product/62061",
                "13" : "/item/product/62062",
                "14" : "/item/product/62063",
                "15" : "/item/product/62064",
                "16" : "/item/product/62065",
                "17" : "/item/product/62066",
                "18" : "/item/product/62067",
                "19" : "/item/product/62068",
                "20" : "/item/product/62069",
                "21" : "/item/product/62070",
                "22" : "/item/product/62071",
        ]) );	
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( who->get_level() >= 65 && !who->get_legend(TASK_21,3) )
	{
		tmp = sprintf(ESC HIY "������Ϣ\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_legend(TASK_21,4) && !who->get_legend(TASK_21,5)) || (who->get_legend(TASK_21,5) && !who->get_legend(TASK_21,7)) )
	{
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.1\n",getoid(me));
	}
	if (who->get_legend(TASK_21,7) && !who->get_legend(TASK_21,8))
	{
		tmp += sprintf(ESC HIY "��ּ��Ĺ\ntalk %x# welcome.1\n",getoid(me));
	}	
	if ( (who->get_legend(TASK_21,9) && !who->get_legend(TASK_21,10)) || (who->get_legend(TASK_21,10) && !who->get_legend(TASK_21,12)) )
	{
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_legend(TASK_21,12) && !who->get_legend(TASK_21,13) )
	{
		tmp += sprintf(ESC HIY "Ѱ��֧��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_level() >= 105 && !who->get_legend(TASK_39,3) )
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.9\n",getoid(me));
	if ( ( who->get_level() >=110 && !who->get_legend(TASK_43,23) ) || ( who->get_legend(TASK_43,23) && !who->get_legend(TASK_43,25) ) )
		tmp += sprintf(ESC HIY "����ǰ�ĺڰ�\ntalk %x# welcome.11\n",getoid(me));

	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"�����������ܵȼ�61-80�����䷽\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) ,get_name()));
	
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 8 ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
       	string *nTmp,tmp;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 65 && !who->get_legend(TASK_21,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������ڻ������ǳ�����Ȥ�����㾡������ɽ�����һ���������»�������ɵĵع�������ͬʱҲ�ϸ����Ͳ��������˲ƶ�ҡ��֮�������������Ҽ������̣�����֪�������г���Σ�������ع������ٸ��޴���һ����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_21,4) && !who->get_legend(TASK_21,5))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵��۪ɽ������ʯ֮�أ���Ҫ���ǿ�ɽ���칤�£�û�п�ɽ���Ǻ��鷳�ġ���˵��δ����ַ�����࿪ɽ�����������س��ǵķ��̨�������Լ�ȥ��ȡ�����Ƿ�Ը�����������ɽ���أ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_21,5) && !who->get_legend(TASK_21,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�п�ɽ����������ʯ֮�ؿ�ɽ���칤�·ǳ��鷳��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_21,6) && !who->get_legend(TASK_21,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���½��������۪ɽ���µĴ��鷳��\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_21,7) && !who->get_legend(TASK_21,8))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����칤���Ѿ�׼����ϣ���ɽ���⽨���ź�ת������Ӯ������ּ�޽��ع���\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_21,9) && !who->get_legend(TASK_21,10))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ʼ���죬С���տ�ʼ������ֻ����������ʯ�ϱ�����ž�¢�ϣ�һζ̧����ۣ��Ȿ�Ǵ���֮�£���Υ����������Ӧ����������ǰȥ�س��Ƿ��̨������ȥ��\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_21,10) && !who->get_legend(TASK_21,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Բ�����ʯ�����ȡ�ã��ѵ���Ҫ�����������̧�����\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_21,11) && !who->get_legend(TASK_21,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɺ��ˣ�Ϊ����֮·�ֳ���һ���ϰ���\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_21,12) && !who->get_legend(TASK_21,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ۪ɽ�ع�֮�����¾߱���ֻǷ���������ˣ��㽫��Ϣ�����ع������٣�ϣ�����ܹ���������������\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
	case 2:
        	if ( who->get_level() >= 65 && !who->get_legend(TASK_21,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_21,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,28,"������Ϣ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������Ϣ");
        	}
        	break;
	case 3:
        	if (who->get_legend(TASK_21,4) && !who->get_legend(TASK_21,5))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_21,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,29,"����֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����֮��");
        	}
        	break;
        case 4:
        	if ( who->get_legend(TASK_21,6) && !who->get_legend(TASK_21,7) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��ɽ��",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_21,7);
			who->add_exp(14000);
			who->add_potential(360);
			who->add_cash(13000);
			send_user(who,"%c%s",';',"����֮�� ���� 14000 Ǳ�� 360 ��Ǯ 13000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,29,"" );
			me->do_welcome(1);
        	}
        	break; 
	case 5:
        	if ( who->get_legend(TASK_21,7) && !who->get_legend(TASK_21,8) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0097");
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!',"��Я������Ʒ̫��");	
        			return ;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_21,8);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,30,"��ּ��Ĺ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ּ��Ĺ");
        	}
        	break; 
	case 6:
        	if (who->get_legend(TASK_21,9) && !who->get_legend(TASK_21,10))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_21,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,31,"�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������");
        	}
        	break;
        case 7:
        	if ( who->get_legend(TASK_21,11) && !who->get_legend(TASK_21,12) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/62050",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_21,12);
			who->add_exp(15500);
			who->add_potential(370);
			who->add_cash(15000);
			send_user(who,"%c%s",';',"������� ���� 15500 Ǳ�� 370 ��Ǯ 15000 ���½�ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,31,"" );
			me->do_welcome(1);
        	}
        	break; 
	case 8:
        	if (who->get_legend(TASK_21,12) && !who->get_legend(TASK_21,13))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_21,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,32,"Ѱ��֧��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ѱ��֧��");
        	}
        	break;
        case 9:
		if ( who->get_level() >= 105 && !who->get_legend(TASK_39,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ֮ǰ�Թ��󽫾���������һ�����飬��Ȼ���������ܣ����ܸ����㡣\n    ���ڣ�������������������ף���Ϊ�ǻ��ܣ������Ҳ����Լ��������Ϣ����������ֻ�������ҵ��Թ��󽫾���Ȼ�������������֮���Ѱ�þ����ˣ��������������ʹ���ġ�\n"ESC"��������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break; 
        case 10:
        	if ( who->get_level() >= 105 && !who->get_legend(TASK_39,3) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,94,"����֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����֮��");
        	}
        	break; 
	case 11:
        	if ( who->get_level() >=110 && !who->get_legend(TASK_43,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ҿ�æ�ڱ�ս����Ͼ���ˣ���ǰǱ������������׷ײ��������ƵƵ�����ҹ�����أ�ʹ�������������������������װ��Ҫô������ɣ�Ҫô���ƻ���֧�����飬�����������ڵ�Ѫ�����������ն�Ϊһ�����۸�ò����䷱�����������˽����������ƻ����������һ�ž��ӵ������ǰ��Ӿ͹������������Ŵ����书�������������壬��֪�ܷ�Ϊ�ҵȴ��һ�����ǵ��������棬ɱ�����궴������5ֻ�������ŵĹ�����6ֻ������������������8�����ڴ˴����ҹ�������л���ˡ��ȵ�����ƽ��֮�������������������Ӿ͵�ͷ�ˡ�\n"ESC"��������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_43,23) && !who->get_legend(TASK_43,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����Ϊ����Щ�������������˲���أ��ѵ�������Ҳη��������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_43,24) && !who->get_legend(TASK_43,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������������������ô�صĴ����һ���ӹ�������������̫ƽ�ö࣬����˴��������޵б������ǵ���Ѫ����СС��˼���ɾ��⡣\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 12:
        	if ( who->get_level() >=110 && !who->get_legend(TASK_43,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_43,23);
        		who->delete_save("qggjtuj");
        		who->delete_save("qggjguixr");
        		who->delete_save("qggjtiangmzs");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,60,"����ǰ�ĺڰ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ǰ�ĺڰ�");
        	}
        	break;
        case 13:
        	if ( who->get_legend(TASK_43,24) && !who->get_legend(TASK_43,25) )
        	{
			if ( !sizeof(who->get_fam_name()) )
			{
				send_user(who,"%c%s",'!',"�������ɿɽ���������Ŷ��");
				return;	
			}
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,110,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_43,25);
        		who->delete_save("qggjtuj");
        		who->delete_save("qggjguixr");
        		who->delete_save("qggjtiangmzs");
			who->add_exp(98000);
			who->add_potential(1120);
			who->add_cash(95000);
			send_user(who,"%c%s",';',sprintf("����ǰ�ĺڰ� ���� 98000 Ǳ�� 1120 ��Ǯ 95000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,60,"" );
        		
        	}
        	break;
        }
}