
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("�ֲ���");
        set_picid_1(6010);
        set_picid_2(6010);
        set_unit("��");

        set_level(0);
        set_value(850);
        set_max_lasting(2799);
        set("dp", 10);
        set("pp", 10);
        set("hp", 5);
        set("mp", 5);

        setup();

        set_gender(1);
        set_armor_code(M_BUYI);
        set_armor_color_1(0x296439c3);
        set_armor_color_2(0x00002124);
}

// ��������ȡ����
string get_desc()
{
        return "�ֲ���";
}
