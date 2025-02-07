
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("玉清素裙");
        set_picid_1(6138);
        set_picid_2(6138);

        set_level(60);
        set_value(28500);
        set_max_lasting(19599);
        set("dp", 143);
        set("pp", 88);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "玉清素裙";
}
