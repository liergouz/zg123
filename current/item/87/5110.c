
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("斩风腰带");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(110);
        set_value(36000);
        set_max_lasting(7999);
        set("dp", 97);
        set("pp", 110);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "斩风腰带";
}
