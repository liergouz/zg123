
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("龙头素裙");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(50);
        set_value(22500);
        set_max_lasting(8499);
        set("dp", 71);
        set("pp", 127);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// 函数：获取描述
string get_desc()
{
        return "龙头素裙";
}
