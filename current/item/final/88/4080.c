
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 2044; }

// 函数：构造处理
void create()
{
        set_name("寒星靴");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(80);
        set_value(6500);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 23);
        set("cp", 0);
        set("pp", 0);
        set("sp", 46);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "寒星靴";
}
