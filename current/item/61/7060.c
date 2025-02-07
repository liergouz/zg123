
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("彻云素裙");
        set_picid_1(6138);
        set_picid_2(6138);

        set_level(60);
        set_value(30500);
        set_max_lasting(9699);
        set("dp", 88);
        set("pp", 154);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "彻云素裙";
}
