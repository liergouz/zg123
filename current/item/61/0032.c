
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(6123);
        set_picid_2(6123);
        set_unit("��");

        set_level(30);
        set_value(2500);
        set_max_lasting(8499);
        set("dp", 40);
        set("pp", 40);
        set("hp", 35);
        set("mp", 35);

        setup();

        set_gender(2);
        set_armor_code(F_JINZHUANG);
        set_armor_color_1(0x416528e8);
        set_armor_color_2(0x00001061);
}

// ��������ȡ����
string get_desc()
{
        return "����";
}
