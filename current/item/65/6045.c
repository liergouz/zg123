
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("虎头帽");
        set_picid_1(6576);
        set_picid_2(6576);

        set_level(45);
        set_value(15300);
        set_max_lasting(6399);
        set("dp", 32);
        set("pp", 53);

        setup();

        set_gender(1);
        set_head_code(43);
}

// 函数：获取描述
string get_desc()
{
        return "虎头帽";
}
