
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "����ͷ�������ҵģ����Ҹ����ʵı��ڶ������ס���",
        "���Ҿ����ھֻ���һ��������������˼Ҿ�Ȼû�ա���",
        "���Ҿ����ھֻ������ѷ��磬���������˼Ҿ�Ȼû�ա���",
        "�ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���",
});
void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("κ��");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
//	set("level",27);
//	set("legend",({32*7+1}));
 	set("mpLegend",([25:({32*7+1}),]));
 	set("mpLegend2",([0:({32*35+4,}),25:({32*7+3,32*7+9,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,this_object());
	if ( ( who->get_level() >= 25 && !who->get_legend(TASK_07,1) ) || ( who->get_legend(TASK_07,1) && !who->get_legend(TASK_07,3) ) )
		tmp += sprintf(ESC HIY "������\ntalk %x# welcome.1\n",getoid(this_object()));
	if (  who->get_legend(TASK_07,3) && !who->get_legend(TASK_07,9)  )
		tmp += sprintf(ESC HIY "ȥ����̲�\ntalk %x# welcome.1\n",getoid(this_object()));
	if (  who->get_legend(TASK_35,3) && !who->get_legend(TASK_35,4)  )
		tmp += sprintf(ESC HIY "̽������\ntalk %x# welcome.6\n",getoid(this_object()));
	if (  who->get_legend(TASK_35,4) && !who->get_legend(TASK_35,5)  )
		tmp += sprintf(ESC HIY "ѯ�����\ntalk %x# welcome.6\n",getoid(this_object()));

	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
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
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 25 && !who->get_legend(TASK_07,1)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �٣�������һ������Ϣ���ҽ�ȥ�ݷ�����Ķ����꣬������ҳ�˼ĺ���˺ܾõ����飡\n    ����Ķ�������һ���ǳ�������ˣ��������Ѿã��Ҷ����Ĳ�ѧ������Ľ���ѣ������������������е�֪���;�ס��������ڣ�һֱ��ȥ�ݷ������ɴ����⵽���·;ңԶ��������Ҿ�������������Ҳ�ա������ȥ�ݷ�������ͷԽ��Խǿ�ң�����û��һ���������������õó��֡�\n    ����˵��ˮ�����Ѳ�߱����Ⱦƣ�������һ��Ů���죬��������æ��ȥ�Ǳ߸�����10̳���ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_07,1) && !who->get_legend(TASK_07,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������ҵ�Ů���죬�����Ҳ���ȥ�ݷö����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_07,2) && !who->get_legend(TASK_07,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ѿ�����������Ů���죬ʵ������ָ�л�������������������͸������ˣ��붡�ְѾ��Ի���һ����ô�������鰡��\n    �����������ʣ���׼�����̲��ƺ���Щ������·;ңԶ������һ������������̲����⣬Ī��Ҫ�Ƶ����ؽ����֣��������ʹ���ã�\n    ��ƽ�������κ����������ȽϽ��ã������ھ�ס��κ���ڣ���ɷ�����ȥ��������̲����Ҵ�������ͻ�������\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_07,3) && !who->get_legend(TASK_07,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������Ů���죬�������������͸������ˣ��������룬�ҵ��̲��ƺ��������������Ǻã�ƽ�������κ�����ձȽϽ��ã������ھ�ס��κ���ڣ���ɷ�����ȥ��������̲����Ҵ�������ͻ�������\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_07,4) && !who->get_legend(TASK_07,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �̲�Ҫ��������ɵÿ�㰡���𵣸����ҵ��г̡�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_07,8) && !who->get_legend(TASK_07,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ʵ��Ҳ֪��κ������������������ô������������������������ǿ��������֪�������������ӣ������ҲŽ���ȥ�������ⲻ����ô����͸������̲������ˣ�\n    �������̫��л���ˣ���������ȥ�ݷö����ˡ������Ͼ�д�Ÿ��߶����������Ϣ���������϶�Ҳ�ǳ����ˣ�\n    ���Ҵ�����������һ��Լ���Ǯ��������ġ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));	
        	break;
        case 2:
        	if ( who->get_level() >= 25 && !who->get_legend(TASK_07,1)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_07,1);
        		who->delete_save_2("haopengyou");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,4,"�͸����ֵľ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�͸����ֵľ�");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_07,2) && !who->get_legend(TASK_07,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Ů����",10) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_07,3);
			who->delete_save_2("haopengyou");
			who->add_exp(1500);
			who->add_potential(30);
			who->add_cash(1200);
			send_user(who,"%c%s",';',"�͸����ֵľ� ���� 1500 Ǳ�� 30 ��Ǯ 1200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,4,"" );
			me->do_welcome(1);
        	}
        	break;
	case 4:
        	if ( who->get_legend(TASK_07,3) && !who->get_legend(TASK_07,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_07,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,5,"ȥ����̲�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ȥ����̲�");
        	}
        	break;
	case 5:
        	if ( who->get_legend(TASK_07,8) && !who->get_legend(TASK_07,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�̲�",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_07,9);
			who->add_exp(5000);
			who->add_potential(160);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"�����̲� ���� 5000 Ǳ�� 160 ��Ǯ 4000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,5,"" );
        	}
        	break;
        case 6:
		if (  who->get_legend(TASK_35,3) && !who->get_legend(TASK_35,4)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ȼ���������ܹܴ����ˣ������������Ǻá�\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));	
		else if (  who->get_legend(TASK_35,4) && !who->get_legend(TASK_35,5)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ϰ��վ��������ں��������ﾭ��Ī�����ʧ����Щ���ڻ���Ȼ��ͻȻ�����������˵�Ȧ�������������������ھӵķ��䣬��ô��������������Ƕ������ɹ��಻���ԣ���ڵ���ͯ������Щ����֪���ø���ϸһЩ������ȥ�������ɡ�\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));	

		break;
	case 7:
        	if (  who->get_legend(TASK_35,3) && !who->get_legend(TASK_35,4)  )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_35,4);
			who->add_exp(77000);
			who->add_potential(990);
			who->add_cash(69000);
			send_user(who,"%c%s",';',"̽������ ���� 77000 Ǳ�� 990 ��Ǯ 69000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,52,"" );
			me->do_welcome(6);
        	}
        	break;	        	
        case 8:
        	if (  who->get_legend(TASK_35,4) && !who->get_legend(TASK_35,5)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_35,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,53,"ѯ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ѯ�����");
        	}
        	break;
        }

}
