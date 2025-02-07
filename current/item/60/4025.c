
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("青云衣");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3000);
        set_max_lasting(7299);
        set("dp", 58);
        set("pp", 32);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// 函数：获取描述
string get_desc()
{
        return "青云衣";
}
