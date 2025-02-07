
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5701; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�ŷ�");
        set_city_name("�Թ�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
//	set("level",56);
//	set("legend",({32*14+24,32*14+27,32*15+1,32*15+4}));	
	set("mpLegend",([50:({32*15+21}),55:({32*14+24,32*14+27,32*15+1,32*15+4,32*16+17,32*17+4,32*17+13,32*17+28}),105:({32*42+1})]));
	set("mpLegend2",([50:({32*15+23,}),55:({32*14+26,32*14+29,32*15+3,32*15+6,32*16+19,32*17+6,32*17+15,32*17+30,}),]));
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
	if ( (who->get_level() >=50 && !who->get_legend(TASK_15,21)) || (who->get_legend(TASK_15,21) && !who->get_legend(TASK_15,23)) )
		tmp += sprintf(ESC HIY "��Ѱͯ����Ȥ\ntalk %x# welcome.13\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_14,24)) || (who->get_legend(TASK_14,24) && !who->get_legend(TASK_14,26)) )
		tmp += sprintf(ESC HIY "�ŷ�ķ���\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_14,27)) || (who->get_legend(TASK_14,27) && !who->get_legend(TASK_14,29)) )
		tmp += sprintf(ESC HIY "���Ǿ���\ntalk %x# welcome.4\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_15,1)) || (who->get_legend(TASK_15,1) && !who->get_legend(TASK_15,3)) )
		tmp += sprintf(ESC HIY "���Ƕ��\ntalk %x# welcome.7\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_15,4)) || (who->get_legend(TASK_15,4) && !who->get_legend(TASK_15,6)) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.10\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_16,17)) || (who->get_legend(TASK_16,17) && !who->get_legend(TASK_16,19)) )
		tmp += sprintf(ESC HIY "��ħ����\ntalk %x# welcome.16\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,4)) || (who->get_legend(TASK_17,4) && !who->get_legend(TASK_17,6)) )
		tmp += sprintf(ESC HIY "ҹ���е�����\ntalk %x# welcome.19\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,13)) || (who->get_legend(TASK_17,13) && !who->get_legend(TASK_17,15)) )
		tmp += sprintf(ESC HIY "����֮��\ntalk %x# welcome.22\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,28)) || (who->get_legend(TASK_17,28) && !who->get_legend(TASK_17,30)) )
		tmp += sprintf(ESC HIY "�ŷ�����\ntalk %x# welcome.25\n",getoid(me));
	if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
		tmp += sprintf(ESC HIY "ѯ����Ϣ\ntalk %x# welcome.28\n",getoid(me));
			
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
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ǰ���������೤�ǵ��ѵ�����С�Ľ��Լ����õĿ���Ǯ��ʧ��������ܰ���Ѱ���ǿ���Ǯ��\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_14,24) && !who->get_legend(TASK_14,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������һ��������С�Ļ���Ǯ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_14,25) && !who->get_legend(TASK_14,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����̫��л���ˣ��治֪������α����㡣\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,11,"�ŷ�ķ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ŷ�ķ���");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_14,25) && !who->get_legend(TASK_14,26) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����Ǯ",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,26);
			who->add_exp(6200);
			who->add_potential(250);
			who->add_cash(6200);
			send_user(who,"%c%s",';',"�ŷ�ķ��� ���� 6200 Ǳ�� 250 ��Ǯ 6200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,11,"" );
        	}
        	break;   
        case 4:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¡���\n    ��֪������û�м�����˵����ʯͷ�����졭�������Ҽ���һ���˵����ʯͷ��̫�����ˣ�������ʲô��û�У���һ�Ŵ����죬һ��һ�ϣ����������ĺ����������Ҽ��������ϵ�ͷ���ܣ����˺�Զ������������������ĳ�Ц����ʵ����̫�����ˣ�\n    �Ҽǵ��ǿ�ʯͷ���೤�ǵķ��̨��������ʯ���������ǰȥ����һ�´��£�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_14,27) && !who->get_legend(TASK_14,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫�����ˣ��Ժ���Ҳ��ȥ�ǵط��ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_14,28) && !who->get_legend(TASK_14,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ȥ������Ҳ���õ��������ˡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_14,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,27);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,12,"���Ǿ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ǿ���");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_14,28) && !who->get_legend(TASK_14,29) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0038",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,29);
			who->add_exp(6100);
			who->add_potential(240);
			who->add_cash(6000);
			send_user(who,"%c%s",';',"���Ǿ��� ���� 6100 Ǳ�� 240 ��Ǯ 6000 ��˿ 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,12,"" );
        	}
        	break;      
        case 7:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵������զ����ô���أ�\n    �Ҳ��������������೤�ǣ��Ҳ�����һ�����Ĺ��ˣ���Ȼ�����˴���ң���ȥ�����������õĹ�Ǯ��������������������ֵǮ�Ķ���������̫���������ˣ�\n    %s�����ͬ������������ˣ����������ɣ�\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	else if ( who->get_legend(TASK_15,1) && !who->get_legend(TASK_15,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ժ���������Ҳ���ܴ��Ǿ����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,2) && !who->get_legend(TASK_15,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ժ���������Ǿ�����Ҳ���õ����ˡ�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 8:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,13,"���Ƕ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ƕ��");
        	}
        	break;
        case 9:
        	if ( who->get_legend(TASK_15,2) && !who->get_legend(TASK_15,3) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0258",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,3);
			who->add_exp(6300);
			who->add_potential(250);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"���Ƕ�� ���� 6300 Ǳ�� 250 ��Ǯ 6400 ���� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,13,"" );
        	}
        	break;   
        case 10:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������ƣ������˺ܶ��ֲ�ͬ���·����������ҵ�һ����������������Ƶķ�������ϧ������¹�����ԭ�ϣ���˵�������೤�ǵ��ѵ����������ܰ����ҵ�����\n"ESC"��������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_15,4) && !who->get_legend(TASK_15,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������ֻ������������Զ��һ���ź���\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,5) && !who->get_legend(TASK_15,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������е��������ʵ���ˣ��Ǻǡ���\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 11:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_15,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,14,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;
        case 12:
        	if ( who->get_legend(TASK_15,5) && !who->get_legend(TASK_15,6) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��¹��",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,6);
			who->add_exp(6300);
			who->add_potential(240);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"�������� ���� 6300 Ǳ�� 240 ��Ǯ 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,14,"" );
        	}
        	break; 
        case 13:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_15,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ÿ�캬����࣬����ͯ��ʱ���濪�İ����ǲ��ǵ����Ŀ��ġ������ѡ�С��顭����������˾��úܿ��ģ����ܸ�����һ������������˵���Գ���1�ķ��̨�������˼�����\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_15,21) && !who->get_legend(TASK_15,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ҳ����Ϊ���ˣ��Ͼ��������ֶ������ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,22) && !who->get_legend(TASK_15,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Եģ�����������Ҷ��þ�û�п��������ֶ����ˣ����ڵ�С���Ӻ��󶼲�������ˡ�\n"ESC"�������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 14:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_15,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,4,"��Ѱͯ����Ȥ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ѱͯ����Ȥ");
        	}
        	break;
        case 15:
        	if ( who->get_legend(TASK_15,22) && !who->get_legend(TASK_15,23) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,23);
			who->add_exp(6400);
			who->add_potential(258);
			who->add_cash(5400);
			send_user(who,"%c%s",';',"��Ѱͯ����Ȥ ���� 6400 Ǳ�� 258 ��Ǯ 5400");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,4,"" );
        	}
        	break; 
        case 16:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_16,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������һЩ����ֵֹ����飬������Ʒ���ã��������������ѱ��һ���������е����硣\n    �ϴ�·���೤�ǵķ��̨�����������죬�ض����Ǳ���ǧ�����֮ħ�ڴ������������ǵø���������֮ǰ������������Ȼ����������롣���Ƿ�Ը��ǰȥ��������\n"ESC"��������\ntalk %x# welcome.17\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_16,17) && !who->get_legend(TASK_16,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ط����ᰲ���������ҵøϿ����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,18) && !who->get_legend(TASK_16,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɺ��ˣ���Ҳ���õ����Ƕ�ħ�����ˡ�\n"ESC"�������\ntalk %x# welcome.18\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 17:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_16,17) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,17);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,16,"��ħ����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ħ����");
        	}
        	break;
        case 18:
        	if ( who->get_legend(TASK_16,18) && !who->get_legend(TASK_16,19) )
        	{
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_16,19);
			who->add_exp(6300);
			who->add_potential(230);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"��ħ���� ���� 6300 Ǳ�� 230 ��Ǯ 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,16,"" );
        	}
        	break; 
        case 19:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ϵ�һ�����죬������û���������һ�����Ķ��������⣬��ô����������Ȼ��û���������Ƿ����㣡\n    ������������������೤�ǵ��ѵ��Ͽմ���һ�����죬��ʱ�кܶ��˶������ˣ���Ҷ������ۣ��������ǳ�˯ǧ��Ļ���ħ�����ˣ��ҿ����������»��ǽ���������Щ�������������ɣ�������û����ȫ���ѣ��Ͻ�ȥ�೤�ǳ���������Ȼ���˾��������ˣ�\n"ESC"��������\ntalk %x# welcome.20\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,4) && !who->get_legend(TASK_17,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����̫�����ˣ��Ժ���Ҳ��ȥ�����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,5) && !who->get_legend(TASK_17,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿��а������ӹ��ˡ�\n"ESC"�������\ntalk %x# welcome.21\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 20:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,4) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,21,"ҹ���е�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ҹ���е�����");
        	}
        	break;
        case 21:
        	if ( who->get_legend(TASK_17,5) && !who->get_legend(TASK_17,6) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/63018",1);
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,6);
			who->add_exp(6400);
			who->add_potential(230);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"ҹ���е����� ���� 6400 Ǳ�� 230 ��Ǯ 6400 ���ĵ�ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,21,"" );
        	}
        	break; 
        case 22:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ҹ���顭�������顭��\n    ��˵��ҹ���飿�����š���˵�������飿��ţ����֪�����������������������������һ����֪������Ϊ��Ҳ��֪��������������\n    ������֪���������һ����ֵǮ�����ҵ�һ�����������ü�Ǯ��������ȥ�������Ұɣ����˺ü�Ǯ�ҷ���һ�룡������������೤�ǵ��ѵ���\n"ESC"��������\ntalk %x# welcome.23\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,13) && !who->get_legend(TASK_17,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҵ������ҵĶ���ȥ���Ǳ��顣\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,14) && !who->get_legend(TASK_17,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������ԭ���������д��ﰡ��\n"ESC"�������\ntalk %x# welcome.24\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 23:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,24,"����֮��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����֮��");
        	}
        	break;
        case 24:
        	if ( who->get_legend(TASK_17,14) && !who->get_legend(TASK_17,15) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,15);
			who->add_exp(6800);
			who->add_potential(240);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"����֮�� ���� 6800 Ǳ�� 240 ��Ǯ 6500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,24,"" );
        	}
        	break; 
        case 25:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���գ���һ�͹ٽ�һ�⸴���ź���ʧ���೤�ǵ��ѵ�������λ�͹������������ԣ�˭�ܰ���Ѱ�������ź�����һ�����س�л��\n"ESC"��������\ntalk %x# welcome.26\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,28) && !who->get_legend(TASK_17,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ�û�����ܰ�������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,29) && !who->get_legend(TASK_17,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������λ�͹ٿ��Է��ĵ����ˡ�\n"ESC"�������\ntalk %x# welcome.27\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 26:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,28);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,29,"�ŷ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ŷ�����");
        	}
        	break;
        case 27:
        	if ( who->get_legend(TASK_17,29) && !who->get_legend(TASK_17,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�����ź�",1) != 1 )
        			return;
 			TASK_LEGEND_D->task_finish(who);
 			who->set_legend(TASK_17,30);
			who->add_exp(6800);
			who->add_potential(250);
			who->add_cash(6700);
			send_user(who,"%c%s",';',"�ŷ����� ���� 6800 Ǳ�� 250 ��Ǯ 6700");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,29,"" );
        	}
        	break; 
	case 28:
		if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���⼸����������ȥ������������������������߶ʲô���ƺ��ܼ��е����ӣ�Ϊ������������֮���֣���λ���������°ﲻ��æ��ֻ����׳ʿǰȥ̽ѯһ����Ϊ������Ҳ�ܵ�Щ���ͣ����ֲ�Ϊ��\n"ESC"��������\ntalk %x# welcome.29\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;	        	
	case 29:
		if ( who->get_level() >=105 && !who->get_legend(TASK_42,1) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,73,"ѯ����Ϣ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ѯ����Ϣ");
        	}
		break;
        }
}