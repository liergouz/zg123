
// �Զ����ɣ�/make/npc/make8008

#include <npc.h>
#include <city.h>

#define WARDER_D        "/inh/city/warder"

inherit OFFICER;

void do_faling();
void accept_task();

// ��������ȡ��������
int get_char_picid() { return %04d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_city_name("%s");

        set_2( "talk", ([
                "faling"        : (: do_faling :),
                 "accept_task"	: (: accept_task :),
        ]) );

        setup();
}

string get_master() { return %s->get_master(); }
string get_master_2() { return %s->get_master_2(); }
string get_master_3() { return %s->get_master_3(); }

void do_look( object who ) { WARDER_D->do_look( who, this_object() ); }

void do_faling() { WARDER_D->do_faling( this_player(), this_object() ); }

void accept_task() { WARDER_D->accept_task( this_player(), this_object() );}