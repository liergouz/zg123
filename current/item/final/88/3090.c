
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 3; }

// 函数：成品编号
int get_fin_type() { return 2065; }

// 函数：构造处理
void create()
{
        set_name("飞天战靴");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(90);
        set_value(7000);
        set_max_lasting(17899);
        set("ap", 0);
        set("dp", 31);
        set("cp", 0);
        set("pp", 0);
        set("sp", 39);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "飞天战靴";
}
