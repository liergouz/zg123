
#include <equip.h>

inherit HEAD;

// 函数：构造处理
void create()
{
        set_name("布帽");
        set_picid_1(6610);
        set_picid_2(6610);
        set_unit("顶");

        set_level(0);
        set_value(950);
        set_max_lasting(2499);
        set("dp", 5);
        set("pp", 5);
        set("hp", 5);
        set("mp", 5);

        setup();

        set_gender(2);
        set_head_code(F_PINGMAO);
        set_head_color(0x4208716a);
}

// 函数：获取描述
string get_desc()
{
        return "布帽";
}
