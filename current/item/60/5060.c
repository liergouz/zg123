
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("翠玉袍");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(60);
        set_value(30500);
        set_max_lasting(9699);
        set("dp", 85);
        set("pp", 151);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// 函数：获取描述
string get_desc()
{
        return "翠玉袍";
}
