
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("羽冠");
        set_picid_1(6538);
        set_picid_2(6538);

        set_level(15);
        set_value(2400);
        set_max_lasting(4899);
        set("dp", 14);
        set("pp", 0);

        setup();

        set_gender(1);
        set_head_code(41);
}

// 函数：获取描述
string get_desc()
{
        return "羽冠";
}
