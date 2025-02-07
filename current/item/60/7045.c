
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("苍昆衣");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(45);
        set_value(18500);
        set_max_lasting(7899);
        set("dp", 70);
        set("pp", 118);

        setup();

        set_gender(1);
        set_armor_code(3);
}

// 函数：获取描述
string get_desc()
{
        return "苍昆衣";
}
