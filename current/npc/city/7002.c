
// �Զ����ɣ�/make/npc/make8002

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GENERAL_D       "/inh/city/general"

inherit OFFICER;

void do_patrol( string arg );
void do_soldier( string arg );
void do_armor( string arg );
void do_welcome( string arg );
void do_defence( string arg );

// ��������ȡ��������
int get_char_picid() { return 5201; }

// ���������촦��
void create()
{
        set_name("����󽫾�");
	set_real_name("����");
        set_city_name("���");

        set_2( "talk", ([
                "patrol"        : (: do_patrol :),
                "soldier"       : (: do_soldier :),
                "armor"         : (: do_armor :),
                "welcome"	: (: do_welcome :),
                "defence"	: (: do_defence :),
        ]) );
//        set("level",45);
//        set("legend",({32*11+24}));
	set("mpLegend",([45:({32*11+24}),50:({32*13+28}),90:({32*32+20}),110:({32*43+20})]));
	set("mpLegend2",([0:({32*32+3,}),45:({32*11+26}),50:({32*13+30}),90:({32*32+22}),110:({32*39+2,32*43+22,})]));
        setup();
}

string get_master() { return CITY_YAN->get_master(); }
string get_master_2() { return CITY_YAN->get_master_2(); }
string get_master_3() { return CITY_YAN->get_master_3(); }

void do_defence(string arg) { "/sys/party/defence"->do_defence(this_player(), this_object(), arg); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( ( who->get_level() >=45 && !who->get_legend(TASK_11,24) ) || ( who->get_legend(TASK_11,24) && !who->get_legend(TASK_11,26) ) )
	{
		tmp = sprintf(ESC HIY "��ս\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >=50 && !who->get_legend(TASK_13,28) ) || ( who->get_legend(TASK_13,28) && !who->get_legend(TASK_13,30) ) )
	{
		tmp += sprintf(ESC HIY "��ȫ����\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( who->get_legend(TASK_32,2) && !who->get_legend(TASK_32,3) )
	{
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.7\n",getoid(me));
	}
	if ( ( who->get_level() >=90 && !who->get_legend(TASK_32,20) ) || ( who->get_legend(TASK_32,20) && !who->get_legend(TASK_32,22) ) )
	{
		tmp += sprintf(ESC HIY "����ԴȪ\ntalk %x# welcome.9\n",getoid(me));
	}
	if ( who->get_level() >=110 && who->get_legend(TASK_39,1) && !who->get_legend(TASK_39,2) )
	{
		tmp += sprintf(ESC HIY "��ݲ���\ntalk %x# welcome.12\n",getoid(me));
	}
	if ( ( who->get_level() >=110 && !who->get_legend(TASK_43,20) ) || ( who->get_legend(TASK_43,20) && !who->get_legend(TASK_43,22) ) )
	{
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.14\n",getoid(me));
	}
	if ("/sys/sys/count"->get_war_flag1()||"/sys/party/defence"->get_count())
		tmp += sprintf(ESC HIY "�ʳǱ���ս\ntalk %x# defence.1\n",getoid(me));	
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GENERAL_D->do_look( who, me ); 
	
}
void do_patrol( string arg ) { GENERAL_D->do_patrol( this_player(), this_object(), arg ); }
void do_soldier( string arg ) { GENERAL_D->do_soldier( this_player(), this_object(), arg ); }
void do_armor( string arg ) { GENERAL_D->do_armor( this_player(), this_object(), arg ); }
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
        	if ( who->get_level() >=45 && !who->get_legend(TASK_11,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ҿ������ܲ��ܶԸ������ս�ɡ���ȥ����ɽһ������10ֻ����������֤�����������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_11,24) && !who->get_legend(TASK_11,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ҫ���ͣ��𹼸����Ҷ����������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_11,25) && !who->get_legend(TASK_11,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ȼ��������Ŭ���������ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=45 && !who->get_legend(TASK_11,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,24);
        		who->delete_save_2("huabaojing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,18,"��ս" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ս");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_11,25) && !who->get_legend(TASK_11,26) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_11,26);
        		who->delete_save_2("huabaojing");
			who->add_exp(5000);
			who->add_potential(160);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"��ս ���� 5000 Ǳ�� 160 ��Ǯ 4000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,18,"" );
        	}
        	break;   
	case 4:
        	if ( who->get_level() >=50 && !who->get_legend(TASK_13,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    פ�����೤���ϵ���Щ���ܱ����ǵ���Ӿ�Ӫ�����ӳ����ģ�˵�������������ֻ�߻�һ����ı���������Ǹ�������������ÿ�춼���ĵ���������Ҫ��ô���������⣬���뷢�������������������һֱû���˰��ң����������ã���ȥ�೤����������ǰɣ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,28) && !who->get_legend(TASK_13,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����㲻������������Ļ�����֤�����ǵ�����̫ǿ��������Ҫ�����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,29) && !who->get_legend(TASK_13,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ƾ��һ�˵�������ԶԶ�����ģ������������־ʿ������Խ��������ң�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
		if ( who->get_level() >= 50 && !who->get_legend(TASK_13,28) ) 
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,28);
        		who->delete_save_2("jjdaodunbing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,22,"��ȫ����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ȫ����");
        	}
		break;
	case 6:
		if ( who->get_legend(TASK_13,29) && !who->get_legend(TASK_13,30) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,30);
        		who->delete_save_2("jjdaodunbing");
			who->add_exp(5800);
			who->add_potential(230);
			who->add_cash(4700);
			send_user(who,"%c%s",';',"��ȫ���� ���� 5800 Ǳ�� 230 ��Ǯ 4700");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,22,"" );
        	}
		break;
	case 7:
		if ( who->get_legend(TASK_32,2) && !who->get_legend(TASK_32,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ǵ�˵�е�ħ��ô����Ҫ�ú��о�һ�£�����٣��ͣ�\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 8:
        	if ( who->get_legend(TASK_32,2) && !who->get_legend(TASK_32,3) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",8) != 1 )
        			return;
        		who->delete_save("ygswdandao");
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_32,3);
			who->add_exp(62000);
			who->add_potential(900);
			who->add_cash(53000);
			send_user(who,"%c%s",';',"���� ���� 62000 Ǳ�� 900 ��Ǯ 53000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,43,"" );
        	}
        	break;
	case 9:
        	if ( who->get_level() >=90 && !who->get_legend(TASK_32,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ҳ�������¸�����������ս�ķ���˭֪���������̣ܽ�������Ȼ���ҷ��������ڵй�������������ȫ����û��Ҫ��������������������������ĲƱ����ֿ�ʼ�ڸ�����ɱ°�ӣ�һ���ӻ�����Ů�Ӹ��������������˵�Ļ������ǻ���û������ͬ����ǰ�ǳ���ս��ͨ��֮����ϵ��������˴����֮ͽ��ʵ��������������������ң�����ϣ���ֱ�����Ǵ���ĳ��裡����������ǰȥ��¹��ʯ�Ŵ壬��������ʬ��ϣ�\n"ESC"��������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_32,20) && !who->get_legend(TASK_32,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���治������������ͷ֮���ѽ⣬Ҳ�Բ��𵱳��ǳ���ս����ȥ������ʿ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_32,21) && !who->get_legend(TASK_32,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ʬ���ںδ������ˣ��������ʬ�󣬸���ͷ­���ھ�Ӫ�Ϸ���ʬ�������ι������ÿ�����μ���ͽ���³���\n"ESC"�������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 10:
		if ( who->get_level() >= 90 && !who->get_legend(TASK_32,20) ) 
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_32,20);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,47,"����ԴȪ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ԴȪ");
        	}
		break;
	case 11:
		if ( who->get_legend(TASK_32,21) && !who->get_legend(TASK_32,22) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_32,22);
			who->add_exp(68000);
			who->add_potential(915);
			who->add_cash(57000);
			send_user(who,"%c%s",';',"����ԴȪ ���� 68000 Ǳ�� 915 ��Ǯ 57000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,47,"" );
        	}
		break;
	case 12:
		if ( who->get_level() >=110 && who->get_legend(TASK_39,1) && !who->get_legend(TASK_39,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ǵģ�������Ǿ���ȷʵ���б��������������Ȥ������Խ��������ԡ�\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 13:
		if ( who->get_level() >=110 && who->get_legend(TASK_39,1) && !who->get_legend(TASK_39,2) )
		{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_39,2);
			who->add_exp(48000);
			who->add_potential(610);
			who->add_cash(45000);
			send_user(who,"%c%s",';',"��ݲ��� ���� 48000 Ǳ�� 610 ��Ǯ 45000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,93,"" );
        	} 
        	break; 
	case 14:
        	if ( who->get_level() >=110 && !who->get_legend(TASK_43,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����۲Ŵ��ԣ�������Ӣ�����䣬������ʿ�Ǳ�Ϊ�顭�������ԣ���ͬ��ͬ�£�������������һ�ģ������������µ�ʱ���Ѿ����죬�Ҿ����ռ�����Σ��׻�˵����δ�����������У������Ĵ����پ�Ȼ��û�а����Ǿ��������룬��������50����ȥ�ˣ���ô������ΪӢ�۵��㣬��û�б�Ч���ҵľ��򰡣�����������ȥ��ħ�����������8���Ϲϡ�12���ܲ���7������������������ô�����ߺߣ����벽�����ٵĺ��𣬲�����������ܰ�ʱ�һ����������������ͣ�\n"ESC"��������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_43,20) && !who->get_legend(TASK_43,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ɲ�ҪС����㶫�������ȱ�����Ҫ���������������Ĺ���������˶��֣�������ʳ������ʰ�����ߣ��㻹������ǰȥ�ɡ�������������ʿ���������̵Ĵ����پ���������ͱ��ͱ���������̵ĵط��������ٷ�����ҵĽ�����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_43,21) && !who->get_legend(TASK_43,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ţ����������Ǳ�����������գ��������µ�����֮�⣬��������������������һ��ӵ�����ճƺţ����������ұ���һ�Ȱ����ж��٣�����������������ǰ����ƽ�ȣ�����������������������������������У�����Ķ��ӣ�\n"ESC"�������\ntalk %x# welcome.16\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 15:
		if ( who->get_level() >=110 && !who->get_legend(TASK_43,20) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_43,20);
        		who->delete_save("ygdjjnangua");
        		who->delete_save("ygdjjluobo");
        		who->delete_save("ygdjjjidan");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,50,"��Ӫ�Ĳ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ӫ�Ĳ���");
        	}
		break;
	case 16:
		if ( who->get_legend(TASK_43,21) && !who->get_legend(TASK_43,22) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���Ϲ�",8) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"���ܲ�",12) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0213",8);
        			return;
        		}
        		if (TASK_LEGEND_D->check_task_item(who,"������",7) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0213",8);
				TASK_LEGEND_D->give_item(who,"item/98/0214",12);
        			return;
        		}
        		TASK_LEGEND_D->give_item(who,"item/product/62091",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_43,22);
        		who->delete_save("ygdjjnangua");
        		who->delete_save("ygdjjluobo");
        		who->delete_save("ygdjjjidan");
			who->add_exp(98000);
			who->add_potential(1100);
			who->add_cash(95000);
			send_user(who,"%c%s",';',"��Ӫ�Ĳ��� ���� 98000 Ǳ�� 1100 ��Ǯ 95000 ��ħ��ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,50,"" );
        	}
		break;
 	case 99:
 		GENERAL_D->do_look( who, me); 
 		break;
        }
}