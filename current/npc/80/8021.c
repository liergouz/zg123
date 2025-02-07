
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
        set_city_name("�Թ�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
	set("mpLegend2",([0:({32*18+29,32*41+19,32*41+22,}),80:({32*38+14,}),]));
        setup();
}

// �������Ի�����
void do_look( object who ) 
{
	object me = this_object();
	string tmp="";
	
	if ("/sys/task/master"->do_look_quest10(who, me)>0) return;
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
	if ( who->get_legend(TASK_18,28) && !who->get_legend(TASK_18,29) )
	{
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.1\n",getoid(me));
	}		
	if ( who->get_level() >= 80 && who->get_legend(TASK_38,13) && !who->get_legend(TASK_38,14) )
	{
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.3\n",getoid(me));
	}
	if ( who->get_legend(TASK_41,18) && !who->get_legend(TASK_41,19) )
	{
		tmp += sprintf(ESC HIY "��̽����\ntalk %x# welcome.5\n",getoid(me));
	}
	if ( who->get_legend(TASK_41,19) && !who->get_legend(TASK_41,22) )
	{
		tmp += sprintf(ESC HIY "��̽ʵ��\ntalk %x# welcome.5\n",getoid(me));
	}
	if ( who->get_legend(TASK_41,22) && !who->get_legend(TASK_41,23) )
	{
		tmp += sprintf(ESC HIY "����̽��\ntalk %x# welcome.5\n",getoid(me));
	}
	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"�뿪"
			);

}


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
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_18,28) && !who->get_legend(TASK_18,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ٺ٣��Ҵ����ҵ��ϸ���С�ܶ�л�عܼҵ�ף���ˡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_legend(TASK_18,28) && !who->get_legend(TASK_18,29) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_18,29);
			who->add_exp(6800);
			who->add_potential(265);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"���� ���� 6800 Ǳ�� 265 ��Ǯ 6500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,9,"" );

       		}
        	break;
        case 3:
        	if ( who->get_level() >= 80 && who->get_legend(TASK_38,13) && !who->get_legend(TASK_38,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ҵ��ˡ���\n    ����������ô�õ����ܣ����Ǳ��������ˣ����������ҵ�˽���ӣ��һ���ȥ�����ģ�лл���ˡ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 4:
        	if ( who->get_level() >= 80 && who->get_legend(TASK_38,13) && !who->get_legend(TASK_38,14) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_38,14);
			who->add_exp(30000);
			who->add_potential(400);
			who->add_cash(22000);
			send_user(who,"%c%s",';',"����֮�� ���� 30000 Ǳ�� 400 ��Ǯ 22000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,50,"" );

       		}
        	break;
	case 5:
		if ( who->get_legend(TASK_41,18) && !who->get_legend(TASK_41,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �󽫾������ҵ������и�Ѱ�������ô���ã���һ��������ϸϸ�����㡣\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_41,19) && !who->get_legend(TASK_41,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����󷨴���������Ĳ���ػ�֮�У�����Ҫ��ȥ��ͼ�е�����ɷ�������㻹δ������ͻ����汩�����ҿ��ҹ�ϸ��Ǳ���������������̽��������ɷ֮������ؼ�����֮̾ǰ���ж��׳ʿ��ν����������ɷ�Ƴ�������������������ĵ׺�������֮�ˣ���������ɷ�����ٷ�λ��һɱ��30�����������30�������񽫣����Ƴ�������ɷ֮������֪�ң����ٽ����������\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_41,20) && !who->get_legend(TASK_41,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ô����û�а����ҵķԸ�ȥ�Ƴ�����ɷô������ɲ���ȥȡ���飬�ҿɲ�����ﲻ�������ְװ�����������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_41,21) && !who->get_legend(TASK_41,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    л��л�أ�����ɷ�����Ƴ��ˣ������ϸ�����ˣ��Ҹ�������ôȥȡ�����󷨣�Ҳ�ݲ��ð����\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_41,22) && !who->get_legend(TASK_41,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����󷨷�����һ�����˷���������У�����������١����������ߡ��ԡ����С��ڡ�ǰ��鷽�ɿ������ӣ������������СԪ�󷨵Ļ��ؾͻ�ͻ��СԪ��ɷ������̼仯Ϊ�ɻң��м��мǣ����������������������������ϸϸѰ�ң��μ��ҵ�������\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
        case 6:
		if ( who->get_legend(TASK_41,18) && !who->get_legend(TASK_41,19) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_41,19);
			who->add_exp(91000);
			who->add_potential(1600);
			who->add_cash(83000);
			send_user(who,"%c%s",';',"��̽���� ���� 91000 Ǳ�� 1600 ��Ǯ 83000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,69,"" );
			me->do_welcome(5);
        	} 
        	break;
	case 7:
       		if ( who->get_legend(TASK_41,19) && !who->get_legend(TASK_41,20) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_41,20);
        		who->delete_save("zzgshouztb");
        		who->delete_save("zzgshouzsj");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,70,"��̽ʵ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��̽ʵ��");
        	}
        	break;        	
        case 8:
		if ( who->get_legend(TASK_41,21) && !who->get_legend(TASK_41,22) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_41,22);
        		who->delete_save("zzgshouztb");
        		who->delete_save("zzgshouzsj");
			who->add_exp(92000);
			who->add_potential(1400);
			who->add_cash(82000);
			send_user(who,"%c%s",';',"��̽ʵ�� ���� 92000 Ǳ�� 1400 ��Ǯ 82000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,70,"" );
			me->do_welcome(5);
        	} 
        	break;
	case 9:
       		if ( who->get_legend(TASK_41,22) && !who->get_legend(TASK_41,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_41,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,71,"����̽��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����̽��");
        	}
        	break;  
        }
}