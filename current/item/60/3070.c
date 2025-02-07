
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("混天披风");
        set_picid_1(6080);
        set_picid_2(6080);

        set_level(70);
        set_value(36500);
        set_max_lasting(22599);
        set("dp", 170);
        set("pp", 100);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// 函数：获取描述
string get_desc()
{
        return "混天披风";
}
