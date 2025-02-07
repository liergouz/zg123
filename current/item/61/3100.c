
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("霸王战袍");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(100);
        set_value(57500);
        set_max_lasting(31599);
        set("dp", 236);
        set("pp", 142);

        setup();

        set_gender(2);
        set_armor_code(27);
}

// 函数：获取描述
string get_desc()
{
        return "霸王战袍";
}
