
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("丝绸衣");
        set_picid_1(6076);
        set_picid_2(6076);

        set_level(30);
        set_value(5000);
        set_max_lasting(10599);
        set("dp", 77);
        set("pp", 46);

        setup();

        set_gender(1);
        set_armor_code(2);
}

// 函数：获取描述
string get_desc()
{
        return "丝绸衣";
}
