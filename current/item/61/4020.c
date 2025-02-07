
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("随风裙");
        set_picid_1(6134);
        set_picid_2(6134);

        set_level(20);
        set_value(2000);
        set_max_lasting(5499);
        set("dp", 48);
        set("pp", 25);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// 函数：获取描述
string get_desc()
{
        return "随风裙";
}
