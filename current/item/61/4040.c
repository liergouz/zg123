
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("鲤鱼裙");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(40);
        set_value(12000);
        set_max_lasting(12799);
        set("dp", 86);
        set("pp", 53);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// 函数：获取描述
string get_desc()
{
        return "鲤鱼裙";
}
