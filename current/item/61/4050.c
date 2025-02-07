
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("赶日素裙");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(50);
        set_value(18000);
        set_max_lasting(16599);
        set("dp", 104);
        set("pp", 67);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// 函数：获取描述
string get_desc()
{
        return "赶日素裙";
}
