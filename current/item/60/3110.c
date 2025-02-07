
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("撼天铠甲");
        set_picid_1(6042);
        set_picid_2(6042);

        set_level(110);
        set_value(64500);
        set_max_lasting(34599);
        set("dp", 258);
        set("pp", 156);

        setup();

        set_gender(1);
        set_armor_code(8);
}

// 函数：获取描述
string get_desc()
{
        return "撼天铠甲";
}
