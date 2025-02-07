
#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// ��������ȡ��������
string get_fam_name() { return "����"; }

// ��������ȡ��������
int get_char_picid() { return 5105; }

// ��������ȡ����˳��
int get_fam_order() { return 5; }

void do_info();
void accept_task(string arg) ;

// ���������촦��
void create()
{
        set_name( "�Ƽ��ܹ�" );
        set_2( "talk", ([
                "info"          : (: do_info :),
                "accept_task"          : (: accept_task :),
        ]));        
        setup();
}

void do_info()
{
        object player, master;
        player = this_player();
        master = this_object();
        send_user( player, "%c%s", ':', sprintf("%s��\n����Ե��������ʾƵ���ϰ壬��������ͨ��ûʲô��֪���ġ�", master->get_name() ) );
}

// ������������ֽ���
void do_look( object who ) { TASK_MASTER_D->do_look_quest9( who, this_object() ); }

// �����İ���Ʒ
int accept_object( object player, object obj ) 
{
	object who = this_object();
	return TASK_MASTER_D->accept_object2( who, player, obj ); 
}

int accept_money(object who, int gold)
{
	return TASK_MASTER_D->accept_money(this_object(), who, gold);
}

void accept_task( string arg ) { TASK_MASTER_D->accept_task9( this_player(), this_object(),arg ); }