
#include <equip.h>

inherit ARMOR;

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(6100);
        set_picid_2(6100);
        set_unit("��");

        set_level(0);
        set_value(1);
        set_max_lasting(900);
        set("dp", 10);
        set("pp", 10);
        set("hp", 5);
        set("mp", 5);

        setup();

        set_gender(2);
        set_armor_code(F_DUANSHAN);
        set_armor_color_1( H_PINK | H_RED_H );
        set_armor_color_2( H_BLACK | H_BLACK_H );
}

// ��������ȡ����
string get_desc()
{
        return "Ů��װ��";
}
