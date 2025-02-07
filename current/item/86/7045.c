
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("齐鸣项链");
        set_picid_1(8657);
        set_picid_2(8657);

        set_level(45);
        set_value(30500);
        set_max_lasting(5199);
        set("cp", 80);
        set("pp", 55);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "齐鸣项链";
}
