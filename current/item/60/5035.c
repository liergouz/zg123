
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("地坤衣");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(35);
        set_value(10500);
        set_max_lasting(6699);
        set("dp", 55);
        set("pp", 91);

        setup();

        set_gender(1);
        set_armor_code(2);
}

// 函数：获取描述
string get_desc()
{
        return "地坤衣";
}
