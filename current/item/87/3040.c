
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("破敌腰带");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(40);
        set_value(7500);
        set_max_lasting(8499);
        set("dp", 38);
        set("pp", 25);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "破敌腰带";
}
