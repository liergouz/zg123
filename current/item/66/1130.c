
#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("玄天战盔");
        set_picid_1(6642);
        set_picid_2(6642);
        set_unit("顶");

        set_level(130);
        set_value(40000);
        set_max_lasting(18699);
        set("dp", 74);
        set("pp", 45);
        set("spec.hp", 60);
        set("spec.mp", 35);
        set("spec.??%", 30);
        set("spec.-*%", 13);
        set("spec.-c*%", 7);

        setup();

        set_gender(2);
        set_head_code(F_ZHANKUI);
        set_head_color(0x3a082965);
}

// 函数：获取描述
string get_desc()
{
        return "玄天战盔";
}
