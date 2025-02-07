
#include <equip.h>

inherit HEAD;

// 函数：构造处理
void create()
{
        set_name("棉布帽");
        set_picid_1(6500);
        set_picid_2(6500);
        set_unit("顶");

        set_level(20);
        set_value(1800);
        set_max_lasting(4299);
        set("dp", 11);
        set("pp", 11);
        set("hp", 15);
        set("mp", 15);

        setup();

        set_gender(1);
        set_head_code(M_ZHANMAO);
        set_head_color(0x42084208);
}

// 函数：获取描述
string get_desc()
{
        return "棉布帽";
}
