
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("衾天战袍");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(120);
        set_value(78500);
        set_max_lasting(16899);
        set("dp", 157);
        set("pp", 295);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// 函数：获取描述
string get_desc()
{
        return "衾天战袍";
}
