// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <public.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 9715; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("�ܹ�");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),

        ]));      

        setup();
}

// �������Ի�����
void do_look( object who ) { TEACHER_D->do_look( who, this_object() ); }

void do_welcome( string arg )
{
        object me = this_object();
        TEACHER_D->do_welcome(me,this_player(),arg);
}
