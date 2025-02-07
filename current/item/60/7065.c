
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("蕲木袍");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(65);
        set_value(34500);
        set_max_lasting(10299);
        set("dp", 94);
        set("pp", 166);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// 函数：获取描述
string get_desc()
{
        return "蕲木袍";
}
