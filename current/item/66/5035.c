
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("地坤头巾");
        set_picid_1(6603);
        set_picid_2(6603);

        set_level(35);
        set_value(9700);
        set_max_lasting(5799);
        set("dp", 29);
        set("pp", 42);

        setup();

        set_gender(2);
        set_head_code(52);
}

// 函数：获取描述
string get_desc()
{
        return "地坤头巾";
}
