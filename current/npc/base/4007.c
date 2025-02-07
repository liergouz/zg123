
// �Զ����ɣ�/make/npc/make0007

#include <npc.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

// ����������ʦ��
int is_repairer() { return 1; }

// ��������ȡ��������
int get_char_picid() { return 5407; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("������ϰ�");
	set_real_name("ʯ��");
        set_city_name("κ��");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level", 21);
//        set("legend", ({ 32*5+13 }));  
 	set("mpLegend",([20:({32*5+13}),]));
 	set("mpLegend2",([20:({32*5+15}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();	
	"/quest/help"->send_help_tips(who, 52);
	if ( ( who->get_level() >= 20 && !who->get_legend(TASK_05,13) ) || ( who->get_legend(TASK_05,13) && !who->get_legend(TASK_05,15) ) )
	{
		tmp = sprintf(ESC HIY "���صĴ�˵\ntalk %x# welcome.1\n",getoid(me));
	}

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_normal_word(me) + "\n"ESC"����ͼ���\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		REPAIR_CMD->main( who, sprintf( "%x#", getoid( this_object() ) ) );
	
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
        	if ( who->get_level() >=20 && !who->get_legend(TASK_05, 13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������÷з��������ʲô����֪������һ�����Ҵ����������˵�����һ����ΰٲ��Ĺ�Ч���Ҽҷ���һֱ����״��Ƿ�ѣ�����������ҵ���ֻ���ң�һ����ʹ���Ĳ�������ɫ��\n    ������Ϊʲô�Լ���ȥ�ң�����Ϊ�����κ��˶����ҵ���ǰЩ�����и����κ��и����ң�����Ҫһ����%s���˲�����ֻ���ҵ���Ե�ˣ��ҵ��˺þã����ڵȵ�������ϣ�����ܰ������æ��\n    ���Ҵ�̽������Ϣ����ֻ�����ƺ������˾�¹�ķɻ�կ�������ɻ�կ��ֱ����ǰ�ߣ������Ǹ�װ��ˮ�Ĵ�ˮ�׺��ҹ�����Ͳ��Ҫ�ҵ������ˡ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),who->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_05,13) && !who->get_legend(TASK_05,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ��Ǹ����ҵĹ����Ǳ��˺�Ū�ҵ���Ҫ�������Ǿ����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_05,14) && !who->get_legend(TASK_05,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ǻǡ�������������°�����̫лл���ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_05,13)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_05,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,12,"���صĴ�˵" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���صĴ�˵");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_05,14) && !who->get_legend(TASK_05,15) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,20,BOOTS_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"����",1) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_05,15);
			who->add_exp(1300);
			who->add_potential(70);
			who->add_cash(1000);
			send_user(who,"%c%s",';',sprintf("���صĴ�˵ ���� 1300 Ǳ�� 70 ��Ǯ 1000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,12,"" );
        	}
        	break;
        case 99:
        	REPAIR_CMD->main( who, sprintf( "%x#", getoid( me ) ) );
        	break;
        }
}