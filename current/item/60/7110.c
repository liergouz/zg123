
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("炎鳞战衣");
        set_picid_1(6042);
        set_picid_2(6042);

        set_level(110);
        set_value(70500);
        set_max_lasting(15699);
        set("dp", 148);
        set("pp", 274);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// 函数：获取描述
string get_desc()
{
        return "炎鳞战衣";
}
