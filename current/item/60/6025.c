
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("蓝缎衣");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3500);
        set_max_lasting(5499);
        set("dp", 41);
        set("pp", 67);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// 函数：获取描述
string get_desc()
{
        return "蓝缎衣";
}
