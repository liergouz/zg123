
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5801; }

// ���������촦��
void create()
{
        set_name( "���Ϻ�" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));

        setup();
}

// �������Ի�����
void do_look( object who )
{
        string tmp="";
        int level, gold, exp;
        
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        send_user( who, "%c%s", ':', get_name() + "��\n����ͳ���ͷ�Ⱦư����������ȵ���������ѽ��\n"
        +tmp +
        ESC"�뿪" );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,j,k,size,*tmp=({}),*res=({}),p,amount;
	object who,item,item1,*inv;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
//        switch(flag)
//        {
//
//	}
}