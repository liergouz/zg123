
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0600; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�Թ�����");
        set_city_name("�Թ�");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",54);
//        set("legend",({32*15+27}));
	set("mpLegend",([50:({32*15+27}),55:({32*38+5}),60:({32*18+10,}),80:({32*27+28})]));
	set("mpLegend2",([50:({32*15+29}),60:({32*18+12,}),80:({32*27+30})]));
        setup();
}

string get_master() { return CITY_ZHAO->get_master(); }
string get_master_2() { return CITY_ZHAO->get_master_2(); }
string get_master_3() { return CITY_ZHAO->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( (who->get_level() >= 50 && !who->get_legend(TASK_15,27)) || (who->get_legend(TASK_15,27)&&!who->get_legend(TASK_15,29)) )
	{
		tmp = sprintf(ESC HIY "�������\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >=60 && !who->get_legend(TASK_18,10)) || (who->get_legend(TASK_18,10) && !who->get_legend(TASK_18,12)) )
		tmp += sprintf(ESC HIY "�������ź�\ntalk %x# welcome.4\n",getoid(me));
	if ( (who->get_level() >= 80 && !who->get_legend(TASK_27,28)) || (who->get_legend(TASK_27,28) && !who->get_legend(TASK_27,30)))
	{
		tmp += sprintf(ESC HIY "¹��\ntalk %x# welcome.7\n",getoid(me));
	}
	if ( who->get_level() >= 55 && !who->get_legend(TASK_38,5) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.10\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		GUARDER_D->do_look_3( who, me ); 
	
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
        	if ( who->get_level() >=50 && !who->get_legend(TASK_15,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Գ��ǵĹ������ǰ���ˣ�����Ŀ�������������Լ������ܺã����������޹�����֪�ж����˻��˻��������ǵļ��£����������˲�����ȥ�������ǣ��ɶ��޹����ˣ�������ϣ�����ܰ����æ��ȥ�Գ��������Թ��������ǵ�ǧ��ҪС�����£����ǵļ�������С����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,27) && !who->get_legend(TASK_15,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����һ�˲����������ǣ��������˰�æ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,28) && !who->get_legend(TASK_15,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ϴ�ҵ�����������������֮ͽ�Ժ󶼲�����ô�����ˡ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_15,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,27);
        		who->delete_save_2("zggongbing");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,6,"�������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_15,28) && !who->get_legend(TASK_15,29) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/65053",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,29);
        		who->delete_save_2("zggongbing");
			who->add_exp(6350);
			who->add_potential(260);
			who->add_cash(5500);
			send_user(who,"%c%s",';',"������� ���� 6350 Ǳ�� 260 ��Ǯ 5500 ��������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,6,"" );
        	}
        	break;  
        case 4:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_18,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ϴ�����С�ӱ�Ϯ���˺�·�����೤���ѵ���ȫ�ߵо���������ʱ��Ȼû���ҵ��о������������������ӾͲ���֤���ҵĹ�ѫ���۹������ˣ���Ը������ҵ�����\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_18,10) && !who->get_legend(TASK_18,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ò��������˹�ȴ���ܷ��ͣ�������Ҳ��\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_18,11) && !who->get_legend(TASK_18,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ҿ������ٷ�������\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 5:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_18,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_18,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,33,"�������ź�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������ź�");
        	}
        	break;
        case 6:
        	if ( who->get_legend(TASK_18,11) && !who->get_legend(TASK_18,12) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,60,NECK_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"�����",1) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_18,12);
			who->add_exp(7000);
			who->add_potential(270);
			who->add_cash(6300);
			send_user(who,"%c%s",';',sprintf("�������ź� ���� 7000 Ǳ�� 270 ��Ǯ 6300 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,33,"" );
        	}
        	break;  
        case 7:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ұ��˵���˿�����Щ�˲��������Ƿ���¹�ǵ��̼֣��������������Ϸ����Լ��Ļ������װױ��������ǣ�ȥ���������ܼ𵽲����Ϻõ�¹�ǣ�����������Ǯ�أ���Ȼ�ˣ�¹��ֻ��������������ʿ������������������ɣ�����Ӷ���Ǿ��Ի���������ģ�Ҫ֪�����������ֵط�¹�ǵ��˿ɾ��ң���Ϊֻ���Ҳ�֪����ô����ȥ¹���ϵĻ�����\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_27,28) && !who->get_legend(TASK_27,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ҵ�¹���أ��ҿ���׼���˷��ı������Ŷ��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_27,29) && !who->get_legend(TASK_27,30) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������õ���Щ¹�ǣ����Ⱳ�Ӷ���ʳ�����ˣ�\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
	case 8:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_27,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_27,28);
        		who->delete_save("zgswlujiao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,44,"¹��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"¹��");
        	}
        	break;
        case 9:
        	if ( who->get_legend(TASK_27,29) && !who->get_legend(TASK_27,30) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"¹��",20) != 1 )
        			return;
        		TASK_LEGEND_D->give_item(who,"item/final/15/1520",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_27,30);
        		who->delete_save("zgswlujiao");
			who->add_exp(48000);
			who->add_potential(680);
			who->add_cash(46000);
			send_user(who,"%c%s",';',"¹�� ���� 48000 Ǳ�� 680 ��Ǯ 46000 ǿЧ���� 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,44,"" );
        	}
        	break;
        case 10:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_38,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵�ع���һ������������Ĺ��������������������һ������̶��򲻵�����˵��������˲��ٵ��ӣ���������ѧϰ����������ͽ����Ҳ�����ļ����޲����ڣ�˵ʵ�����һ����е㶯�ģ�ֻ���Ҳ�֪��������ס���ģ���ȥ�ع������������������ܲ������������ͽ�ܡ�\n"ESC"��������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break; 
        case 11:
        	if ( who->get_level() >= 55 && !who->get_legend(TASK_38,5) )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_38,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHAOGUO,"�Թ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,64,"��������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��������");
        	}
		break;
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}