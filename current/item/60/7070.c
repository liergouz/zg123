
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("倾露披风");
        set_picid_1(6080);
        set_picid_2(6080);

        set_level(70);
        set_value(38500);
        set_max_lasting(10899);
        set("dp", 100);
        set("pp", 178);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// 函数：获取描述
string get_desc()
{
        return "倾露披风";
}
