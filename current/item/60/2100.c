
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("破云战衣");
        set_picid_1(6082);
        set_picid_2(6082);

        set_level(100);
        set_value(57500);
        set_max_lasting(31599);
        set("dp", 231);
        set("pp", 147);

        setup();

        set_gender(1);
        set_armor_code(7);
}

// 函数：获取描述
string get_desc()
{
        return "破云战衣";
}
