
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：成品编号
int get_fin_type() { return 2308; }

// 函数：构造处理
void create()
{
        set_name("龙骨战衣");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(119);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 281);
        set("cp", 0);
        set("pp", 182);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "龙骨战衣";
}
