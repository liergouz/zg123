
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("幽明项链");
        set_picid_1(8613);
        set_picid_2(8613);

        set_level(80);
        set_value(48500);
        set_max_lasting(8499);
        set("cp", 0);
        set("pp", 75);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "幽明项链";
}
