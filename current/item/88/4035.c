
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("水青鞋");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(35);
        set_value(4700);
        set_max_lasting(6499);
        set("dp", 9);
        set("sp", 28);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "水青鞋";
}
