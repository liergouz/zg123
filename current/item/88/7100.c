
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("炽纹履");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(100);
        set_value(28500);
        set_max_lasting(8299);
        set("dp", 22);
        set("sp", 39);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "炽纹履";
}
