
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("飞天铠甲");
        set_picid_1(6040);
        set_picid_2(6040);

        set_level(90);
        set_value(50500);
        set_max_lasting(28599);
        set("dp", 214);
        set("pp", 128);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// 函数：获取描述
string get_desc()
{
        return "飞天铠甲";
}
