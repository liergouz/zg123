
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("青铜项链");
        set_picid_1(8604);
        set_picid_2(8604);

        set_level(15);
        set_value(3000);
        set_max_lasting(6499);
        set("cp", 0);
        set("pp", 20);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "青铜项链";
}
