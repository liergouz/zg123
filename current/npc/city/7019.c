
// �Զ����ɣ�/make/npc/make8019

#include <npc.h>
#include <city.h>

#define ESTIMATOR_D     "/inh/city/estimator"

inherit OFFICER;

void do_upgrade();

// ��������ȡ��������
int get_char_picid() { return 5501; }

// ���������촦��
void create()
{
        set_name("ְҵ����ʦ");
        set_city_name("���");

        set_2( "talk", ([
                "upgrade"       : (: do_upgrade :),
        ]) );

        setup();
}

string get_master() { return CITY_YAN->get_master(); }
string get_master_2() { return CITY_YAN->get_master_2(); }
string get_master_3() { return CITY_YAN->get_master_3(); }

void do_look( object who ) { ESTIMATOR_D->do_look( who, this_object() ); }

void do_upgrade() { ESTIMATOR_D->do_upgrade( this_player(), this_object() ); }
