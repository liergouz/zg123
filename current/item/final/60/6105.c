
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：成品编号
int get_fin_type() { return 2249; }

// 函数：构造处理
void create()
{
        set_name("潮汐法袍");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 166);
        set("cp", 0);
        set("pp", 272);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "潮汐法袍";
}
