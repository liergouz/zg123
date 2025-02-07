
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("荧光披风");
        set_picid_1(6060);
        set_picid_2(6060);

        set_level(80);
        set_value(46500);
        set_max_lasting(12099);
        set("dp", 107);
        set("pp", 199);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// 函数：获取描述
string get_desc()
{
        return "荧光披风";
}
