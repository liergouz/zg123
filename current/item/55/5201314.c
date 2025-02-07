
// 自动生成：/make/equip/60b

#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("你是美女吗？");
        set_picid_1(0051);
        set_picid_2(0051);

        set_level(0);
        set_value(40);
        set_max_lasting(2599);
        set("ap", 20);
        set("cp", 20);
        set("dp", 20);
        set("pp", 20);
        set("hp", 20);
        set("!%", 2000);
        set("?%", 2000);

        setup();

        set_gender(2);
        set_back_type(2);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "美女才能用的物品。";
}
