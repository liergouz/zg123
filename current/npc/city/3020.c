
// �Զ����ɣ�/make/npc/make8020

#include <npc.h>
#include <ansi.h>
#include <task.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0452; }
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
        set_name("�Թ�����");
        set_city_name("�Թ�");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",56);
//	set("legend",({32*14+21}));
	set("mpLegend",([55:({32*14+21,32*17+1}),80:({32*28+20})]));
	set("mpLegend2",([55:({32*14+23,32*17+3}),80:({32*28+22})]));
	set_skill(0680, 80);
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_14,21) ) || ( who->get_legend(TASK_14,21) && !who->get_legend(TASK_14,23) ) )
	{
		tmp = sprintf(ESC HIY "������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_17,1) ) || ( who->get_legend(TASK_17,1) && !who->get_legend(TASK_17,3) ) )
	{
		tmp += sprintf(ESC HIY "ҹ���е����\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( ( who->get_level() >= 80 && !who->get_legend(TASK_28,20) ) || ( who->get_legend(TASK_28,20) && !who->get_legend(TASK_28,22) ) )
	{
		tmp += sprintf(ESC HIY "���һս\ntalk %x# welcome.7\n",getoid(me));
	}
	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
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
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������ÿ�������ۻ��ֻ�ǹ������࣬�������������˿���\n    �Ƕ�ͷ����������ѹ���ǣ��ⶼ��˵�ˣ�˭Ҫ�����������ǿ������ޣ����ֵ��ǣ�����Ȼ���˿����ǵĹ�Ǯ����Щ��Ǯ�������������������������İ���\n    %s�����ҪΪ�����������������ľ����೤�ǵ��ѵ��ϡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	else if ( who->get_legend(TASK_14,21) && !who->get_legend(TASK_14,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������Ҫ�����ǳ��������ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_14,22) && !who->get_legend(TASK_14,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɺ��ˣ���Ҳ���ᱻ���۸��ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,10,"������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_14,22) && !who->get_legend(TASK_14,23) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0257",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,23);
			who->add_exp(6000);
			who->add_potential(240);
			who->add_cash(6000);
			send_user(who,"%c%s",';',"������ ���� 6000 Ǳ�� 240 ��Ǯ 6000 ���� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,10,"" );
        	}
        	break;   
 	case 4:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_17,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ǹ��Ϲ����ˣ�����Щʱ������һЩ���⻹���Ѹ㶨����˵��Щϸ��ɣ���ʱ����Ʒ̫С������������񻨴�ĥ�ģ�����ͷʹ����֪����һ�־��ӣ�����������Ʒ�ϣ����ԷŴ��������������������Щϸ������׶��ˣ��⾵�Ӿͽ���⾵��ϡ�ж������ѵ��ҵ�����\n    �������೤�ǵķ��̨�����Ҽ�����һ�������������ƾ�������⾵��������ģ���ȥ�������Ұɣ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_17,1) && !who->get_legend(TASK_17,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ҵ�����ȥѰ�����汦����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,2) && !who->get_legend(TASK_17,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ҷ����ˣ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if( who->get_level() >=55 && !who->get_legend(TASK_17,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,1);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,20,"ҹ���е����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ҹ���е����");
        	}
        	break;       
        case 6:
        	if ( who->get_legend(TASK_17,2) && !who->get_legend(TASK_17,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��⾵",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,3);
			who->add_exp(6600);
			who->add_potential(250);
			who->add_cash(6200);
			send_user(who,"%c%s",';',"ҹ���е���� ���� 6600 Ǳ�� 250 ��Ǯ 6200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,20,"" );
        	}
        	break;     
 	case 7:
        	if ( who->get_level() >=80 && !who->get_legend(TASK_28,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵĶ���Ϊ�˰��յİ�ȫȥ�����˿ӣ�����Щ����������ս������δ�������Ե���˻�����ֱ�����յ�����һ���ţ�˵�����ǿ�ʼһ������ս����׼��һ�ټ�����Щ�������ã�֮�����Ҳû����������Ϣ������һ��Ҫ���ұ������ȥ���˿���������ǡ�\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_28,20) && !who->get_legend(TASK_28,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ʵ��������Ϊ�������ҿ����ұ����������ұ������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_28,21) && !who->get_legend(TASK_28,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڱ���������Ҹ���θ�л�㣡\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 8:
        	if( who->get_level() >=80 && !who->get_legend(TASK_28,20) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,20);
   			who->delete_save("zggjdaodkl");
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,51,"���һս" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���һս");
        	}
        	break;       
        case 9:
        	if ( who->get_legend(TASK_28,21) && !who->get_legend(TASK_28,22) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/62076",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,22);
   			who->delete_save("zggjdaodkl");
			who->add_exp(51000);
			who->add_potential(705);
			who->add_cash(48800);
			send_user(who,"%c%s",';',"���һս ���� 51000 Ǳ�� 705 ��Ǯ 48800 ��������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,51,"" );
        	}
        	break;   
        }
}