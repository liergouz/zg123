
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("紫蔓裙");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(25);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 66);
        set("pp", 39);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// 函数：获取描述
string get_desc()
{
        return "紫蔓裙";
}
