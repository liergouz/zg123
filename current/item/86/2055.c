
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("幽灵项链");
        set_picid_1(8607);
        set_picid_2(8607);

        set_level(55);
        set_value(31000);
        set_max_lasting(7699);
        set("cp", 0);
        set("pp", 60);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "幽灵项链";
}
