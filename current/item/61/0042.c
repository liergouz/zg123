
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("�ʽ���");
        set_picid_1(6123);
        set_picid_2(6123);
        set_unit("��");

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 50);
        set("pp", 50);
        set("hp", 45);
        set("mp", 45);

        setup();

        set_gender(2);
        set_armor_code(F_JINZHUANG);
        set_armor_color_1(0x416528e8);
        set_armor_color_2(0x00001061);
}

// ��������ȡ����
string get_desc()
{
        return "�ʽ���";
}
