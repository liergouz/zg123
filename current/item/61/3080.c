
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("云龙彩衣");
        set_picid_1(6160);
        set_picid_2(6160);

        set_level(80);
        set_value(43500);
        set_max_lasting(25599);
        set("dp", 192);
        set("pp", 114);

        setup();

        set_gender(2);
        set_armor_code(26);
}

// 函数：获取描述
string get_desc()
{
        return "云龙彩衣";
}
