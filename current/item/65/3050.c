
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("战天冠");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(50);
        set_value(12000);
        set_max_lasting(9099);
        set("dp", 68);
        set("pp", 28);

        setup();

        set_gender(1);
        set_head_code(43);
}

// 函数：获取描述
string get_desc()
{
        return "战天冠";
}
