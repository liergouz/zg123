
#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("玄女战盔");
        set_picid_1(6682);
        set_picid_2(6682);
        set_unit("顶");

        set_level(130);
        set_value(62000);
        set_max_lasting(11499);
        set("dp", 52);
        set("pp", 130);
        set("spec.hp", 55);
        set("spec.mp", 70);
        set("spec.??%", 40);
        set("spec.-*%", 7);
        set("spec.-c*%", 7);

        setup();

        set_gender(2);
        set_head_code(F_ZHANKUI);
        set_head_color(0x39e119a8);
}

// 函数：获取描述
string get_desc()
{
        return "玄女战盔";
}
