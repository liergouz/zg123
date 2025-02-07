
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("天水衣");
        set_picid_1(6076);
        set_picid_2(6076);

        set_level(30);
        set_value(6000);
        set_max_lasting(9099);
        set("dp", 67);
        set("pp", 39);

        setup();

        set_gender(1);
        set_armor_code(2);
}

// 函数：获取描述
string get_desc()
{
        return "天水衣";
}
