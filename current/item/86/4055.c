
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("凤凰珠链");
        set_picid_1(8603);
        set_picid_2(8603);

        set_level(55);
        set_value(34400);
        set_max_lasting(6499);
        set("cp", 0);
        set("pp", 57);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "凤凰珠链";
}
