
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("飞云履");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(65);
        set_value(13800);
        set_max_lasting(9299);
        set("dp", 31);
        set("sp", 33);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "飞云履";
}
