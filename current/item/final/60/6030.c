
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：成品编号
int get_fin_type() { return 1226; }

// 函数：构造处理
void create()
{
        set_name("青龙袍");
        set_picid_1(6078);
        set_picid_2(6078);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 55);
        set("cp", 0);
        set("pp", 95);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "青龙袍";
}
