
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("踏云腰带");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(50);
        set_value(10000);
        set_max_lasting(9399);
        set("dp", 50);
        set("pp", 35);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "踏云腰带";
}
