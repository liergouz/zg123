
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "����ͷ�������ҵģ����Ҹ����ʵı��ڶ������ס���",
        "���Ҿ����ھֻ���һ��������������˼Ҿ�Ȼû�ա���",
        "���Ҿ����ھֻ������ѷ��磬���������˼Ҿ�Ȼû�ա���",
        "�ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���",
});
void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5701; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("��Ϊ");
        set_city_name("����");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
	set("mpLegend2",([0:({32*26+21,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_26,20) && !who->get_legend(TASK_26,21) )
		tmp += sprintf(ESC HIY "Ѱ�˱���\ntalk %x# welcome.1\n",getoid(me));
			
	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
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
        	if ( who->get_legend(TASK_26,20) && !who->get_legend(TASK_26,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ʲô�����Ѿ���ɱ�������Ǹ��ɶ������ɱ���ˣ����������ֻ�ѽ��Ϊ���ҵ��������������ĵ��ģ�����Ϊ�������壬�Ҳ������������Ƿ���ȥ�ˣ��ұ���������Ҳлл��Ϊ��������ô����£����治֪������ôлл��ã���������ǰ���̵�ʱ���ҵ���һ������ը��ͼֽ���ҾͰ�����͸���ɡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if ( who->get_legend(TASK_26,20) && !who->get_legend(TASK_26,21) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/66043",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_26,21);
			who->add_exp(41000);
			who->add_potential(600);
			who->add_cash(40000);
			send_user(who,"%c%s",';',"Ѱ�˱��� ���� 41000 Ǳ�� 600 ��Ǯ 40000 ����ը��ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,35,"" );
        	}
        	break;
	}
}