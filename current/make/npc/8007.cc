
// �Զ����ɣ�/make/npc/make8007

#include <npc.h>
#include <city.h>

#define DIPLOMAT_D      "/inh/city/diplomat"

inherit OFFICER;

void do_relation( string arg );

// ��������ȡ��������
int get_char_picid() { return %04d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_city_name("%s");

        set_2( "talk", ([
                "relation"      : (: do_relation :),
        ]) );

        setup();
}

string get_master() { return %s->get_master(); }
string get_master_2() { return %s->get_master_2(); }
string get_master_3() { return %s->get_master_3(); }

void do_look( object who ) { DIPLOMAT_D->do_look( who, this_object() ); }

void do_relation( string arg ) { DIPLOMAT_D->do_relation( this_player(), this_object(), arg ); }
