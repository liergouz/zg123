#include <npc.h>
#include <ansi.h>
#include <public.h>
#define ZHONGQIU "sys/party/moon1"

inherit OFFICER;
// ��������ȡ��������
int get_char_picid() { return 6010; }
void do_welcome(string arg);
// ���������촦��
void create()
{
        set_name("�϶�");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );

        setup();
}

void do_look(object who)
{
	ZHONGQIU->do_look(this_object(),who);
}


void do_welcome( string arg )
{
        object me = this_object();
        ZHONGQIU->do_welcome(me, arg);
}

