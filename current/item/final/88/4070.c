
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 2025; }

// 函数：构造处理
void create()
{
        set_name("天威靴");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(70);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 21);
        set("cp", 0);
        set("pp", 0);
        set("sp", 42);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "天威靴";
}
