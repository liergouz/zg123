
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

// ���������촦��
void create()
{
        set_name("�������");
        set_city_name("���");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",46);
//        set("legend",({32*12+4}));
	set("mpLegend",([45:({32*12+4}),]));
	set("mpLegend2",([45:({32*12+6}),]));
        set_skill(0670, 80);
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_12,4) ) || ( who->get_legend(TASK_12,4) && !who->get_legend(TASK_12,6) ) )
	{
		tmp = sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
	}
	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
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
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
        	if ( who->get_level() >=45 && !who->get_legend(TASK_12,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ϊ�����������£��ǹ�ͷ��ɽ�����������ң������Ҳ�˿��ҵĹ�Ǯ����Ը������ֻع�����\n    �Ƕ�ͷ��ɽ����֣��������Ͽ�ȥ�ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_12,4) && !who->get_legend(TASK_12,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ��һ������������ɣ�����ֱ���������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_12,5) && !who->get_legend(TASK_12,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����г�ͷ֮���ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=45 && !who->get_legend(TASK_12,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_12,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,2,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_12,5) && !who->get_legend(TASK_12,6) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/61008",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_12,6);
			who->add_exp(4600);
			who->add_potential(170);
			who->add_cash(3900);
			send_user(who,"%c%s",';',"�������� ���� 4600 Ǳ�� 170 ��Ǯ 3900 ������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,2,"" );
        	}
        	break;   
        }
}