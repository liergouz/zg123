
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2121; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6015);
        set_picid_2(6015);

        set_level(45);
        set_value(8000);
        set_max_lasting(19899);
        set("ap", 0);
        set("dp", 71);
        set("cp", 0);
        set("pp", 124);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
