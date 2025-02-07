
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
int get_char_picid() { return 5302; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�عܼ�");
        set_city_name("�ع�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
//        set("level",62);
//        set("legend",({32*18+28}));
 	set("mpLegend",([60:({32*18+28}),115:({32*46+1,32*46+26}),]));
 	set("mpLegend2",([0:({32*20+20,32*37+30,}),115:({32*39+10,32*46+12,}),]));        
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
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
	if ( (who->get_level() >=60 && !who->get_legend(TASK_18,28)) || ( ( who->get_legend(TASK_18,28) && !who->get_legend(TASK_18,29) ) ) )
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.1\n",getoid(me));
	if ( who->get_legend(TASK_20,19) && !who->get_legend(TASK_20,20) )
	{
		tmp += sprintf(ESC HIY "̽����ʵ\ntalk %x# welcome.3\n",getoid(me));
	}
	if ( (who->get_legend(TASK_20,20) && !who->get_legend(TASK_20,21)) || (who->get_legend(TASK_20,21) && !who->get_legend(TASK_20,23)))
	{
		tmp += sprintf(ESC HIY "����ͼֽ\ntalk %x# welcome.3\n",getoid(me));
	}
	if ( who->get_level() >=40 && who->get_legend(TASK_37,29) && !who->get_legend(TASK_37,30) )
		tmp += sprintf(ESC HIY "�����ĵ�\ntalk %x# welcome.6\n",getoid(me));
	if ( who->get_level() >=115 && who->get_legend(TASK_39,9) && !who->get_legend(TASK_39,10) )
		tmp += sprintf(ESC HIY "��Ը\ntalk %x# welcome.8\n",getoid(me));
	if ( who->get_level() >=115 && !who->get_legend(TASK_46,1) )
		tmp += sprintf(ESC HIY "ȷ�ϴ�˵\ntalk %x# welcome.10\n",getoid(me));
        if ( who->get_legend(TASK_46,11)&&!who->get_legend(TASK_46,12) ) 
		tmp += sprintf(ESC HIY "Σ�ս��\ntalk %x# welcome.10\n",getoid(this_object())); 
	if ( who->get_level() >=115 && !who->get_legend(TASK_46,26) )
		tmp += sprintf(ESC HIY "�ݷ�֮·\ntalk %x# welcome.13\n",getoid(me));

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
        	if ( who->get_level() >=60 && !who->get_legend(TASK_18,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ٺ٣����ܹܵ��ϵ���Ȼǿ�˰�����Ȼ�������ӣ������ȥ�������˳·���ҽ���ݺ����͸����ܹܣ����ٹ��Ӿ�Ȼ�����ϵ�80���ٹ��ٽ����������ض�ǰ;������������Ҫ����������Ͼ������������ף�ط�̸һ���ġ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_18,28) && !who->get_legend(TASK_18,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ȥ�ɣ�����·��̰�棬������ҰѺ����͵���\n"ESC"�뿪", me->get_name()));
			
        	break;
        case 2:
        	if ( who->get_level() >=60 && !who->get_legend(TASK_18,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0082");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			send_user(who,"%c%s",'!', "��Я������Ʒ̫����");	
        			destruct(item);
        			return;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_18,28);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,9,"����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����");
       		}
        	break;
        case 3:
        	if ( who->get_legend(TASK_20,19) && !who->get_legend(TASK_20,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ǵ������ɼ��ڹ������عܼҺ�������������ӣ�������Ҳ����ʲô���£���Ȯ��֮��ס�ģ��ߣ������Щ��������׼���ɣ�����Ҫ���ǡ��úõġ��ޣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_20,20) && !who->get_legend(TASK_20,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڹ���ԭʼͼֽ��ʧ�����س����ѵ���������ǰȥ���ǹ���ͼֽ�ҵ��������ع�������\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_20,21) && !who->get_legend(TASK_20,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ�����ͼֽ����\n"ESC"�뿪", me->get_name()));

        	break;
        case 4:
        	if ( who->get_legend(TASK_20,19) && !who->get_legend(TASK_20,20) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_20,20);
			who->add_exp(11000);
			who->add_potential(320);
			who->add_cash(9000);
			send_user(who,"%c%s",';',"̽����ʵ ���� 11000 Ǳ�� 320 ��Ǯ 9000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,23,"" );
			me->do_welcome(3);
        	}
        	break; 
	case 5:
        	if ( who->get_legend(TASK_20,20) && !who->get_legend(TASK_20,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_20,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,24,"����ͼֽ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ͼֽ");
        	}
        	break;        
	case 6:
		if ( who->get_level() >=40 && who->get_legend(TASK_37,29) && !who->get_legend(TASK_37,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ܹ�ǫ���ˣ���ʵ��Ҳ�������ܹܹ����з�������ǰȥ�ֽ��أ�û�뵽�����������ˣ������ɣ��һ�����ܹ�Լ��ʱ��ϸ̸���������ĵã��鷳���ˣ���ôԶ������\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
			
		break;
	case 7:
		if ( who->get_level() >=40 && who->get_legend(TASK_37,29) && !who->get_legend(TASK_37,30) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_37,30);
			who->add_exp(3000);
			who->add_potential(70);
			who->add_cash(2500);
			send_user(who,"%c%s",';',"�����ĵ� ���� 3000 Ǳ�� 70 ��Ǯ 2500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,73,"" );
        	}
        	break;
	case 8:
		if ( who->get_level() >=115 && who->get_legend(TASK_39,9) && !who->get_legend(TASK_39,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�뵽��������˵ĳ���ң��Ұ�����������Ը�ɣ�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
			
		break;
	case 9:
		if ( who->get_level() >=115 && who->get_legend(TASK_39,9) && !who->get_legend(TASK_39,10) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_39,10);
			who->add_exp(52000);
			who->add_potential(620);
			who->add_cash(48000);
			send_user(who,"%c%s",';',"��Ը ���� 52000 Ǳ�� 620 ��Ǯ 48000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,67,"" );
        	}
        	break;
        case 10:
        	if ( who->get_level() >=115 && !who->get_legend(TASK_46,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������±��棬�������еĵ��꾹Ȼ�ܹ���ÿ��ʮ�������������ڳ���ƽ�������ɱ¾��ÿ�¶��в�����׳�걻��ɱ����ÿ����ʱ���鶼��Ϊ��֣��·����˯ȥ�����Ϲ��Ź����Ц�ݣ�����Ǹ�����������Σ��Ǩ�Ƶ���Խ��Խ�࣬�Ѿ���Ϊ̸ƽ��ɫ��ĵز����һ�����ʲôа��������õ��꼳ȡ������һЩʲôа��֮�£���������йش�������������Ϊ������ʿ�ϲ����δ˵�а��������Ϊ���к����հɣ�����������ǰȥ̽��һ������˵���Ϻ���ס�վã����Ź�ʶ�������������ʿ���\n"ESC"��������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,11)&&!who->get_legend(TASK_46,12) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ҵ��أ�����û��ʲô��������в���ǹ��˵Ĵ����ˣ������Ǹ�С���Ū����������ѣ�׳ʿ��˷�Ҳ�����ˣ�����һֱ�龫���ǵ�����������Ҳ������һ�����������\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 11:
        	if ( who->get_level() >=115 && !who->get_legend(TASK_46,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,64,"���괫˵1" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���괫˵1");
       		}
        	break;
        case 12:
        	if( who->get_legend(TASK_46,11)&&!who->get_legend(TASK_46,12) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64181",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_46,12);
			who->add_exp(92000);
			who->add_potential(1100);
			who->add_cash(93000);
			send_user(who,"%c%s",';',"���괫˵5 ���� 92000 Ǳ�� 1100 ��Ǯ 93000 ����Ьͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,68,"" );
        	}
        	break;
        case 13:
        	if ( who->get_level() >=115 && !who->get_legend(TASK_46,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ҩʦΪ���������ɵ�����˵����һЩ�鷳�������������˸���Ԯ������֪��׳ʿ���Ը��ǰ��?\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
//		else if ( who->get_legend(TASK_46,11)&&!who->get_legend(TASK_46,12) ) 
//			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Ǽ����¡�\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 14:
        	if ( who->get_level() >=115 && !who->get_legend(TASK_46,26) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_46,26);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,74,"��ҩ֮·1" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ҩ֮·1");
       		}
        	break;
        }
}