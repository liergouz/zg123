
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>
#include <equip.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 5805; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
//        set("level",44);
//        set("legend",({32*11+14}));     
	set("mpLegend",([40:({32*11+14})]));
	set("mpLegend2",([40:({32*11+23})]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( (who->get_level() >= 40 && !who->get_legend(TASK_11,14)) || (who->get_legend(TASK_11,14)&&!who->get_legend(TASK_11,15)) ) 
		tmp += sprintf(ESC HIY "���ε�����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_11,22)&&!who->get_legend(TASK_11,23) ) 
		tmp += sprintf(ESC HIY "���ε�����\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    ����ֵ�ý�����������ǣ��Ⱳ��û������ˣ�\n", get_name())
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
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 40 && !who->get_legend(TASK_11,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������һ�������鷳�����飬��Ϊ����̫������Բ���������������ֻ���ҵ�һ���ˣ������Ұ������£�������Ҫ�������ܣ��Ҿ�����������\n    ��Ը���������Ը��Ļ�����ȥ���Թ��������������������˵�����¸���ô�죬���ͻ����׵ģ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_11,14) && !who->get_legend(TASK_11,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���˰���һ����û����ˣ������æ�����Ȼ��Ը����ҡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_11,22)&&!who->get_legend(TASK_11,23) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �µ����ֻ�ܰ����������̵ķ��������ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
 	      	break;
     
        case 2:
        	if( who->get_level() >= 40 && !who->get_legend(TASK_11,14) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_11,14);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,17,"���ε�������1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ε�������1��");
        	}
        	break;

        case 3:
        	if( who->get_legend(TASK_11,22) && !who->get_legend(TASK_11,23) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"��",1) != 1 )
        			return;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),40,NECK_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_11,23);
			who->add_exp(4500);
			who->add_potential(145);
			who->add_cash(3900);
			send_user(who,"%c%s",';',sprintf("���ε�������4�� ���� 4500 Ǳ�� 145 ��Ǯ 3900 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,3,"" );
        	}
        	break;
        }
}