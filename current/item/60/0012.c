
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6020);
        set_picid_2(6020);
        set_unit("��");

        set_level(10);
        set_value(1200);
        set_max_lasting(4599);
        set("dp", 20);
        set("pp", 20);
        set("hp", 15);
        set("mp", 15);

        setup();

        set_gender(1);
        set_armor_code(M_BUYI);
        set_armor_color_1(0x310228c0);
        set_armor_color_2(0x00001060);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
