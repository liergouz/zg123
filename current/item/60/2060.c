
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("踏青袍");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(60);
        set_value(28500);
        set_max_lasting(19599);
        set("dp", 143);
        set("pp", 91);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// 函数：获取描述
string get_desc()
{
        return "踏青袍";
}
