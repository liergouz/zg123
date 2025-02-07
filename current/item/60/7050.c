
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("跃天袍");
        set_picid_1(6058);
        set_picid_2(6058);

        set_level(50);
        set_value(22500);
        set_max_lasting(8499);
        set("dp", 76);
        set("pp", 130);

        setup();

        set_gender(1);
        set_armor_code(3);
}

// 函数：获取描述
string get_desc()
{
        return "跃天袍";
}
