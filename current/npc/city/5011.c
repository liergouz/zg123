
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0651; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�ع�����");
        set_city_name("�ع�");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",43);
//        set("legend",({32*11+11}));
	set("mpLegend",([40:({32*11+11}),110:({32*43+17})]));
	set("mpLegend2",([40:({32*11+13}),]));
        setup();
}

string get_master() { return CITY_QIN->get_master(); }
string get_master_2() { return CITY_QIN->get_master_2(); }
string get_master_3() { return CITY_QIN->get_master_3(); }

void do_look( object who ) 
{ 
	string tmp="";
	object me = this_object();
        if ( (who->get_level() >= 40 && !who->get_legend(TASK_11,11)) || (who->get_legend(TASK_11,11)&&!who->get_legend(TASK_11,13)) ) 
		tmp += sprintf(ESC HIY "ħ��ʯ\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_level() >= 110 && !who->get_legend(TASK_43,17) ) 
		tmp += sprintf(ESC HIY "���ѵİ���\ntalk %x# welcome.4\n",getoid(this_object())); 

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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if (who->get_level() >= 40 && !who->get_legend(TASK_11,11))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    һֱ�������Ҷ�������Ҫ�������£���Ȼ�����ǲ�������㣬����Ҫ��ʲô�ġ������Ը������ҳ���������£���һ�����������ģ�\n    ����ȥ������10��ħ��ʯ����ȥ֣���������ռ�����\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,11) && !who->get_legend(TASK_11,12) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������²��ɣ���ɵø���һ������Σ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_11,12) && !who->get_legend(TASK_11,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���³ɹ�����һ�����ٸ��������ģ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if(who->get_level() >= 40 && !who->get_legend(TASK_11,11))
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,11);
        		who->delete_save_2("moqingshi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,7,"ħ��ʯ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ħ��ʯ");
        	}
        	break;
       case 3:
        	if ( who->get_legend(TASK_11,12) && !who->get_legend(TASK_11,13) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"ħ��ʯ",10) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,13);
        		who->delete_save_2("moqingshi");
			who->add_exp(5800);
			who->add_potential(186);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"ħ��ʯ ���� 5800 Ǳ�� 186 ��Ǯ 4000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,7,"" );
        	}
        	break;     
        case 4:
        	if (who->get_level() >= 110 && !who->get_legend(TASK_43,17))
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���в�����ƣ����е�Ϧ������˭֪���úõĹ�Ů��ô̯����̯��ë���أ����а��ռ��м�����Ů���ÿ��ҹ�ﶼ��ͷ�ۣ����˼����������û���κã�Խ����Խ���������������Ż����ʵĴ��Ů�Ǹ�ʹ��������ģ���˶����İ�����˵�������ж���鵤��ҩ������һζ�ȼ�������ѹ��ͷ�ۣ���������Ԯ�ְ�æŪ5�žȼ��������հɣ��ڴ˴����ع�������Ī��л���ˡ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		break;
        case 5:
        	if (who->get_level() >= 110 && !who->get_legend(TASK_43,17))
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_43,17);
        		who->delete_save("qgswjiujd");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,59,"���ѵİ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ѵİ���");
        	}
		break;
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}