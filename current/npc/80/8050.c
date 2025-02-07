
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
int get_char_picid() { return 5301; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("���ܹ�");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
	set("mpLegend2",([0:({32*27+11,32*32+10,}),40:({32*38+2,}),]));
        setup();
}

// �������Ի�����
void do_look( object who ) 
{
	string tmp="";
	object me = this_object();
	if ("/sys/task/master"->do_look_quest10(who, this_object())>0) return;
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
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_27,10) && !who->get_legend(TASK_27,11) )
		tmp += sprintf(ESC HIY "ͬ����\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_27,11) && !who->get_legend(TASK_27,12)) || (who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,14)) )
		tmp += sprintf(ESC HIY "ͬ����\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_legend(TASK_32,9) && !who->get_legend(TASK_32,10) )
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.5\n",getoid(me));
	if ( who->get_level() >= 40 && who->get_legend(TASK_38,1) && !who->get_legend(TASK_38,2) )
		tmp += sprintf(ESC HIY "������\ntalk %x# welcome.7\n",getoid(me));

	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"�뿪"
			);

}


// ��������ʼ����
// void do_task_start() { TASK_ESCORT_D->do_task_start( this_player(), this_object() ); }
// ������ȡ������
// void do_task_cancel() { TASK_ESCORT_D->do_task_cancel( this_player(), this_object() ); }

int accept_money(object who, int gold)
{
	return "/sys/task/master"->accept_money(this_object(), who, gold);
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_legend(TASK_27,10) && !who->get_legend(TASK_27,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���µı����Ҷ�֪�����ܶ��˶����Ҵ���һЩ��������䣬�����ҿɲ�����ô���׻����������֪���ı���������Ŷ��\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_27,11) && !who->get_legend(TASK_27,12))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ÿ�������Ҵ����������Ϣ���ˣ��Ҷ���д����һ��д���ⱦ����š���������ű�����Ҫ������ȶ�һ����������ֱ��ҵ����ҵ�ë�ʡ���̨��ī����������д�ɵġ����������Ҫ���ҵ���ȶ��ҵ������������������ǵط���Σ�գ���������û�����Щ����һ����ȥ��\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if (who->get_legend(TASK_27,12) && !who->get_legend(TASK_27,13))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������������Ҳ������Ļ��Ҹ���û��Ȥ��������Ҫ�ҵĶ��������\n"ESC"�뿪", me->get_name()));
        	else if (who->get_legend(TASK_27,13) && !who->get_legend(TASK_27,14))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����㾭���������Ŀ����㹻֤������һ�������������ˡ���Ȼ�������������ˣ��Ҿ͸�������Ҫ�ҵĶ��������ڰɡ��ú�����ţ���ȥ�ú���ĥһ����������ˡ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
        case 2:
        	if ( who->get_legend(TASK_27,10) && !who->get_legend(TASK_27,11) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_27,11);
			who->add_exp(24000);
			who->add_potential(420);
			who->add_cash(22000);
			send_user(who,"%c%s",';',"ͬ������1�� ���� 24000 Ǳ�� 420 ��Ǯ 22000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,42,"" );
			me->do_welcome(1);
        	}
        	break;
	case 3:
        	if( who->get_legend(TASK_27,11) && !who->get_legend(TASK_27,12) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_27,12);
        		who->delete_save_2("yzgmaobi");
        		who->delete_save_2("yzgyantai");
        		who->delete_save_2("yzgmokuai");
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,37,"ͬ������2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ͬ������2��");
        	}
        	break;   
        case 4:
        	if ( who->get_legend(TASK_27,13) && !who->get_legend(TASK_27,14) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ë��",1) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"��̨",1) != 1 )
        		{
        			item = new("item/98/0127");
        			p = item->move(who,-1);
        			item->add_to_user(p);
        			return;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"ī��",1) != 1 )
			{
        			item = new("item/98/0127");
        			p = item->move(who,-1);
        			item->add_to_user(p);
        			item = new("item/98/0128");
        			p = item->move(who,-1);
        			item->add_to_user(p);
        			return;
        		}		        			
			item = new("item/98/0130");
			p = item->move(who,-1);
			item->add_to_user(p);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_27,14);
        		who->delete_save_2("yzgmaobi");
        		who->delete_save_2("yzgyantai");
        		who->delete_save_2("yzgmokuai");
			who->add_exp(26000);
			who->add_potential(450);
			who->add_cash(25000);
			send_user(who,"%c%s",';',"ͬ������2�� ���� 26000 Ǳ�� 450 ��Ǯ 25000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,38,"���������棨3��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,37,"" );
			me->do_welcome(1);
        	}
        	break;
        case 5:
        	if ( who->get_legend(TASK_32,9) && !who->get_legend(TASK_32,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������֪�����ߣ��Թܼ�Ҳ���Ϸ����Ƕ�л�ˣ�������������£��Ϸ�ض��岻�ݴǡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 6:
        	if ( who->get_legend(TASK_32,9) && !who->get_legend(TASK_32,10) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_32,10);
			who->add_exp(58000);
			who->add_potential(850);
			who->add_cash(50000);
			send_user(who,"%c%s",';',"���� ���� 58000 Ǳ�� 850 ��Ǯ 50000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,56,"" );
        	}
        	break;
        case 7:
        	if ( who->get_level() >= 40 && who->get_legend(TASK_38,1) && !who->get_legend(TASK_38,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �һ���Ϊ��ֻ�ǲ��������ң�û�뵽�����ԭ�򣬿�������������ҳ�����\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
        case 8:
        	if ( who->get_level() >= 40 && who->get_legend(TASK_38,1) && !who->get_legend(TASK_38,2) )
		{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_38,2);
			who->add_exp(4000);
			who->add_potential(130);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"������ ���� 4000 Ǳ�� 130 ��Ǯ 4000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,90,"" );
        	}       		
        	break;
        }
}