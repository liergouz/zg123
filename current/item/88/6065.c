
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("飞玉鞋");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(65);
        set_value(16300);
        set_max_lasting(6799);
        set("dp", 15);
        set("sp", 25);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "飞玉鞋";
}
