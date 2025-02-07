
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("天乾战衣");
        set_picid_1(6062);
        set_picid_2(6062);

        set_level(120);
        set_value(78500);
        set_max_lasting(16899);
        set("dp", 160);
        set("pp", 298);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// 函数：获取描述
string get_desc()
{
        return "天乾战衣";
}
