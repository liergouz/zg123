
#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("玄天神甲");
        set_picid_1(6142);
        set_picid_2(6142);
        set_unit("件");

        set_level(130);
        set_value(80000);
        set_max_lasting(40599);
        set("dp", 242);
        set("pp", 108);
        set("spec.hp", 220);
        set("spec.mp", 60);
        set("spec.-*%", 15);

        setup();

        set_gender(2);
        set_armor_code(F_ZHANJIA);
        set_armor_color_1(0x73f0842e);
        set_armor_color_2(0x00004208);
}

// 函数：获取描述
string get_desc()
{
        return "玄天神甲";
}
