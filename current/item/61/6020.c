
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("细麻裙");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(20);
        set_value(2500);
        set_max_lasting(4899);
        set("dp", 35);
        set("pp", 55);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// 函数：获取描述
string get_desc()
{
        return "细麻裙";
}
