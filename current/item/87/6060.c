
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("垂云腰带");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(60);
        set_value(18500);
        set_max_lasting(6499);
        set("dp", 45);
        set("pp", 60);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "垂云腰带";
}
