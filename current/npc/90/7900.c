
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;
string accept_quest(string arg);
// ��������ȡ��������
string get_fam_name() { return "������"; }

// ��������ȡ��������
int get_char_picid() { return 4135; }

// ��������ȡ����˳��
int get_fam_order() { return 8; }

// ���������촦��
void create()
{
        set_name( "����" );
        set_2( "talk", ([
                "accept_quest"            : (: accept_quest :),  
        ]));
        setup();
}

// ������������ֽ���
void do_look( object who ) { TASK_MASTER_D->do_look_quest8( who, this_object() ); }
void accept_quest(string arg) { TASK_MASTER_D->accept_quest8( this_player(), this_object(),arg); }
