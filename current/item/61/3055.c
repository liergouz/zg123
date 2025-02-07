
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("飞豹素裙");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(24500);
        set_max_lasting(18099);
        set("dp", 137);
        set("pp", 79);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "飞豹素裙";
}
