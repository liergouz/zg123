
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("混天战帽");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(70);
        set_value(22500);
        set_max_lasting(12699);
        set("dp", 92);
        set("pp", 40);

        setup();

        set_gender(1);
        set_head_code(45);
}

// 函数：获取描述
string get_desc()
{
        return "混天战帽";
}
