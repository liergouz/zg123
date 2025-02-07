#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5415; }

// ���������촦��
void create()
{
        set_name("����");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*10+2,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
        if ( who->get_legend(TASK_10,1) && !who->get_legend(TASK_10,2) ) 
		tmp += sprintf(ESC HIY "�����Ŀ���\ntalk %x# welcome.1\n",getoid(this_object())); 
        send_user( who, "%c%s", ':', sprintf( "%s��\n    ��֪��ɽ�ֹ���ʱ����ֹͣ��������ַ�����������Щ��������񰡡�\n", get_name())
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_10,1) && !who->get_legend(TASK_10,2) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    %s��������˵�����ˣ��������λ����ɽ�����ϸ�͹�����ʹ�ڵ�%s��\n    �Ҿ������������ɽ�����У����ɳ�����̽��̽·������Ȼ�Ҳ��ų�·��������ƥʶ;�������·����ʹ�Ҿ��߳���ɽ�ȣ�����ս����ͣ���ҵô��������ٻع���\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),who->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	break;

        case 2:
        	if ( who->get_legend(TASK_10,1) && !who->get_legend(TASK_10,2) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/64031",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_10,2);
			who->add_exp(4000);
			who->add_potential(130);
			who->add_cash(4000);
			send_user(who,"%c%s",';',"���Ÿ����٣�3�� ���� 4000 Ǳ�� 130 ��Ǯ 4000 ������ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,8,"" );
        	}
        	break;   

        }
}