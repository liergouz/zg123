
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("传风冠");
        set_picid_1(6574);
        set_picid_2(6574);

        set_level(30);
        set_value(7000);
        set_max_lasting(5499);
        set("dp", 25);
        set("pp", 37);

        setup();

        set_gender(1);
        set_head_code(42);
}

// 函数：获取描述
string get_desc()
{
        return "传风冠";
}
