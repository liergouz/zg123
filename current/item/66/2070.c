
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("狂龙巾帽");
        set_picid_1(6654);
        set_picid_2(6654);

        set_level(70);
        set_value(22500);
        set_max_lasting(12699);
        set("dp", 82);
        set("pp", 48);

        setup();

        set_gender(2);
        set_head_code(55);
}

// 函数：获取描述
string get_desc()
{
        return "狂龙巾帽";
}
