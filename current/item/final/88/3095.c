
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 3; }

// 函数：成品编号
int get_fin_type() { return 2241; }

// 函数：构造处理
void create()
{
        set_name("跃兔靴");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 32);
        set("cp", 0);
        set("pp", 0);
        set("sp", 41);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "跃兔靴";
}
