
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("神行巾帽");
        set_picid_1(6625);
        set_picid_2(6625);

        set_level(55);
        set_value(13700);
        set_max_lasting(9699);
        set("dp", 66);
        set("pp", 36);

        setup();

        set_gender(2);
        set_head_code(54);
}

// 函数：获取描述
string get_desc()
{
        return "神行巾帽";
}
