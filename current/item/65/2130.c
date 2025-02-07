
#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("天魔战盔");
        set_picid_1(6562);
        set_picid_2(6562);
        set_unit("顶");

        set_level(130);
        set_value(36000);
        set_max_lasting(12099);
        set("dp", 65);
        set("pp", 90);
        set("spec.hp", 60);
        set("spec.mp", 48);
        set("spec.??%", 30);
        set("spec.-*%", 9);
        set("spec.-c*%", 7);

        setup();

        set_gender(1);
        set_head_code(M_ZHANKUI);
        set_head_color(0x49e37a80);
}

// 函数：获取描述
string get_desc()
{
        return "天魔战盔";
}
