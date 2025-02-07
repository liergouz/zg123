
// �Զ����ɣ�/make/npc/make8012

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_out();
void do_record();

// ��������ȡ��������
int get_char_picid() { return 0651; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�ع�����");
        set_city_name("�ع�");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
                "welcome"	: (: do_welcome :),
        ]) );
        set("in", 13);
        set("out", 11);
//        set("level",64);
//        set("legend",({32*20+4}));
	set("mpLegend",([60:({32*20+4}),100:({32*39+14})]));
	set("mpLegend2",([60:({32*20+6,}),100:({32*39+16,32*39+19,32*39+22,})]));
        setup();
}

string get_master() { return CITY_QIN->get_master(); }
string get_master_2() { return CITY_QIN->get_master_2(); }
string get_master_3() { return CITY_QIN->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
        if ( (who->get_level() >= 60 && !who->get_legend(TASK_20,4)) || (who->get_legend(TASK_20,4)&&!who->get_legend(TASK_20,6)) ) 
		tmp += sprintf(ESC HIY "ɱ�˶�ħ\ntalk %x# welcome.1\n",getoid(me)); 
        if ( (who->get_level() >= 100 && !who->get_legend(TASK_39,14)) || (who->get_legend(TASK_39,14)&&!who->get_legend(TASK_39,16)) ) 
		tmp += sprintf(ESC HIY "��ħ֮��\ntalk %x# welcome.4\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_39,16) && !who->get_legend(TASK_39,17)) || (who->get_legend(TASK_39,17)&&!who->get_legend(TASK_39,19)) ) 
		tmp += sprintf(ESC HIY "���������\ntalk %x# welcome.4\n",getoid(this_object())); 
        if ( (who->get_legend(TASK_39,19) && !who->get_legend(TASK_39,20)) || (who->get_legend(TASK_39,20)&&!who->get_legend(TASK_39,22)) ) 
		tmp += sprintf(ESC HIY "�����ʵ�\ntalk %x# welcome.4\n",getoid(this_object())); 

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_2( who, me ); 
	
}
void do_out() { GUARDER_D->do_out( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }

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
        	if (who->get_level() >= 60 && !who->get_legend(TASK_20,4))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����س���һ���İ��ճ���Ī�������ʬɱ����׷����ã����ڷ���ԭ�����س�����ɱ�˳��ĵ��ܱ���Ϊ��Ȼ�������׶�������쳣�ƻ������������һ����©���������ֲ�����˶�ͬ�سǵĽ�������϶���������ǰ������Ҹ����ָ�ǿ�������������ܵ�׳ʿȥִ�д��£��ҿ�׳ʿ�����ʵ���Ա����������һ�ˣ�������20��Ϊ��������������Եĵ��ܱ��ɡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_20,4) && !who->get_legend(TASK_20,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ħ�������������ڣ�����δ棬���պο࣡\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_20,5) && !who->get_legend(TASK_20,6) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ⱥ��ħ������Χ���ϰ��տɾͰ��Ķ��ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if(who->get_level() >= 60 && !who->get_legend(TASK_20,4))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_20,4);
        		who->delete_save_2("sarenemo");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,48,"ɱ�˶�ħ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ɱ�˶�ħ");
        	}
        	break;
	case 3:
        	if ( who->get_legend(TASK_20,5) && !who->get_legend(TASK_20,6) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_20,6);
        		who->delete_save_2("sarenemo");
			who->add_exp(7700);
			who->add_potential(270);
			who->add_cash(8000);
			send_user(who,"%c%s",';',"ɱ�˶�ħ ���� 7700 Ǳ�� 270 ��Ǯ 8000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,48,"" );
        	}
        	break;     
	case 4:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_39,14) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ţ�����и���������Ҫ��һ���ǳ���Ҫͬʱ���Ѱ�����飬��Ҫ���������ħ֮�ᣬ��Щ�����������һ���С���ɱ�����ΪʲôҪ���������Ȼ����и�����鷳��������������������ܣ�����û��Ƕ�Զ��á�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_39,14) && !who->get_legend(TASK_39,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҳ����Ļ�����Զ������֪��Ϊʲô��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_39,15) && !who->get_legend(TASK_39,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ˵��������㻹Ҫ�ʣ����ⲻ�����Լ�С������Ϸ�����ǲ��������������������������㻹���߰ɣ�ʲô���㲻�£��ã��ã��ã���ȵ��ң������Ҹ�Ƨ�����䡣\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_39,16) && !who->get_legend(TASK_39,17) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������˵��Ϊ������ˣ����ⲻ��Ϊ����ҿɲ��뱻�����������������������ɣ�����ȥ�������ռ�5�����ߡ�7����ǣ�������˵�ɡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_39,17) && !who->get_legend(TASK_39,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������˵����Ҫ��̫��ĺ����ģ���Ȼ������һ����鷳��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_39,18) && !who->get_legend(TASK_39,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �㻹Ҫ����������к����ĵĻ�������Ҫ�������۵ġ�\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_39,19) && !who->get_legend(TASK_39,20) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������ᰡ�������ҵ�������⵽����׷ɱ��������ȥ�ɵ�������2��ĵ�ɷ������3����3���̫��������6������˵���������ڼ��Ӻ�׷ɱ�㣬��ɵ����ҾͿ��Է��ĸ������ˡ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_39,20) && !who->get_legend(TASK_39,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �㲻������ҷԸ������飬�������������������ģ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_39,21) && !who->get_legend(TASK_39,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������һ��Ȼ�ϵ��ˣ��ҿ�û��ʲô���ܣ�����ǵþ����ʵ׵ģ���ֻ��������ǲ�£�\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 5:
        	if ( who->get_level() >= 100 && !who->get_legend(TASK_39,14) ) 
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,14);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,56,"�����ʵף�1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ʵף�1��");
        	}
        	break;
	case 6:
        	if ( who->get_legend(TASK_39,15) && !who->get_legend(TASK_39,16) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��ħ֮��",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_39,16);
			who->add_exp(35000 );
			who->add_potential(649);
			who->add_cash(55000);
			send_user(who,"%c%s",';',"�����ʵף�1�� ���� 35000  Ǳ�� 649 ��Ǯ 55000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,56,"" );
        		me->do_welcome(4);
        	}
        	break;
        case 7:
        	if ( who->get_legend(TASK_39,16) && !who->get_legend(TASK_39,17) ) 
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,17);
        		who->delete_save("qgswmianxian");
        		who->delete_save("qgswzaojiao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,57,"�����ʵף�2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ʵף�2��");
        	}
        	break;
	case 8:
        	if ( who->get_legend(TASK_39,18) && !who->get_legend(TASK_39,19) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",5) != 1 )
        			return;
        		if (TASK_LEGEND_D->check_task_item(who,"���",7) != 1 )
        		{
				TASK_LEGEND_D->give_item(who,"item/98/0187",5);
        			return;
        		}
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_39,19);
        		who->delete_save("qgswmianxian");
        		who->delete_save("qgswzaojiao");
			who->add_exp(40000);
			who->add_potential(658);
			who->add_cash(38000);
			send_user(who,"%c%s",';',"�����ʵף�2�� ���� 40000 Ǳ�� 658 ��Ǯ 38000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,57,"" );
        		me->do_welcome(4);
        	}
        	break;
        case 9:
        	if ( who->get_legend(TASK_39,19) && !who->get_legend(TASK_39,20) ) 
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_39,20);
        		who->delete_save("qgswdisamzs");
        		who->delete_save("qgswtaijimzs");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,58,"�����ʵף�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����ʵף�3��");
        	}
        	break;
	case 10:
        	if ( who->get_legend(TASK_39,21) && !who->get_legend(TASK_39,22) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64171",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_39,22);
        		who->delete_save("qgswdisamzs");
        		who->delete_save("qgswtaijimzs");
			who->add_exp(145000);
			who->add_potential(1500);
			who->add_cash(148000);
			send_user(who,"%c%s",';',"�����ʵף�3�� ���� 145000 Ǳ�� 1500 ��Ǯ 148000 ����ս��ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,58,"" );
        	}
        	break;
        case 99:
        	GUARDER_D->do_look_2( who, me ); 
        	break;     
        }
}