
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("���ӷ�");
        set_picid_1(6005);
        set_picid_2(6005);
        set_unit("��");

        set_level(50);
        set_value(5000);
        set_max_lasting(10599);
        set("dp", 60);
        set("pp", 60);
        set("hp", 55);
        set("mp", 55);

        setup();

        set_gender(1);
        set_armor_code(M_CHANGPAO);
        set_armor_color_1(0x392151c1);
        set_armor_color_2(0x00004208);
}

// ��������ȡ����
string get_desc()
{
        return "���ӷ�";
}
