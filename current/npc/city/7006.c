
// �Զ����ɣ�/make/npc/make8006

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

#define INQUISITOR_D    "/inh/city/inquisitor"

inherit OFFICER;

void do_elect( string arg );
void do_vote( string arg );
void do_score( string arg );

// ��������ȡ��������
int get_char_picid() { return 5102; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�����ʷ");
	set_real_name("��֮");
        set_city_name("���");

        set_2( "talk", ([
                "elect"         : (: do_elect :),
                "vote"          : (: do_vote :),
                "score"         : (: do_score :),
                "welcome"	: (: do_welcome :),
        ]) );
//	set("level",50);
//	set("legend",({32*13+10})); 
	set("mpLegend",([50:({32*13+10,32*14+7}),]));
	set("mpLegend2",([50:({32*13+12,32*14+9,32*14+12,}),]));
        setup();
}

string get_master() { return CITY_YAN->get_master(); }
string get_master_2() { return CITY_YAN->get_master_2(); }
string get_master_3() { return CITY_YAN->get_master_3(); }

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_13,10) ) || ( who->get_legend(TASK_13,10) && !who->get_legend(TASK_13,12) ) )
	{
		tmp = sprintf(ESC HIY "������˵\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_14,7) ) || ( who->get_legend(TASK_14,7) && !who->get_legend(TASK_14,9) ) )
	{
		tmp += sprintf(ESC HIY "�ռ�Բ��\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( ( who->get_legend(TASK_14,9) && !who->get_legend(TASK_14,10) ) || ( who->get_legend(TASK_14,10) && !who->get_legend(TASK_14,12) ) )
	{
		tmp += sprintf(ESC HIY "�ռ���\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( ( who->get_legend(TASK_14,12) && !who->get_legend(TASK_14,13) ) || ( who->get_legend(TASK_14,13) && !who->get_legend(TASK_14,14) ) )
	{
		tmp += sprintf(ESC HIY "ȡ��\ntalk %x# welcome.4\n",getoid(me));
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"�Ի�\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		INQUISITOR_D->do_look( who, this_object() ); 
	
}
void do_elect( string arg ) { INQUISITOR_D->do_elect( this_player(), this_object(), arg ); }
void do_vote( string arg ) { INQUISITOR_D->do_vote( this_player(), this_object(), arg ); }
void do_score( string arg ) { INQUISITOR_D->do_score( this_player(), this_object(), arg ); }

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
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_13,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵��һ��������ֻҪ������������֮ͥ�ϣ������ô�����ͥ���������ܵ�Ѭ�գ����Ǳ���������κ�̰������֮��ᱻ�����������������������������ͥ�Ϲ�������һ����������ô̰������֮ͽ�ͻ�Խ��Խ���ˣ����ҵĹ���Ҳ��Խ��Խ���ɡ�\n    ��������֣����һ������������������ȥ���������ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_13,10) && !who->get_legend(TASK_13,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ѵ�ֻ�Ǹ���˵����ϣ������ȷʵ���ڡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_13,11) && !who->get_legend(TASK_13,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������˴����������Ժ�참�����������ϸ�¡�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        		
        	break;
	case 2:
        	if( who->get_level() >=50 && !who->get_legend(TASK_13,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_13,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,14,"������˵" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������˵");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_13,11) && !who->get_legend(TASK_13,12) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),50,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_13,12);
			who->add_exp(5800);
			who->add_potential(210);
			who->add_cash(5000);
			send_user(who,"%c%s",';',sprintf("������˵ ���� 5800 Ǳ�� 210 ��Ǯ 5000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,14,"" );
        	}
        	break; 
        case 4:
        	if ( who->get_level() >= 50 && !who->get_legend(TASK_14,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ƽʱ�һ��е�۲����ǵİ��ã��������ܸ�������Ĺ۲쵽���ǵ���������ȥ�೤�Ǹ����ռ�3���������������Բ��������\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_14,7) && !who->get_legend(TASK_14,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿������е��Ѷȣ���������ϣ���������ҡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_14,8) && !who->get_legend(TASK_14,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл�㣬�����ҿ��Կ�ʼ�������ˣ������ҿ��ܻ���Ҫ��İ�æ��\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_14,9) && !who->get_legend(TASK_14,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ƽʱ�һ��е�۲����ǵİ��ã��������ܸ�������Ĺ۲쵽���ǵ���������ȥ�೤�Ǹ����ҵ��������������Ҫ�Ľ��������\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_14,10) && !who->get_legend(TASK_14,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���¿������е��Ѷȣ���������ϣ���������ҡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_14,11) && !who->get_legend(TASK_14,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл�㣬�����ҿ��Կ�ʼ�������ˣ������ҿ��ܻ���Ҫ��İ�æ��\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
         	else if ( who->get_legend(TASK_14,12) && !who->get_legend(TASK_14,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ˣ�����ȡ�����֣�������3��Բ����Ҳ�ø���ȡ�������֣���˵���Թ������һλ���ˣ�֪ʶԨ������ȥ���������ɡ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_14,13) && !who->get_legend(TASK_14,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ƿ�ȡ�������ˣ�\n"ESC"�뿪", me->get_name()));
           		
        	break;
	case 5:
        	if( who->get_level() >=50 && !who->get_legend(TASK_14,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,7);
        		who->delete_save_2("ysyuanhuan");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,25,"���ǣ�1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ǣ�1��");
        	}
        	break;       
        case 6:
        	if ( who->get_legend(TASK_14,8) && !who->get_legend(TASK_14,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Բ��",3) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,9);
        		who->delete_save_2("ysyuanhuan");
			who->add_exp(4000);
			who->add_potential(140);
			who->add_cash(2800);
			send_user(who,"%c%s",';',"���ǣ�1�� ���� 4000 Ǳ�� 140 ��Ǯ 2800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,25,"" );
			me->do_welcome(4);
        	}
        	break; 
	case 7:
        	if( who->get_legend(TASK_14,9) && !who->get_legend(TASK_14,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,26,"���ǣ�2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ǣ�2��");
        	}
        	break;       
        case 8:
        	if ( who->get_legend(TASK_14,11) && !who->get_legend(TASK_14,12) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_14,12);
			who->add_exp(4000);
			who->add_potential(140);
			who->add_cash(2800);
			send_user(who,"%c%s",';',"���ǣ�2�� ���� 4000 Ǳ�� 140 ��Ǯ 2800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,26,"" );
			me->do_welcome(4);
        	}
        	break; 
	case 9:
        	if( who->get_legend(TASK_14,12) && !who->get_legend(TASK_14,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_14,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,27,"���ǣ�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ǣ�3��");
        	}
        	break;    
        case 99:	
		INQUISITOR_D->do_look( who, me); 
        	break;  
        }
}