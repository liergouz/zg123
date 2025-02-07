
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("�Թ�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
//	set("level",58);
//	set("legend",({32*17+10}));	
 	set("mpLegend",([55:({32*17+10}),]));
 	set("mpLegend2",([0:({32*23+26}),55:({32*17+12}),]));
        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,10)) || (who->get_legend(TASK_17,10) && !who->get_legend(TASK_17,12)) )
		tmp += sprintf(ESC HIY "���̨�ϵ�����\ntalk %x# welcome.1\n",getoid(me));
        if (who->get_legend(TASK_23,25)&&!who->get_legend(TASK_23,26)) 
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.4\n",getoid(this_object())); 
        if (who->get_legend(TASK_23,26)&&!who->get_legend(TASK_23,27)) 
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.4\n",getoid(this_object())); 
			
	send_user(who,"%c%s",':',sprintf( "%s��\n    �ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���\n", get_name(),  ) 
			+ tmp +
			ESC"�뿪"
			);

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
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ͼ�������Щ���ĵ��ˣ�û�¶�Ϲ���ڣ�������Ļ̡̻�\n    ��˵���೤�ǵ��ѵ��Ͽ�ͻȻ����һ���������²������˸���ѵ����ǹ���������ȥ�������ҹ������Ǹ������ĵļһ�Ū�ģ�������ҪС�Ļ��򰡣�\n    ��������ǵ�Ҫ��ѵ��һ�٣�������������ԣ��ָ����������������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,10) && !who->get_legend(TASK_17,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������̫�ɶ��ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,11) && !who->get_legend(TASK_17,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ժ󻹸Ҳ���������\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,23,"���̨�ϵ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���̨�ϵ�����");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_17,11) && !who->get_legend(TASK_17,12) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/61010",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,12);
			who->add_exp(6500);
			who->add_potential(240);
			who->add_cash(6600);
			send_user(who,"%c%s",';',"���̨�ϵ����� ���� 6500 Ǳ�� 240 ��Ǯ 6600 ţ�⳴����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,23,"" );
        	}
		break;
        case 4:
	       	if ( who->get_legend(TASK_23,25) && !who->get_legend(TASK_23,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ʵ��ν�Ĳ�ʶ�ֵ����ܿ��Ķ����ţ�ֻ���һ��Ļ����ѡ���Ϊ�һ��Ļ�ȡ����ί���ߵ����ģ������ҿ��԰���������˵�Ļ���ͼ�����ֳ��������ԣ����Ƕ����һ�����˻��Ļ�������ʶ�ֵ���Ҳ�ܿ������š�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	else if ( who->get_legend(TASK_23,26) && !who->get_legend(TASK_23,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰһ�����Ҿ���κ�����ٺ����ʱ����Ҳ����������λѰ�������˵���ɷ�׽������ȥ�Ѿ�ʮ�궼û�������ˣ���ȴһֱû�иļޣ�һֱ�ڵȺ������ɷ����������������һ�Գ����������Ȼ���岻�ݴǡ����ǣ�����˵����Щ����һֱ�ܵ�һ������Ѷ�ĵ����ƻ飬����Ѱ������������Ҫ������Ͷ��·�ĵز����������ڰ�����Ž���Ѱ������֮ǰ��û��ǵ��޶����ϵ�Сũ���Ա߰���Ѷ��ѵһ�£�Ȼ���ٰ��Ž���Ѱ���������ϱȽϺ�һ�㡣\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;   
        case 5:
        	if ( who->get_legend(TASK_23,25) && !who->get_legend(TASK_23,26) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_23,26);
			who->add_exp(17000);
			who->add_potential(260);
			who->add_cash(17000);
			send_user(who,"%c%s",';',"��ʿ�İ��飨2�� ���� 17000 Ǳ�� 260 ��Ǯ 17000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,47,"" );
			me->do_welcome(4);
        	}
		break;
	case 6:
        	if ( who->get_legend(TASK_23,26) && !who->get_legend(TASK_23,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0109");
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!',"��Я������Ʒ̫����");
        			return ;	
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_23,27);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,40,"��ʿ�İ��飨3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ʿ�İ��飨3��");
        	}
        	break;  
        }
}