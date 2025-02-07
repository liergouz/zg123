
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("垂云披风");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(60);
        set_value(30500);
        set_max_lasting(9699);
        set("dp", 83);
        set("pp", 151);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "垂云披风";
}
