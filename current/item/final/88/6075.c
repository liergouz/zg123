
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2196; }

// ���������촦��
void create()
{
        set_name("Զ��Ь");
        set_picid_1(8809);
        set_picid_2(8809);

        set_level(75);
        set_value(9500);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 33);
        set("cp", 0);
        set("pp", 0);
        set("sp", 38);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Զ��Ь";
}
