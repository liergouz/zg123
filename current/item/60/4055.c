
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("玄魔袍");
        set_picid_1(6078);
        set_picid_2(6078);

        set_level(55);
        set_value(21000);
        set_max_lasting(18399);
        set("dp", 114);
        set("pp", 74);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// 函数：获取描述
string get_desc()
{
        return "玄魔袍";
}
