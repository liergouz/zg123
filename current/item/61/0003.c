
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("ϸ����");
        set_picid_1(6120);
        set_picid_2(6120);
        set_unit("��");

        set_level(0);
        set_value(850);
        set_max_lasting(2799);
        set("dp", 10);
        set("pp", 10);
        set("hp", 5);
        set("mp", 5);

        setup();

        set_gender(2);
        set_armor_code(F_BUYI);
        set_armor_color_1(0x20c23901);
        set_armor_color_2(0x000020e2);
}

// ��������ȡ����
string get_desc()
{
        return "ϸ����";
}
