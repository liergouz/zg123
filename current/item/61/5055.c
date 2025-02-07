
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("杏风素裙");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(26500);
        set_max_lasting(9099);
        set("dp", 79);
        set("pp", 139);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "杏风素裙";
}
