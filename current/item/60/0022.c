
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("�޲���");
        set_picid_1(6020);
        set_picid_2(6020);
        set_unit("��");

        set_level(20);
        set_value(1350);
        set_max_lasting(6699);
        set("dp", 30);
        set("pp", 30);
        set("hp", 25);
        set("mp", 25);

        setup();

        set_gender(1);
        set_armor_code(M_BUYI);
        set_armor_color_1(0x310228c0);
        set_armor_color_2(0x00001060);
}

// ��������ȡ����
string get_desc()
{
        return "�޲���";
}
