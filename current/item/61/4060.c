
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("金丝素裙");
        set_picid_1(6138);
        set_picid_2(6138);

        set_level(60);
        set_value(24000);
        set_max_lasting(20299);
        set("dp", 123);
        set("pp", 81);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "金丝素裙";
}
