
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("棉布衣");
        set_picid_1(6003);
        set_picid_2(6003);

        set_level(10);
        set_value(1200);
        set_max_lasting(4599);
        set("dp", 19);
        set("pp", 0);

        setup();

        set_gender(1);
        set_armor_code(0);
}

// 函数：获取描述
string get_desc()
{
        return "棉布衣";
}
