
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 5; }

// 函数：成品编号
int get_fin_type() { return 2315; }

// 函数：构造处理
void create()
{
        set_name("龙骨冠");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(119);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 88);
        set("cp", 0);
        set("pp", 150);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "龙骨冠";
}
