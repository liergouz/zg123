
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("飞天腰带");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(90);
        set_value(20000);
        set_max_lasting(12999);
        set("dp", 88);
        set("pp", 75);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "飞天腰带";
}
