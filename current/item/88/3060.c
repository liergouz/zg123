
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("战将鞋");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(60);
        set_value(12200);
        set_max_lasting(8899);
        set("dp", 29);
        set("sp", 28);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "战将鞋";
}
