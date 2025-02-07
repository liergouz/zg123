
// �Զ����ɣ�/make/npc/make8012

#include <npc.h>
#include <city.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

void do_out();
void do_record();

// ��������ȡ��������
int get_char_picid() { return 5209; }

// ���������촦��
void create()
{
        set_name("κ������");
        set_city_name("κ��");

        set_2( "talk", ([
                "out"           : (: do_out :),
                "record"	: (: do_record :),
        ]) );
        set("in", 12);
        set("out", 10);

        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who ) { GUARDER_D->do_look_2( who, this_object() ); }

void do_out() { GUARDER_D->do_out( this_player(), this_object() ); }

void do_record() { GUARDER_D->do_record( this_player(), this_object() ); }
