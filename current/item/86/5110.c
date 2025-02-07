
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("真魂项链");
        set_picid_1(8611);
        set_picid_2(8611);

        set_level(110);
        set_value(89000);
        set_max_lasting(6199);
        set("cp", 208);
        set("pp", 116);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "真魂项链";
}
