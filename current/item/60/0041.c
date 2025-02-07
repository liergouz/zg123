
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("侠士装");
        set_picid_1(6013);
        set_picid_2(6013);
        set_unit("件");

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 50);
        set("pp", 50);
        set("hp", 45);
        set("mp", 45);

        setup();

        set_gender(1);
        set_armor_code(M_JINZHUANG);
        set_armor_color_1(0x416282e2);
        set_armor_color_2(0x000018a0);
}

// 函数：获取描述
string get_desc()
{
        return "侠士装";
}
