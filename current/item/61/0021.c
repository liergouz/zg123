
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("ϸ����");
        set_picid_1(6110);
        set_picid_2(6110);
        set_unit("��");

        set_level(20);
        set_value(1350);
        set_max_lasting(6699);
        set("dp", 30);
        set("pp", 30);
        set("hp", 25);
        set("mp", 25);

        setup();

        set_gender(2);
        set_armor_code(F_BUYI);
        set_armor_color_1(0x200a6188);
        set_armor_color_2(0x000010a4);
}

// ��������ȡ����
string get_desc()
{
        return "ϸ����";
}
