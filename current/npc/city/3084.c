
// �Զ����ɣ�/make/npc/make8084

#include <npc.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 7805; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�Թ�����");
	set_real_name("�⼧");
        set_city_name("�Թ�");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",54);
//        set("legend",({32*15+24}));
	set("mpLegend",([80:({32*27+10}),105:({32*39+23}),50:({32*15+24}),55:({32*16+14,32*16+20,32*16+23,32*16+26,32*17+7,32*17+25})]));
	set("mpLegend2",([0:({32*41+30,32*42+6,32*42+11,32*42+14,32*42+24,32*42+27,32*43+6,}),80:({32*27+15,32*27+18,}),100:({32*38+28,}),105:({32*40+4}),50:({32*15+26,}),55:({32*16+16,32*16+22,32*16+25,32*16+28,32*17+9,32*17+27,})]));
        setup();
}

// �������Ի�����
void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_15,24) ) || ( who->get_legend(TASK_15,24) && !who->get_legend(TASK_15,26) ) )
	{
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_16,14) ) || ( who->get_legend(TASK_16,14) && !who->get_legend(TASK_16,16) ) )
	{
		tmp += sprintf(ESC HIY "�����ϵĿ���\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_16,20) ) || ( who->get_legend(TASK_16,20) && !who->get_legend(TASK_16,22) ) )
	{
		tmp += sprintf(ESC HIY "���ռ���\ntalk %x# welcome.7\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_16,23) ) || ( who->get_legend(TASK_16,23) && !who->get_legend(TASK_16,25) ) )
	{
		tmp += sprintf(ESC HIY "���´�˵\ntalk %x# welcome.10\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_16,26) ) || ( who->get_legend(TASK_16,26) && !who->get_legend(TASK_16,28) ) )
	{
		tmp += sprintf(ESC HIY "ǧ������\ntalk %x# welcome.13\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_17,7) ) || ( who->get_legend(TASK_17,7) && !who->get_legend(TASK_17,9) ) )
	{
		tmp += sprintf(ESC HIY "ҹ������\ntalk %x# welcome.16\n",getoid(me));
	}
	if ( ( who->get_level() >= 55 && !who->get_legend(TASK_17,25) ) || ( who->get_legend(TASK_17,25) && !who->get_legend(TASK_17,27) ) )
	{
		tmp += sprintf(ESC HIY "��ҽ���\ntalk %x# welcome.19\n",getoid(me));
	}
	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,10) )
	{
		tmp += sprintf(ESC HIY "ͬ����\ntalk %x# welcome.22\n",getoid(me));
	}
	if ( who->get_legend(TASK_27,14) && !who->get_legend(TASK_27,15) )
	{
		tmp += sprintf(ESC HIY "ͬ����\ntalk %x# welcome.22\n",getoid(me));
	}
	if ( (who->get_legend(TASK_27,15) && !who->get_legend(TASK_27,16)) || (who->get_legend(TASK_27,16) && !who->get_legend(TASK_27,18)) )
	{
		tmp += sprintf(ESC HIY "ͬ����\ntalk %x# welcome.22\n",getoid(me));
	}
	if ( who->get_level() >=100 && who->get_legend(TASK_38,27) && !who->get_legend(TASK_38,28) )
		tmp += sprintf(ESC HIY "��Թ\ntalk %x# welcome.27\n",getoid(me));
	if ( who->get_level() >=105 && !who->get_legend(TASK_39,23) )
		tmp += sprintf(ESC HIY "Ѱ����֮��\ntalk %x# welcome.29\n",getoid(me));
        if ( who->get_legend(TASK_40,3) && !who->get_legend(TASK_40,4) ) 
		tmp += sprintf(ESC HIY "������Ϊ\ntalk %x# welcome.29\n",getoid(me)); 
	if ( who->get_legend(TASK_42,5) && !who->get_legend(TASK_42,6) )
		tmp += sprintf(ESC HIY "ѯ��ս��\ntalk %x# welcome.32\n",getoid(me));
	if ( who->get_legend(TASK_42,6) && !who->get_legend(TASK_41,30) )
		tmp += sprintf(ESC HIY "�´�������\ntalk %x# welcome.32\n",getoid(me));
	if ( who->get_legend(TASK_41,30) && !who->get_legend(TASK_42,7) )
		tmp += sprintf(ESC HIY "��Ѱս��\ntalk %x# welcome.32\n",getoid(me));
	if ( who->get_legend(TASK_42,10) && !who->get_legend(TASK_42,11) )
		tmp += sprintf(ESC HIY "ѯ��ԭ��\ntalk %x# welcome.37\n",getoid(me));
	if ( who->get_legend(TASK_42,11) && !who->get_legend(TASK_42,14) )
		tmp += sprintf(ESC HIY "С������\ntalk %x# welcome.37\n",getoid(me));
	if ( who->get_legend(TASK_42,14) && !who->get_legend(TASK_42,15) )
		tmp += sprintf(ESC HIY "�����̿�\ntalk %x# welcome.37\n",getoid(me));
	if ( who->get_legend(TASK_42,23) && !who->get_legend(TASK_42,24) )
		tmp += sprintf(ESC HIY "̽������\ntalk %x# welcome.42\n",getoid(me));
	if ( who->get_legend(TASK_42,24) && !who->get_legend(TASK_42,27) )
		tmp += sprintf(ESC HIY "Ϊ�����\ntalk %x# welcome.42\n",getoid(me));
	if ( who->get_legend(TASK_42,27) && !who->get_legend(TASK_43,1) )
		tmp += sprintf(ESC HIY "����ʵ��\ntalk %x# welcome.42\n",getoid(me));
	if ( who->get_legend(TASK_43,5) && !who->get_legend(TASK_43,6) )
		tmp += sprintf(ESC HIY "ѯ������\ntalk %x# welcome.47\n",getoid(me));
	if ( who->get_legend(TASK_43,6) && !who->get_legend(TASK_43,7) )
		tmp += sprintf(ESC HIY "���֪����\ntalk %x# welcome.47\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name()) +
		tmp +
		ESC"�뿪");
	else
		more_look_menu( who, sprintf( "%s��\n    %s\n", get_name(), "/quest/word"->get_country_word(me) ) );
	
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
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
 	case 1:
        	if ( who->get_level() >=50 && !who->get_legend(TASK_15,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����ֹ��߿��Ǳز����ٵģ����Ҽ����׹����Ѿ����˺ܶ����ˣ����ܸ����ҵ���ͷ����������������˵�Գ����ϵĵ��ܱ������ܱ����С�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,24) && !who->get_legend(TASK_15,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҽ����׹������ǲ������ˣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,25) && !who->get_legend(TASK_15,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл�㣬������Щ���õĹ��ߣ��ҵĸ����ٶȿ��Լӿ첻�١�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_15,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,24);
        		who->delete_save_2("bxcutou");
        		who->delete_save_2("bxliandao");
        		who->delete_save_2("bxboji");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,5,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_15,25) && !who->get_legend(TASK_15,26) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),50,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"��ͷ",1) != 1 )
        			return;
			if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
			{
				item = new("item/98/0068");
				p = item->move(who,-1);
				item->add_to_user(p);
        			return;
        		}
     			if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        		{
				item = new("item/98/0068");
				p = item->move(who,-1);
				item->add_to_user(p);
        			item = new("item/98/0069");
				p = item->move(who,-1);
				item->add_to_user(p);
        			return;
        		}
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,26);
        		who->delete_save_2("bxcutou");
        		who->delete_save_2("bxliandao");
        		who->delete_save_2("bxboji");
			who->add_exp(6500);
			who->add_potential(265);
			who->add_cash(5600);
			send_user(who,"%c%s",';',sprintf("�������� ���� 6500 Ǳ�� 265 ��Ǯ 5600 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,5,"" );
        	}
        	break;  
 	case 4:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_16,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    һ������ҵ����������������̣�ģ�����������\n    ǰ���������೤�ǵķ��̨���棬����һ��С���ﱻ��Ʀ�۸�����ǰȥ��ֹ��û�뵽��������ţ��һ�Ѿͽ����ƿ������ҽ��������������������Ŀ������绨�����С���ﱻ����̣��ԩ����ԩ������\n    ������������ĳ������ȥ�೤�ǵķ��̨�ɵ��Ǹ���ʯ���ĵ�Ʀ�ɣ���һﻹ��֪��Ҫ�������ˣ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_16,14) && !who->get_legend(TASK_16,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������Ұ���\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,15) && !who->get_legend(TASK_16,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��λ%s������Ϊ���������\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
	case 5:
        	if( who->get_level() >=55 && !who->get_legend(TASK_16,14) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,14);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,15,"�����ϵĿ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ϵĿ���");
        	}
        	break;       
        case 6:
        	if ( who->get_legend(TASK_16,15) && !who->get_legend(TASK_16,16) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/stuff/0259",2);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_16,16);
			who->add_exp(6400);
			who->add_potential(230);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"�����ϵĿ��� ���� 6400 Ǳ�� 230 ��Ǯ 6500 ��Ƭ 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,15,"" );
        	}
        	break;  
 	case 7:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_16,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ��常����ǰ�����ң�������ʲô������һ��Ҫ���೤�Ƿ��̨�ϵ��������������Ҳ��֪������֮����ʲô��Թ�����������������ԣ���Ҳϣ���ܴ�������Ը����\n    ������ȥ�೤����ս�����������Σ���û�ܳɹ�������㶪����������˵������ų�����Ҫ���������ܴ����ĵ������������������ң�����������ǰȥ�೤�ǵķ��̨����������������常����Ը��\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_16,20) && !who->get_legend(TASK_16,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ը����û�а취ʵ���ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,21) && !who->get_legend(TASK_16,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л%s����������\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;
	case 8:
        	if( who->get_level() >=55 && !who->get_legend(TASK_16,20) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,20);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,17,"���ռ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ռ���");
        	}
        	break;       
        case 9:
        	if ( who->get_legend(TASK_16,21) && !who->get_legend(TASK_16,22) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/63017",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_16,22);
			who->add_exp(6600);
			who->add_potential(240);
			who->add_cash(6400);
			send_user(who,"%c%s",';',"���ռ��� ���� 6600 Ǳ�� 240 ��Ǯ 6400 ������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,17,"" );
        	}
        	break;  
 	case 10:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_16,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    С��ʱ�����ѧŮ�죬��ʱ��ֻҪ���Լ��������ģ�ɶ����������úã�������ʹ��ˣ�Ҫ��Խ��Խ�ߣ����Ծ�����һ�����£���˵������������˿���ɵ����º��˿�����������ü��꣬���ڴ���\n    ��������˿�Ǻ����ҵĲ��ϣ���˵�����������೤�ǵ��ѵ��ϼ���������Ը������ҵ�����\n"ESC"��������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_16,23) && !who->get_legend(TASK_16,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ֻ�Ǹ���˵�ɣ�����ô�ܵ����أ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,24) && !who->get_legend(TASK_16,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿ɺ��ˣ��ҵ�Ը������Ҫʵ���ˡ�\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 11:
        	if( who->get_level() >=55 && !who->get_legend(TASK_16,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,23);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,18,"���´�˵" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���´�˵");
        	}
        	break;       
        case 12:
        	if ( who->get_legend(TASK_16,24) && !who->get_legend(TASK_16,25) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��˿",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_16,25);
			who->add_exp(6500);
			who->add_potential(230);
			who->add_cash(6300);
			send_user(who,"%c%s",';',"���´�˵ ���� 6500 Ǳ�� 230 ��Ǯ 6300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,18,"" );
        	}
        	break;  
 	case 13:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_16,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ι���Ǳߵ��Ǹ�˭��ǧ��������˵���ɣ�������������û��˵��ǧ���������ֱ���ɡ�\n    ��һ�ֹ���ѧ��֮������·��ǧ��������ǧ����ڻ��£����һ���û�����ĸ������������񹦣���˵ֻҪ��������¶�Ϳ�������ǧ���ˣ��ѵ��㲻��������ֻҪ�������೤�ǵ��ѵ������ҵ����Ҷ������һ�룬����һ�������¶����ȥ�����㲻������ǧ�������ܿ��԰ɣ��Ķ������ж����Ͻ�ȥ�ɣ�\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_16,26) && !who->get_legend(TASK_16,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �һ�������ʵʵ���ҵİ��հɣ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_16,27) && !who->get_legend(TASK_16,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ҵĳ�ͷ֮�����ˡ�\n"ESC"�������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 14:
        	if( who->get_level() >=55 && !who->get_legend(TASK_16,26) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_16,26);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,19,"ǧ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ǧ������");
        	}
        	break;       
        case 15:
        	if ( who->get_legend(TASK_16,27) && !who->get_legend(TASK_16,28) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����¶",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_16,28);
			who->add_exp(6500);
			who->add_potential(250);
			who->add_cash(6500);
			send_user(who,"%c%s",';',"ǧ������ ���� 6500 Ǳ�� 250 ��Ǯ 6500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,19,"" );
        	}
        	break;  
 	case 16:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_17,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵�ǻ��˰������ͻȻ�Լ����ˣ������ǲ���߯��֣�̫�����ˣ�\n    ��������ֻ��һ��ԭ�򣬾���һ���в��ɾ��Ķ����������˼����ȥ���������ڤ֮���ֳ��������ˣ���ȥ�೤�ǵ��ѵ��ϳ������ɣ�\n"ESC"��������\ntalk %x# welcome.17\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_17,7) && !who->get_legend(TASK_17,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ǿֲ����Ժ�ҪС�����¡�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,8) && !who->get_legend(TASK_17,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �治��Ϊ����Ӣ�۰���\n"ESC"�������\ntalk %x# welcome.18\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 17:
        	if( who->get_level() >=55 && !who->get_legend(TASK_17,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,7);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,22,"ҹ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ҹ������");
        	}
        	break;       
        case 18:
        	if ( who->get_legend(TASK_17,8) && !who->get_legend(TASK_17,9) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,9);
			who->add_exp(6600);
			who->add_potential(250);
			who->add_cash(6700);
			send_user(who,"%c%s",';',"ҹ������ ���� 6600 Ǳ�� 230 ��Ǯ 6700");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,22,"" );
        	}
        	break;  
 	case 19:
        	if ( who->get_level() >=55 && !who->get_legend(TASK_17,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ǹ���ɱ°�ӡ��޶����ļһ�����ϴ���˲��ٰ��յļң���ñ��˼��������������Ҽ�Ҳ����ϴ�٣�\n    �Һ�����Թ�޳�����Ȼ�����Դ��ң�����������������ᶨ�ˣ�����ȥ���ҽ�ѵ��һ�ٰɣ���������������\n"ESC"��������\ntalk %x# welcome.20\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_17,25) && !who->get_legend(TASK_17,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ҵð���ˣ���Ȼ�´��������Ƕ�˸���ô�죿\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_17,26) && !who->get_legend(TASK_17,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����̫лл���ˣ�������������е�һ�ڶ�����\n"ESC"�������\ntalk %x# welcome.21\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 20:
        	if( who->get_level() >=55 && !who->get_legend(TASK_17,25) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_17,25);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,28,"��ҽ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ҽ���");
        	}
        	break;       
        case 21:
        	if ( who->get_legend(TASK_17,26) && !who->get_legend(TASK_17,27) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_17,27);
			who->add_exp(6900);
			who->add_potential(260);
			who->add_cash(6800);
			send_user(who,"%c%s",';',"��ҽ��� ���� 6900 Ǳ�� 260 ��Ǯ 6800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,28,"" );
        	}
        	break;  
 	case 22:
        	if ( who->get_level() >=80 && !who->get_legend(TASK_27,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����˵�ܶ���ǰ�����ϳ��ֹ�һ�Ա����ͬ������ֻҪ���˷ֱ�������������ʱ�ҵ��Է�������Һ��ҵİ��˶��ֱ��������Ա����ô���ǾͲ��س���������˼֮���ˡ�����˵������ܹ����������ⱦ�ﶼ����������������ȥѯ��һ����������������\n"ESC"��������\ntalk %x# welcome.23\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_27,14) && !who->get_legend(TASK_27,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл����������ܹ��������ţ������Ļ��Ҿ���Ŀ����ҵ����ͬ�����ˡ������ȿ��������˵ʲô��������ͬ������ʱ���һ���Ҫ��İ�����\n"ESC"�������\ntalk %x# welcome.24\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_27,15) && !who->get_legend(TASK_27,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ܹܸ��ҵ����������ʾ�����ͬ����Ӧ�þ������˿������ĳһ���������ϡ��������˿ӵ������ҿɴ򲻹��������һ���Ҫ��İ�æ������ȥ���˿�ɱ����������ã����ҵ����������ϵ�ͬ�����������ˡ�\n"ESC"��������\ntalk %x# welcome.25\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_27,16) && !who->get_legend(TASK_27,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҳ���ͬ�������Һ��ҵİ�������������ң�ÿ�����Ƕ�Ҫ����˼֮��ļ尾��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_27,17) && !who->get_legend(TASK_27,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ĺܸ�л�㣬���������ͬ�������Һ��ҵİ��˾Ͳ���ÿ�춼Ҫ����˼֮��ļ尾�ˡ�\n"ESC"�������\ntalk %x# welcome.26\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 23:
        	if( who->get_level() >=80 && !who->get_legend(TASK_27,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_27,10);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,42,"ͬ������1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ͬ������1��");
        	}
        	break;  
        case 24:
        	if ( who->get_legend(TASK_27,14) && !who->get_legend(TASK_27,15) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���ܹܵ���",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_27,15);
			who->add_exp(24000);
			who->add_potential(420);
			who->add_cash(22000);
			send_user(who,"%c%s",';',"���������棨3�� ���� 24000 Ǳ�� 420 ��Ǯ 22000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,38,"" );
			me->do_welcome(22);
        	}
        	break; 
	case 25:
        	if( who->get_legend(TASK_27,15) && !who->get_legend(TASK_27,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_27,16);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,43,"ͬ������4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ͬ������4��");
        	}
        	break;  
        case 26:
        	if ( who->get_legend(TASK_27,17) && !who->get_legend(TASK_27,18) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),80,NECK_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ; 
        		if (TASK_LEGEND_D->check_task_item(who,"ͬ����",1) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_27,18);
			who->add_exp(100000);
			who->add_potential(1400);
			who->add_cash(100000);
			send_user(who,"%c%s",';',sprintf("���������棨4�� ���� 100000 Ǳ�� 1400 ��Ǯ 100000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,43,"" );
        	}
        	break; 
	case 27:
		if ( who->get_level() >=100 && who->get_legend(TASK_38,27) && !who->get_legend(TASK_38,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵܵܺ��������ڵ����û�й��Ķ��ǣ�û���������������룬���ǲ����ȥ�ˡ�\n"ESC"�������\ntalk %x# welcome.28\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;		
	case 28:
		if ( who->get_level() >=100 && who->get_legend(TASK_38,27) && !who->get_legend(TASK_38,28) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_38,28);
			who->add_exp(45000);
			who->add_potential(610);
			who->add_cash(40000);
			send_user(who,"%c%s",';',"��Թ ���� 45000 Ǳ�� 610 ��Ǯ 40000");
			send_user(who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,92,"" );
        	}
		break;
	case 29:
		if ( who->get_level() >=105 && !who->get_legend(TASK_39,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������������ڼ����ˣ������Χ�������Ѿ�Ȼһ����û���������ɾ���Ȣ�Ҷ������ӣ��������������Ų����ҽ����ݣ������������ҹ�Ҿ�Ȼ��������һ���˶ȹ����ò�������Ϊʲô�ҵ��ھ�����ȫ����Ը��ͬ�ҽ������أ��ѵ���ƽ������ʲô������������ô����ȥ����������ϳ�������������ʣ��ô����������𾴵ĳ��ߣ���ƽ��Ҳ�����߶���Ӧ�û������Ϊʲô�ɡ�\n"ESC"��������\ntalk %x# welcome.30\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,3) && !who->get_legend(TASK_40,4) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�뵽��������ٻ��������ң�Ҳлл�㣬����˵�öԣ���Щ�����Ǳ����Լ�ȥ�ֲ��ġ�\n"ESC"�������\ntalk %x# welcome.31\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 30:
        	if ( who->get_level() >=105 && !who->get_legend(TASK_39,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,23);
   			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,58,"������裨1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������裨1��");
        	}
        	break; 		
	case 31:
		if ( who->get_legend(TASK_40,3) && !who->get_legend(TASK_40,4) ) 
		{
			if (TASK_LEGEND_D->check_task_item(who,"�޺õ�СľͰ",1) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/product/64172",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_40,4);
			who->add_exp(200500);
			who->add_potential(2255);
			who->add_cash(200500);
			send_user(who,"%c%s",';',"������裨5�� ���� 200500 Ǳ�� 2255 ��Ǯ 200500 �����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,9,"" );
        	}
		break;
	case 32:
		if ( who->get_legend(TASK_42,5) && !who->get_legend(TASK_42,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �꣬��ͬ������\n"ESC"�������\ntalk %x# welcome.33\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,6) && !who->get_legend(TASK_41,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵ս�����ۼ���������ĵ�ɷ��͵ȥ�ˣ�����ȥɱ30����ɷ�����غ�30�����������Ȼ���Һ����ѻ���̽������Ϣ��\n"ESC"��������\ntalk %x# welcome.34\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_41,28) && !who->get_legend(TASK_41,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����Թ�����������л��ǲ������޷�ʩ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_41,29) && !who->get_legend(TASK_41,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ã����ȵȵȣ��ҽ���ʩ������ɲ�Ҫ͵���������ҵķ������ɿɾ�Ҫ�����˼��ˣ�\n"ESC"�������\ntalk %x# welcome.35\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_41,30) && !who->get_legend(TASK_42,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������̫���ˣ��۵��ҿ�����һ��Ƥ���Ժ�û��ʲô�ߴ��۵������һ�������Ϊ���֪���ˣ���ս�����˲�������������ϲ������һ���������ȥ����Ѱ�������Թ�������ƽԭ����\n"ESC"��������\ntalk %x# welcome.36\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 33:
		if ( who->get_legend(TASK_42,5) && !who->get_legend(TASK_42,6) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_42,6);
			who->add_exp(95000);
			who->add_potential(1650);
			who->add_cash(85000);
			send_user(who,"%c%s",';',"ѯ��ս�� ���� 95000 Ǳ�� 1650 ��Ǯ 85000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,75,"" );
			me->do_welcome(32);
        	} 
		break;
	case 34:
		if ( who->get_legend(TASK_42,6) && !who->get_legend(TASK_41,28) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_41,28);
        		who->delete_save("zgbxdsmzs");
        		who->delete_save("zgbxshouztb");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,76,"�´�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�´�������");
        	}
		break;
	case 35:
		if ( who->get_legend(TASK_41,29) && !who->get_legend(TASK_41,30) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_41,30);
        		who->delete_save("zgbxdsmzs");
        		who->delete_save("zgbxshouztb");
			who->add_exp(95000);
			who->add_potential(1650);
			who->add_cash(86000);
			send_user(who,"%c%s",';',"�´������� ���� 95000 Ǳ�� 1650 ��Ǯ 86000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,76,"" );
			me->do_welcome(32);
        	} 
		break;
	case 36:
		if ( who->get_legend(TASK_41,30) && !who->get_legend(TASK_42,7) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,77,"��Ѱս��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ѱս��");
        	}
		break;
	case 37:
		if ( who->get_legend(TASK_42,10) && !who->get_legend(TASK_42,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ٺ٣����ʱ��˲�һ��֪�������������ʶ��ˣ������ɵ�֪��һ�����Ϣ����֪����ʲô����û�У�\n"ESC"�������\ntalk %x# welcome.38\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,11) && !who->get_legend(TASK_42,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ѽѽ���������ֵö����Ǹ������ü�����ѻ����ˣ�������֪�������ɱ�ж���̫�����йأ���ȥ����������ɱ30��̫�������غ�30��������������������ң���ֻ����Ϊ�����ٶ���һ���ѻ����ˣ������ɵ�����ʷ���˱���һ���ҵĹ������ʹ�һ�㶼�����٣�Ҫ��Ȼ�ҿɾͿ����ˡ�\n"ESC"��������\ntalk %x# welcome.39\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,12) && !who->get_legend(TASK_42,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ��ϴ����������ֻ�ǽ���?�����ˣ��������ˣ����ֵ���Ϣ��Ϣ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_42,13) && !who->get_legend(TASK_42,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ӹ�ز��������ظ��˰ɣ���ȥ˳�ֹ��ţ�����͵�����������춯������һ�к�����㸺���ҸŲ�����\n"ESC"�������\ntalk %x# welcome.40\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,14) && !who->get_legend(TASK_42,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ������ȹ��ϵ�С�ӣ������ɣ�����˴�ͷ�ĺ���Ҫ���ֵĻ������ģ����񲢲���̫�����ˣ���֪��������������ģ�������Ҳ��ָ���������������˳����������һ��ɱ������һ�����ݣ�ǰ����ɵõ������������ɵ���Ļ�������������������㱱��һ����ϵ���£��߻��ж�����ȥ�������������ɣ����������������ȥ�����Թ�������һ����\n"ESC"��������\ntalk %x# welcome.41\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 38:
		if ( who->get_legend(TASK_42,10) && !who->get_legend(TASK_42,11) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_42,11);
			who->add_exp(96000);
			who->add_potential(1750);
			who->add_cash(87000);
			send_user(who,"%c%s",';',"ѯ��ԭ�� ���� 96000 Ǳ�� 1750 ��Ǯ 87000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,78,"" );
			me->do_welcome(37);
        	} 
		break;
	case 39:
		if ( who->get_legend(TASK_42,11) && !who->get_legend(TASK_42,12) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,12);
        		who->delete_save("zgbxtjmzs");
        		who->delete_save("zgbxshouztb1");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,79,"С������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"С������");
        	}
		break;
	case 40:
		if ( who->get_legend(TASK_42,13) && !who->get_legend(TASK_42,14) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_42,14);
        		who->delete_save("zgbxtjmzs");
        		who->delete_save("zgbxshouztb1");
			who->add_exp(97000);
			who->add_potential(1700);
			who->add_cash(88000);
			send_user(who,"%c%s",';',"С������ ���� 97000 Ǳ�� 1700 ��Ǯ 88000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,79,"" );
			me->do_welcome(37);
        	} 
		break;
	case 41:
		if ( who->get_legend(TASK_42,14) && !who->get_legend(TASK_42,15) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,80,"�����̿�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����̿�");
        	}
		break;
	case 42:
		if ( who->get_legend(TASK_42,23) && !who->get_legend(TASK_42,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������ǵ��������Ǿ����������������ػ��������?\n"ESC"�������\ntalk %x# welcome.43\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,24) && !who->get_legend(TASK_42,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֪�������˵�о�ͯҥ����ŵ������ѹ���ء����������ָ�ı��Ƕ�������������̱���ɽ���Լ�������ʵȨ��ð�ö�˰����ǿ������˽��������ǿ����Ů���ƻ����ᣬ��������Ŀ�б�˽�ң���Ҷ��̻̲������գ��������������˼�̤�����������򱳵����ս����࣬Թ������Ҫ�Ƕ���������������´���֮�ţ������ӡ��Ǹ�����������������������ϲ����ͣ�׳ʿ���������ˣ�������Ҳ������˵�ˡ�\n"ESC"��������\ntalk %x# welcome.44\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,25) && !who->get_legend(TASK_42,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ٹ��໤�����ǰ������г�ͷ֮�գ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_42,26) && !who->get_legend(TASK_42,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������Ǳ������ˡ�\n"ESC"�������\ntalk %x# welcome.45\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_42,27) && !who->get_legend(TASK_43,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ϴ�ͯҥ�ἰ����ţ���Ҳ����ֱ��ͬ��˵������һʱ�嶯���£��ҽ�����ʱ������鶼д�������߿����ϣ��㽻������������������������ɡ�\n"ESC"��������\ntalk %x# welcome.46\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 43:
		if ( who->get_legend(TASK_42,23) && !who->get_legend(TASK_42,24) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_42,24);
			who->add_exp(98000);
			who->add_potential(1800);
			who->add_cash(89000);
			send_user(who,"%c%s",';',"̽������ ���� 98000 Ǳ�� 1800 ��Ǯ 89000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,83,"" );
			me->do_welcome(42);
        	} 
		break;
	case 44:
		if ( who->get_legend(TASK_42,24) && !who->get_legend(TASK_42,25) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_42,25);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,84,"Ϊ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ϊ�����");
        	}
		break;
	case 45:
		if ( who->get_legend(TASK_42,26) && !who->get_legend(TASK_42,27) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_42,27);
			who->add_exp(97000);
			who->add_potential(1850);
			who->add_cash(90000);
			send_user(who,"%c%s",';',"Ϊ����� ���� 97000 Ǳ�� 1850 ��Ǯ 90000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,84,"" );
			me->do_welcome(42);
        	} 
		break;
	case 46:
		if ( who->get_legend(TASK_42,27) && !who->get_legend(TASK_43,1) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		TASK_LEGEND_D->give_item(who,"item/98/0207",1);  
        		who->set_legend(TASK_43,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,85,"����ʵ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ʵ��");
        	}
		break;
	case 47:
		if ( who->get_legend(TASK_43,5) && !who->get_legend(TASK_43,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������˵�����������������Χ��������ѣ�����඼���Գ��ǿ�һ������ʧ�٣�ʧ�ٵ�������Ů���������٣����ڸ���ԭί������Ҳ�벻���ס�����֮��Ȳ���ʶ���ֲ����࣬����ʲôԭ��ʹ������ʧ���أ�\n"ESC"�������\ntalk %x# welcome.48\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_43,6) && !who->get_legend(TASK_43,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������и����ܹ������㳹����£������ղ�������Ҳ�������ǰ��İ��������˿���Ҫʧ�ٵ��Գ�����ڴ�һ�����и����ѽ���������㽫��д�İݷ��Ÿ������������ܹ�͸¶����������\n"ESC"��������\ntalk %x# welcome.49\n"ESC"�뿪", me->get_name(),getoid(me)));

		break;
	case 48:
		if ( who->get_legend(TASK_43,5) && !who->get_legend(TASK_43,6) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_43,6);
			who->add_exp(93000);
			who->add_potential(1750);
			who->add_cash(91000);
			send_user(who,"%c%s",';',"ѯ������ ���� 93000 Ǳ�� 1750 ��Ǯ 91000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,88,"" );
			me->do_welcome(47);
        	} 
		break;
	case 49:
		if ( who->get_legend(TASK_43,6) && !who->get_legend(TASK_43,7) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		TASK_LEGEND_D->give_item(who,"item/98/0209",1);  
        		who->set_legend(TASK_43,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,89,"���֪����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���֪����");
        	}
		break;
        }
}