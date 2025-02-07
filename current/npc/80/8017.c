
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 0451; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("������");
        set_city_name("�Թ�");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
//        set("level",58);
//        set("legend",({32*17+16}));
	set("mpLegend",([55:({32*17+16,32*17+19,32*17+22}),105:({32*41+16})]));
	set("mpLegend2",([55:({32*17+18,32*17+21,32*17+24,}),0:({32*11+15,32*11+18,32*11+21,32*28+11,})]));
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
	if ( who->get_legend(TASK_11,14) && !who->get_legend(TASK_11,15) )
		tmp += sprintf(ESC HIY "����������\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_11,15) && !who->get_legend(TASK_11,16)) || (who->get_legend(TASK_11,16) && !who->get_legend(TASK_11,18)) )
		tmp += sprintf(ESC HIY "�ռ�ʯ̿\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_11,18) && !who->get_legend(TASK_11,19)) || (who->get_legend(TASK_11,19) && !who->get_legend(TASK_11,21)) )
		tmp += sprintf(ESC HIY "��ѵ����\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_11,21) && !who->get_legend(TASK_11,22)) || (who->get_legend(TASK_11,22) && !who->get_legend(TASK_11,23)) )
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,16)) || (who->get_legend(TASK_17,16) && !who->get_legend(TASK_17,18)) )
		tmp += sprintf(ESC HIY "�»�Թ̾\ntalk %x# welcome.8\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,19)) || (who->get_legend(TASK_17,19) && !who->get_legend(TASK_17,21)) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.11\n",getoid(me));
	if ( (who->get_level() >=55 && !who->get_legend(TASK_17,22)) || (who->get_legend(TASK_17,22) && !who->get_legend(TASK_17,24)) )
		tmp += sprintf(ESC HIY "���ص�ӫ��\ntalk %x# welcome.14\n",getoid(me));
	if ( who->get_legend(TASK_28,10) && !who->get_legend(TASK_28,11) )
		tmp += sprintf(ESC HIY "����ľ���Կ��\ntalk %x# welcome.17\n",getoid(me));
	if ( who->get_legend(TASK_28,11) && !who->get_legend(TASK_28,12) )
		tmp += sprintf(ESC HIY "����Կ��\ntalk %x# welcome.17\n",getoid(me));
	if ( who->get_level() >= 105 && !who->get_legend(TASK_41,16) )
		tmp += sprintf(ESC HIY "ѯ��ԭ��\ntalk %x# welcome.20\n",getoid(me));
			
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
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_11,14) && !who->get_legend(TASK_11,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������»��е㼬�֣������ɣ�����ȥ���Ұ���£���������취������û������һʧ֮�ߡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,15) && !who->get_legend(TASK_11,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������»��е㼬�֣���ȥ�����ռ�10��ʯ̿����������������취��ʵ�ڲ�֪��ȥ���ҵĻ�����ȥ���Ʒ�ɡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,16) && !who->get_legend(TASK_11,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ʱ�һ�û�뵽�취����ȥ�����ռ�ʯ̿�ɣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_11,17) && !who->get_legend(TASK_11,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Щʯ̿�����ܻ��е�������ɾ������ҵ��Ǹ�������ô���أ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,18) && !who->get_legend(TASK_11,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������Щʯ̿�����ܻ��е���������и����˾������������ﵷ�ң���ȥ���ҽ�ѵ��ѵ������������������ߣ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,19) && !who->get_legend(TASK_11,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ʱ��û������õİ취������ȥ��ѵ�Ƕ���������������Ұɣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_11,20) && !who->get_legend(TASK_11,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ȵ������������Űɣ��Ұѽ������ķ���д�������ϣ�ϣ���ܰ�������졣\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,21) && !who->get_legend(TASK_11,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������Ž��������ɣ�����Ҳ��֪���ܲ��������ã�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,22) && !who->get_legend(TASK_11,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ɱ���������죬�����ڼ����أ�\n"ESC"�뿪", me->get_name()));
        	break;
        case 2:
        	if( who->get_legend(TASK_11,14) && !who->get_legend(TASK_11,15) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,15);
			who->add_exp(4400);
			who->add_potential(140);
			who->add_cash(3800);
			send_user(who,"%c%s",';',"���ε�������1�� ���� 4400 Ǳ�� 140 ��Ǯ 3800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,17,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if( who->get_legend(TASK_11,15) && !who->get_legend(TASK_11,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,16);
        		who->delete_save_2("wtjshitan");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,1,"���ε�������2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ε�������2��");
        	}
        	break;
        case 4:
        	if( who->get_legend(TASK_11,17) && !who->get_legend(TASK_11,18) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ʯ̿",10) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64037",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,18);
        		who->delete_save_2("wtjshitan");
			who->add_exp(6000);
			who->add_potential(190);
			who->add_cash(4500);
			send_user(who,"%c%s",';',"���ε�������2�� ���� 6000 Ǳ�� 190 ��Ǯ 4500 ������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,1,"" );
			me->do_welcome(1);
        	}
        	break;
        case 5:
        	if( who->get_legend(TASK_11,18) && !who->get_legend(TASK_11,19) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,19);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,2,"���ε�������3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ε�������3��");
        	}
        	break;
        case 6:
        	if( who->get_legend(TASK_11,20) && !who->get_legend(TASK_11,21) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64034",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,21);
			who->add_exp(6000);
			who->add_potential(190);
			who->add_cash(4500);
			send_user(who,"%c%s",';',"���ε�������3�� ���� 6000 Ǳ�� 190 ��Ǯ 4500 ��ս��ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,2,"" );
			me->do_welcome(1);
        	}
        	break;
        case 7:
        	if( who->get_legend(TASK_11,21) && !who->get_legend(TASK_11,22) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			item = new("item/98/0047");
			if ( !item  )
				return ;
			p = item->move(who,-1);
			if ( !p )
			{
				destruct(item);
				send_user( who, "%c%s", '!', "�����ϵĶ���̫����");
				return;
			}
			item->add_to_user(p);
        		who->set_legend(TASK_11,22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,3,"���ε�������4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ε�������4��");
        	}
        	break;
        case 8:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ϸ�˯�£��Ϳ�����ǰվ��һ���ˣ���˵����һ���λ�Ұ�����Ҳ�Ҫ�£���ֻ�����Ҹ�����������\n    ��˵������Ϊ�����������ӣ������С���ͺ����������������Ŀ����һ��Ҫ��������ޣ�����������;��ֻ����������������ѩ�ޣ�\n    �Ҿ����������ʺ��������µģ���Ϊ�㲻��ʶ��С����������Թ�޳𣬾���ɱ������Ҳû�˻���Ϊ����ɵģ�ȥ�ɣ������೤�ǵ��ѵ��ϡ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,16) && !who->get_legend(TASK_17,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ֻ��ȥ���ٲ��ܽ��������⡣\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,17) && !who->get_legend(TASK_17,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ǹ��»���԰�Ϣ�ˣ�\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 9:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,25,"�»�Թ̾" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�»�Թ̾");
        	}
        	break;
        case 10:
        	if ( who->get_legend(TASK_17,17) && !who->get_legend(TASK_17,18) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,18);
			who->add_exp(6700);
			who->add_potential(250);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"�»�Թ̾ ���� 6700 Ǳ�� 250 ��Ǯ 6400");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,25,"" );
        	}
        	break;   
        case 11:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰ�쾭���೤�ǵķ��̨ʱ����Ȼ����һ���ˣ��ó�һ���Ž�����һ���������������������Ľ��٣��ŵ��������޴롣\n    �����Ҳ�֪����ԭ������ŽǾ��Ǵ�˵�е������Žǣ����õ������Žǲ����������ˣ�����ѧ������񹦡�������������Ҳ�ǳ���ѧ�����������Կ����������ҵ��������Žǣ��ҵ�ʱ�������������ŽǷ������೤�Ƿ��̨�ϵ�һ�������ڣ���ȥ���Ұɣ�\n"ESC"��������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,19) && !who->get_legend(TASK_17,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ������۾���������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,20) && !who->get_legend(TASK_17,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ���%sлл���ˣ�\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
	case 12:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,19) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,19);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,26,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;
        case 13:
        	if ( who->get_legend(TASK_17,20) && !who->get_legend(TASK_17,21) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�����Ž�",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,21);
			who->add_exp(6800);
			who->add_potential(270);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"�������� ���� 6800 Ǳ�� 270 ��Ǯ 6500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,26,"" );
        	}
        	break;   
        case 14:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������·���೤�ǵ��ѵ���ʱ��������һ�����ص�ӫ��������Ʈ�����ҹ�����ʧ���Ѿõı̹�ʯ�����ˣ���Ը�����Ѱ������\n"ESC"��������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_17,22) && !who->get_legend(TASK_17,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������̫��ϧ�ˣ�Ҫ���ܵõ��Ǳ�ʯ��á�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,23) && !who->get_legend(TASK_17,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ���%s�������̫лл���ˣ�\n"ESC"�������\ntalk %x# welcome.16\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
	case 15:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_17,22) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,27,"���ص�ӫ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ص�ӫ��");
        	}
        	break;
        case 16:
        	if ( who->get_legend(TASK_17,23) && !who->get_legend(TASK_17,24) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�̹�ʯ",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,24);
			who->add_exp(7000);
			who->add_potential(260);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"���ص�ӫ�� ���� 7000 Ǳ�� 260 ��Ǯ 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,27,"" );
        	}
        	break;   
        case 17:
        	if ( who->get_legend(TASK_28,10) && !who->get_legend(TASK_28,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ǹ����ֻ��һ�������Ĵ��ˣ��������ô��쾫ϸ֮��������룬Ӧ�û��б�İ취��\n"ESC"�������\ntalk %x# welcome.18\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_28,11) && !who->get_legend(TASK_28,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ֻ���ܹ������ֹ������ܴ�����˾�ϸ֮����ȥ���ǿ������������ܰ�����㡣\n"ESC"��������\ntalk %x# welcome.19\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 18:
        	if ( who->get_legend(TASK_28,10) && !who->get_legend(TASK_28,11) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,11);
			who->add_exp(23500);
			who->add_potential(430);
			who->add_cash(23000);
			send_user(who,"%c%s",';',"ľ������ܣ�2�� ���� 23500 Ǳ�� 430 ��Ǯ 23000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,48,"" );
        		me->do_welcome(17);
        	}
        	break; 
	case 19:
        	if ( who->get_legend(TASK_28,11) && !who->get_legend(TASK_28,12) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,12);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,49,"ľ������ܣ�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ľ������ܣ�3��");
        	}
        	break;
        case 20:
       		if ( who->get_level() >= 105 && !who->get_legend(TASK_41,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҹ�����һ�����ҵ����������������ȥ�ͻ���ʱ�����Թ��󽫾�����üͷ�������ƺ���ʲô������˵ķ����£�����Ϊ�󽫾���������Ϊ�����֣�����С����̽����ν���Ҳ��˵������ֻ�п���ʿ�Ƿ��ܹ��ﵽ�󽫾��ˡ�\n"ESC"��������\ntalk %x# welcome.21\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 21:
       		if ( who->get_level() >= 105 && !who->get_legend(TASK_41,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_41,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,68,"ѯ��ԭ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ѯ��ԭ��");
        	}
        	break;
        }
}