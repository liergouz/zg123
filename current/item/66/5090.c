
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("斥云巾帽");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(90);
        set_value(40000);
        set_max_lasting(9099);
        set("dp", 62);
        set("pp", 102);

        setup();

        set_gender(2);
        set_head_code(56);
}

// 函数：获取描述
string get_desc()
{
        return "斥云巾帽";
}
