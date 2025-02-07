
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("凤羽铠甲");
        set_picid_1(6040);
        set_picid_2(6040);

        set_level(90);
        set_value(42000);
        set_max_lasting(31599);
        set("dp", 167);
        set("pp", 123);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// 函数：获取描述
string get_desc()
{
        return "凤羽铠甲";
}
