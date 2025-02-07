
// �Զ����ɣ�/make/npc/make8020

#include <npc.h>
#include <ansi.h>
#include <task.h>

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
        set_name("��������");
        set_real_name("ʯ��1~30");
        set_city_name("����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",33);
//	set("legend",({32*8+22}));
	set("mpLegend",([30:({32*8+22})]));
	set("mpLegend2",([0:({32*33+21,}),30:({32*8+24,}),]));
	set_skill(0650, 39);
        set_2( "good", ([
                "01" : "/item/product/65001",
                "02" : "/item/product/65002",
                "03" : "/item/product/65003",
                "04" : "/item/product/65004",
                "05" : "/item/product/65005",
                "06" : "/item/product/65006",
                "07" : "/item/product/65007",
                "08" : "/item/product/65008",
                "09" : "/item/product/65009",
                "10" : "/item/product/65010",
                "11" : "/item/product/65011",        
                "12" : "/item/product/65012",
                "13" : "/item/product/65013",
                "14" : "/item/product/65014",
                "15" : "/item/product/65015",      
                "16" : "/item/product/65016",
                "17" : "/item/product/65017",
                "18" : "/item/product/65018",
                "19" : "/item/product/65019",
                "20" : "/item/product/65020",
                "21" : "/item/product/65021",                                                
        ]) );	
        setup();
}

// �������Ի�����

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( ( who->get_level() >= 30 && !who->get_legend(TASK_08,22) ) || ( who->get_legend(TASK_08,22) && !who->get_legend(TASK_08,24) ) )
	{
		tmp = sprintf(ESC HIY "��������Ի�\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_legend(TASK_33,20) && !who->get_legend(TASK_33,21) )
		tmp += sprintf(ESC HIY "�黹����\ntalk %x# welcome.4\n",getoid(this_object()));

	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"����ʯ�̼��ܵȼ�1-30�����䷽\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) ,get_name()));
	
}
int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 1 ); }

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
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ɽ�Ĳ��������ȥ����\n    ���һ��ʱ���ҳ�ȥ�Ǳ���������˵�������¶��ͣ�����ϡ�٣�����һ��������Ҳ��δ�����£�ֱ���ǴΡ���\n    ������е�࣬ҹĻ��������������أ��Ҵ�æ�����Ҹϣ�ͻȻ���ҷ����ҵĽž�Ȼ�������Լ��Ŀ��ƣ������±���ȥ����ʱ���Ҿ����ˣ���Ŭ������ͣס�Ų������Ҹ���ͣ���ˣ�һֱ�ߵ����±�Ե�����ۿ��Լ���Ҫ�������£����ڰ����ż���ʱ����ͻȻͣ����������֪���⸽����һֻ�Ի꾫�飬������Ū�ˣ����һ�ʹ�ܶ����޹�����������ȥ������������ȥһ�˴��ɽ�Ĳ������ȥ���Ǻ��˵��Ի꾫����ɵ���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_08,22) && !who->get_legend(TASK_08,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���´���Ҳ��ȥ���������ˣ������Լ�������Ҫ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_08,23) && !who->get_legend(TASK_08,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ����´���ȥ���������Ͳ��õ����ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_08,22) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_08,22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,20,"��������Ի�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������Ի�");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_08,23) && !who->get_legend(TASK_08,24) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/final/16/1602",5);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_08,24);
			who->add_exp(2600);
			who->add_potential(90);
			who->add_cash(2000);
			send_user(who,"%c%s",';',"��������Ի� ���� 2600 Ǳ�� 90 ��Ǯ 2000 ����ը�� 5");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,20,"" );
        	}
        	break;   
	case 4:
		if ( who->get_legend(TASK_33,20) && !who->get_legend(TASK_33,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����˵��������һЩ���飬����Ϊ��û���㻹�����ˣ�û�뵽�����͹����ˣ����Ǹ������õ��˰���\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if ( who->get_legend(TASK_33,20) && !who->get_legend(TASK_33,21) )
        	{
			if ( TASK_LEGEND_D->check_task_item(who,"������ľ�",1) != 1)
				return;      		
			if ( TASK_LEGEND_D->check_task_item(who,"����������",1) != 1)
			{
				TASK_LEGEND_D->give_item(who,"item/98/0157",1); 
				return;
			}
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_33,21);
        		who->delete_save("cgbxmuz");
        		who->delete_save("cgbxpaoz");
			who->add_exp(64000);
			who->add_potential(910);
			who->add_cash(55000);
			send_user(who,"%c%s",';',"���־��� ���� 64000 Ǳ�� 910 ��Ǯ 55000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,39,"" );
        	}
        	break;     
        }
}