
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("火龙项链");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(55);
        set_value(31000);
        set_max_lasting(7699);
        set("cp", 0);
        set("pp", 50);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "火龙项链";
}
