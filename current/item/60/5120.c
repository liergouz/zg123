
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("衾天战衣");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(78500);
        set_max_lasting(16899);
        set("dp", 157);
        set("pp", 295);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// 函数：获取描述
string get_desc()
{
        return "衾天战衣";
}
