
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：成品编号
int get_fin_type() { return 2161; }

// 函数：构造处理
void create()
{
        set_name("天狼行装");
        set_picid_1(6058);
        set_picid_2(6058);

        set_level(65);
        set_value(8500);
        set_max_lasting(21899);
        set("ap", 0);
        set("dp", 161);
        set("cp", 0);
        set("pp", 92);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "天狼行装";
}
