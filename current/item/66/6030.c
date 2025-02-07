
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("青龙头巾");
        set_picid_1(6620);
        set_picid_2(6620);

        set_level(30);
        set_value(7000);
        set_max_lasting(5499);
        set("dp", 23);
        set("pp", 36);

        setup();

        set_gender(2);
        set_head_code(52);
}

// 函数：获取描述
string get_desc()
{
        return "青龙头巾";
}
