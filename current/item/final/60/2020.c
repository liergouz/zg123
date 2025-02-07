
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：成品编号
int get_fin_type() { return 1203; }

// 函数：构造处理
void create()
{
        set_name("青柳行装");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(20);
        set_value(1000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 70);
        set("cp", 0);
        set("pp", 45);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "青柳行装";
}
