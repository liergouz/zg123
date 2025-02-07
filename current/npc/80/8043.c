
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
void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5805; }

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("����");

	set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
	set("mpLegend2",([10:({32*37+16,}),]));
        setup();
}
// �������Ի�����
void do_look( object who ) 
{
	string tmp="";
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}        

        tmp += CHAIN_D->get_chain_menu(who,this_object());
	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
		tmp += sprintf(ESC HIY "�չ��鱦\ntalk %x# welcome.1\n",getoid(this_object()));

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
        int flag, date , status, p, z, x, y, i,amount,size;
        object who, obj, item,*inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
	 	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
			send_user(who,"%c%s",':',sprintf("%s:\n    ��Ȼ�ǼҴ����񣬲���������ߵļ۸��Ҷ��������ģ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;        		
			TASK_LEGEND_D->give_item(who,"item/final/33/1701",2);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_37,16);
			who->add_exp(300);
			who->add_potential(30);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"�չ��鱦 ���� 300 Ǳ�� 30 ��Ǯ 1000 ���ع� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,42,"" );
        	}
        	break;
 
        }
}