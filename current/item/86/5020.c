
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("铁项链");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(20);
        set_value(8000);
        set_max_lasting(4899);
        set("cp", 28);
        set("pp", 26);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "铁项链";
}
