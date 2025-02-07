
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("武生服");
        set_picid_1(6003);
        set_picid_2(6003);
        set_unit("件");

        set_level(30);
        set_value(2500);
        set_max_lasting(8499);
        set("dp", 40);
        set("pp", 40);
        set("hp", 35);
        set("mp", 35);

        setup();

        set_gender(1);
        set_armor_code(M_JINZHUANG);
        set_armor_color_1(0x30e35162);
        set_armor_color_2(0x000020e3);
}

// 函数：获取描述
string get_desc()
{
        return "武生服";
}
