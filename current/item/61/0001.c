
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("女装布衣");
        set_picid_1(6123);
        set_picid_2(6123);

        set_level(0);
        set_value(80);
        set_max_lasting(2599);
        set("dp", 10);
        set("pp", 0);

        setup();

        set_gender(2);
        set_armor_code(20);
}

// 函数：获取描述
string get_desc()
{
        return "女装布衣";
}
