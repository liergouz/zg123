
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("镶铁裙");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(25);
        set_value(3500);
        set_max_lasting(5499);
        set("dp", 46);
        set("pp", 70);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// 函数：获取描述
string get_desc()
{
        return "镶铁裙";
}
