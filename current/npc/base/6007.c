
// �Զ����ɣ�/make/npc/make0007

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// ����������ʦ��
int is_repairer() { return 1; }
void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5407; }

// ���������촦��
void create()
{
        set_name("������ϰ�");
	set_real_name("����");
        set_city_name("����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level", 35);
//        set("legend", ({ 32*9+16 }));
 	set("mpLegend",([35:({32*9+16}),]));
 	set("mpLegend2",([35:({32*9+18}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string tmp;
	"/quest/help"->send_help_tips(who, 52);
	if ( ( who->get_level() >= 35 && !who->get_legend(TASK_09,16) ) || ( who->get_legend(TASK_09,16) && !who->get_legend(TASK_09,18) ) )
	{
		tmp = get_name() + "��\n    "+"/quest/word"->get_normal_word(me) + "\n"+
			sprintf("\n"ESC"����ͼ���\ntalk %x# welcome.99\n",getoid(me))+
               		sprintf(ESC HIY "ɽ����Ĺ��\ntalk %x# welcome.1\n",getoid(me)) ;	
	}
	
	if ( stringp(tmp) )
	{
		tmp += ESC"�뿪";
		send_user( who, "%c%s", ':',tmp);
	}	
	else	
        	REPAIR_CMD->main( who, sprintf( "%x#", getoid( me ) ) );
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
       	string *nTmp,tmp;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_09,16) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������һ���Ѿ�����õ�éɽ��ʿ��װ������Ҫ�͹�ȥéɽ��������ɽ��Ĵ��������ߣ����Ѿ���Ǯ��ͨ���ҿ���˳���������˭֪�����ɽ��֪����������һֻ���֣���ס���ҵ�ȥ·��\n    �Ҹ�������̸�����£���˵��Ҳ����ֻ����û�취���ۿ����������ھ�Ҫ���ˡ���֪�����ܷ�������æ������ֻ������ʰ������������ɽ����ɽɽ�����һ���㲻��ı��꣡  \n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_09,16) && !who->get_legend(TASK_09,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���´���Ҳ��ȥ�����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_09,17) && !who->get_legend(TASK_09,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������Ϊ�������˼����°���\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_level() >= 35 && !who->get_legend(TASK_09,16) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_09,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,28,"ɽ����Ĺ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ɽ����Ĺ��");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_09,17) && !who->get_legend(TASK_09,18) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),30,ARMOR_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_09,18);
			who->add_exp(2800);
			who->add_potential(110);
			who->add_cash(2000);
			send_user(who,"%c%s",';',sprintf("ɽ����Ĺ�� ���� 2800 Ǳ�� 110 ��Ǯ 2000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,28,"" );
        	}
        	break;   
 	case 99:
 		REPAIR_CMD->main( who, sprintf( "%x#", getoid( me ) ) );
 		break;
        }
}