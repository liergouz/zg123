
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("古甲腰带");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(20);
        set_value(4500);
        set_max_lasting(5299);
        set("dp", 8);
        set("pp", 22);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "古甲腰带";
}
