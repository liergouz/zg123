
#include <equip.h>

inherit ARMOR;

// 函数：构造处理
void create()
{
        set_name("粗麻衣");
        set_picid_1(6010);
        set_picid_2(6010);
        set_unit("件");

        set_level(10);
        set_value(1200);
        set_max_lasting(4599);
        set("dp", 20);
        set("pp", 20);
        set("hp", 15);
        set("mp", 15);

        setup();

        set_gender(1);
        set_armor_code(M_BUYI);
        set_armor_color_1(0x296439c3);
        set_armor_color_2(0x00002124);
}

// 函数：获取描述
string get_desc()
{
        return "粗麻衣";
}
