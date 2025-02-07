
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("细布衣");
        set_picid_1(6110);
        set_picid_2(6110);
        set_unit("件");

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
        set_armor_color_1(0x200a6188);
        set_armor_color_2(0x000010a4);
}

// 函数：获取描述
string get_desc()
{
        return "细布衣";
}
