
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("龙皮披风");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(65);
        set_value(27000);
        set_max_lasting(22299);
        set("dp", 132);
        set("pp", 88);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// 函数：获取描述
string get_desc()
{
        return "龙皮披风";
}
