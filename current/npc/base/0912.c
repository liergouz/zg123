#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 6; }
// ���Լ���do_look����
int is_self_look() { return 1; }
// ��������ȡ��������
int get_char_picid() { return 5403; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("���޵���ҽ");
        set_city_name("���ִ�");

        set_2( "good", ([
                "01" : "/item/91/9100",
                "02" : "/item/91/9101",
                "03" : "/item/91/9110",
                "04" : "/item/91/9111",
                "05" : "/item/stuff/0106",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 42);
	result = sprintf("%s��\n    �⵺�Ϲ��ﱻ�˸�ʩ��������ʹ�����Ǹ������ߣ�һ��Ҳ���������࣬���Ҫ����ҩƷ��ȥ̽�ա���\n", me->get_name() );
	result = result + sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

}
/*
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {

	}
}
*/	  