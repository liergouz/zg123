
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("衾天腰带");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(120);
        set_value(39500);
        set_max_lasting(8299);
        set("dp", 107);
        set("pp", 120);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "衾天腰带";
}
