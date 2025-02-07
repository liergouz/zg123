
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("照世素裙");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(26500);
        set_max_lasting(9099);
        set("dp", 82);
        set("pp", 142);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "照世素裙";
}
