
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("绸衣");
        set_picid_1(6103);
        set_picid_2(6103);
        set_unit("件");

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
        set_armor_color_1(0x28e16222);
        set_armor_color_2(0x000020c0);
}

// 函数：获取描述
string get_desc()
{
        return "绸衣";
}
