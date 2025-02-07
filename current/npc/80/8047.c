
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
void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 7102; }

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
//	set("level",47);
//	set("legend",({32*12+10}));
	set("mpLegend",([45:({32*12+10}),50:({32*15+15})]));
	set("mpLegend2",([45:({32*12+12}),50:({32*15+17})]));
        setup();
}

// �������Ի�����
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
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_12,10) ) || ( who->get_legend(TASK_12,10) && !who->get_legend(TASK_12,12) ) )
		tmp += sprintf(ESC HIY "�ӵ�����\ntalk %x# welcome.1\n",getoid(me));
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_15,15) ) || ( who->get_legend(TASK_15,15) && !who->get_legend(TASK_15,17) ) )
		tmp += sprintf(ESC HIY "��Ʒ��\ntalk %x# welcome.4\n",getoid(me));
			
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
        	if ( who->get_level() >=45 && !who->get_legend(TASK_12,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����֣������������һ��ֲ�����Ӱ��ԭ������ڡ��������ʱ�䣬����֣�������˶�������ʧ�٣�\n    ���ҵ��Ʋ⣬Ӧ���ǹ�֮�������������ǰȥ����֮��ɱ���ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_12,10) && !who->get_legend(TASK_12,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵø����ҵ��������ѣ������ǲ�Ҫ�������ߡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_12,11) && !who->get_legend(TASK_12,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    %s����Ӣ�°���\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=45 && !who->get_legend(TASK_12,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_12,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,4,"�ӵ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ӵ�����");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_12,11) && !who->get_legend(TASK_12,12) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64063",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_12,12);
			who->add_exp(4900);
			who->add_potential(160);
			who->add_cash(4100);
			send_user(who,"%c%s",';',"�ӵ����� ���� 4900 Ǳ�� 160 ��Ǯ 4100 ������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,4,"" );
        	}
        	break;   
	case 4:
        	if ( who->get_level() >=50 && !who->get_legend(TASK_15,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��̫������Ȼ���ˣ���������Ϊ�����ۻ���ͦ�õģ������ҿ�һ�Ҿ�Ӫ���еĵ꣬����ȥ�೤�Ǹ����ռ�10����������\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,15) && !who->get_legend(TASK_15,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�з��У���Ҫ��ô������������أ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,16) && !who->get_legend(TASK_15,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���˷��У����ܻ���ҪһЩ����֮��ģ��ҾͲ��鷳���ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if( who->get_level() >=50 && !who->get_legend(TASK_15,15) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,15);
        		who->delete_save_2("cqfajia");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,33,"��Ʒ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ʒ��");
        	}
        	break;       
        case 6:
        	if ( who->get_legend(TASK_15,16) && !who->get_legend(TASK_15,17) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",10) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/final/15/1513",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,17);
        		who->delete_save_2("cqfajia");
			who->add_exp(6500);
			who->add_potential(225);
			who->add_cash(5500);
			send_user(who,"%c%s",';',"��Ʒ�� ���� 6500 Ǳ�� 225 ��Ǯ 5500 �߼����� 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,33,"" );
        	}
        	break;   
        }
}