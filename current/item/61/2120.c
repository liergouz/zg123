
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("凤天战袍");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(120);
        set_value(71500);
        set_max_lasting(37599);
        set("dp", 275);
        set("pp", 175);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// 函数：获取描述
string get_desc()
{
        return "凤天战袍";
}
