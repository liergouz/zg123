
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("紫蔓鞋");
        set_picid_1(8803);
        set_picid_2(8803);

        set_level(25);
        set_value(2500);
        set_max_lasting(6299);
        set("dp", 13);
        set("sp", 9);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "紫蔓鞋";
}
