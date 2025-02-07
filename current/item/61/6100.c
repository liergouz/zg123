
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("云龙战袍");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(100);
        set_value(62500);
        set_max_lasting(14499);
        set("dp", 131);
        set("pp", 247);

        setup();

        set_gender(2);
        set_armor_code(27);
}

// 函数：获取描述
string get_desc()
{
        return "云龙战袍";
}
