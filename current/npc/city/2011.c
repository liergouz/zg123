
// �Զ����ɣ�/make/npc/make8010

#include <npc.h>
#include <city.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5209; }

// ���������촦��
void create()
{
        set_name("��������");
        set_city_name("����");

        setup();
}

string get_master() { return CITY_HAN->get_master(); }
string get_master_2() { return CITY_HAN->get_master_2(); }
string get_master_3() { return CITY_HAN->get_master_3(); }

void do_look( object who ) { GUARDER_D->do_look_3( who, this_object() ); }
