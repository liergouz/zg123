
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 7; }

// 函数：成品编号
int get_fin_type() { return 1214; }

// 函数：构造处理
void create()
{
        set_name("古甲鞋");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 9);
        set("cp", 0);
        set("pp", 0);
        set("sp", 11);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "古甲鞋";
}
