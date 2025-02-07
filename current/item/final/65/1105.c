
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 2250; }

// 函数：构造处理
void create()
{
        set_name("亡魂之盔");
        set_picid_1(6582);
        set_picid_2(6582);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 205);
        set("cp", 0);
        set("pp", 64);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "亡魂之盔";
}
