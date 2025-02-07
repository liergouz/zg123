
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller_2() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 5402; }

void reset() ;

int is_self_look() { return 1; }

void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��������");
	set_real_name("�Ҹ�");
        set_city_name("�Թ�");

	set_2( "good", ([
	                "01" : "/sys/item/product"->get_random_diamond(),
	                "02" : "/sys/item/product"->get_random_diamond(),
	                "03" : "/sys/item/product"->get_random_diamond(),
	                "04" : "/sys/item/product"->get_random_diamond(),
	        ]) );
	set_2( "list", ([
	                "01" : 1+random(2),
	                "02" : 1+random(2),
			"03" : 1+random(2),
			"04" : 1+random(2),
	        ]) );	
	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
//	set("level",60);
//	set("legend",({32*18+7}) );
 	set("mpLegend",([60:({32*18+7}),]));
 	set("mpLegend2",([60:({32*18+9}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );

	if ( (who->get_level() >=60 && !who->get_legend(TASK_18,7)) || (who->get_legend(TASK_18,7) && !who->get_legend(TASK_18,9)) )
		result += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));

	result = result + sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

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
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_18,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ϸñ����������ٵ��������£������Ҿ��ȵ��ǹ���һ������ʯ�Ĵ�˵����֪����ʯͷ��ʲô��Ч����Ȼ���˻�����ô��Ĵ���ȥ���������뷢�ƣ��Ͽ�ȥ�೤�������ǿ�����ʯ�ɣ���˵ֻ����Ե�˲����ҵ�����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_18,7) && !who->get_legend(TASK_18,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ������۾���������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_18,8) && !who->get_legend(TASK_18,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������������������Ҳ����ȥ�����ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_18,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_18,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,32,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_18,8) && !who->get_legend(TASK_18,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����ʯ",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		TASK_LEGEND_D->give_item(who,"item/product/66028",1);
			who->set_legend(TASK_18,9);
			who->add_exp(7000);
			who->add_potential(260);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"�������� ���� 7000 Ǳ�� 260 ��Ǯ 6500 �߱�ը��ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,32,"" );
        	}
        	break;  
        }
}

// ��������λ����
void reset() 
{
	object me = this_object();
	int count;
	count = me->add("count", 1);
	if (count % 3==0)
	{
	        me->set_2( "good", ([
	                "01" : "/sys/item/product"->get_random_diamond(),
	                "02" : "/sys/item/product"->get_random_diamond(),
	                "03" : "/sys/item/product"->get_random_diamond(),
	                "04" : "/sys/item/product"->get_random_diamond(),
	        ]) );
	
	        me->set_2( "list", ([
	                "01" : 1+random(2),
	                "02" : 1+random(2),
			"03" : 1+random(2),
			"04" : 1+random(2),
	        ]) );		
	}	
}