
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：成品编号
int get_fin_type() { return 2118; }

// 函数：构造处理
void create()
{
        set_name("锁链护心甲");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(45);
        set_value(7500);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 115);
        set("cp", 0);
        set("pp", 73);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "锁链护心甲";
}
