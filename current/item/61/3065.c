
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("战龙彩衣");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(65);
        set_value(32500);
        set_max_lasting(21099);
        set("dp", 159);
        set("pp", 93);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// 函数：获取描述
string get_desc()
{
        return "战龙彩衣";
}
