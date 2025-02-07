
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("棉布衣");
        set_picid_1(6000);
        set_picid_2(6000);
        set_unit("件");

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
        set_armor_color_1(0x51c44a48);
        set_armor_color_2(0x00001881);
}

// 函数：获取描述
string get_desc()
{
        return "棉布衣";
}
