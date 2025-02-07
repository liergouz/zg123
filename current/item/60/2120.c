
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("凤天铠甲");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(71500);
        set_max_lasting(37599);
        set("dp", 275);
        set("pp", 175);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// 函数：获取描述
string get_desc()
{
        return "凤天铠甲";
}
