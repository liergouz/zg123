
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>

inherit OFFICER;
string *TalkTable = ({ 
        "����ͷ�������ҵģ����Ҹ����ʵı��ڶ������ס���",
        "���Ҿ����ھֻ���һ��������������˼Ҿ�Ȼû�ա���",
        "���Ҿ����ھֻ������ѷ��磬���������˼Ҿ�Ȼû�ա���",
        "�ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���",
});
void do_task_start();
void do_task_cancel();
void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5302; }

// ���������촦��
void create()
{
        set_name("���ܼ�");
        set_city_name("����");


	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));

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
	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"�뿪"
			);

}