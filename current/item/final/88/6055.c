
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2154; }

// ���������촦��
void create()
{
        set_name("ս��Ь");
        set_picid_1(8809);
        set_picid_2(8809);

        set_level(55);
        set_value(8500);
        set_max_lasting(21899);
        set("ap", 0);
        set("dp", 23);
        set("cp", 0);
        set("pp", 0);
        set("sp", 28);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս��Ь";
}
