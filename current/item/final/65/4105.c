
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 2256; }

// 函数：构造处理
void create()
{
        set_name("流云头巾");
        set_picid_1(6556);
        set_picid_2(6556);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 185);
        set("cp", 0);
        set("pp", 67);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "流云头巾";
}
