
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(6105);
        set_picid_2(6105);
        set_unit("��");

        set_level(50);
        set_value(5000);
        set_max_lasting(10599);
        set("dp", 60);
        set("pp", 60);
        set("hp", 55);
        set("mp", 55);

        setup();

        set_gender(2);
        set_armor_code(F_BEIZI);
        set_armor_color_1(0x3ac359c1);
        set_armor_color_2(0x000018c2);
}

// ��������ȡ����
string get_desc()
{
        return "����";
}
