
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("翻云巾帽");
        set_picid_1(6638);
        set_picid_2(6638);

        set_level(80);
        set_value(26000);
        set_max_lasting(13899);
        set("dp", 93);
        set("pp", 54);

        setup();

        set_gender(2);
        set_head_code(56);
}

// 函数：获取描述
string get_desc()
{
        return "翻云巾帽";
}
