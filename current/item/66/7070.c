
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("倾露巾帽");
        set_picid_1(6654);
        set_picid_2(6654);

        set_level(70);
        set_value(29000);
        set_max_lasting(7899);
        set("dp", 49);
        set("pp", 77);

        setup();

        set_gender(2);
        set_head_code(55);
}

// 函数：获取描述
string get_desc()
{
        return "倾露巾帽";
}
