
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 5; }

// 函数：成品编号
int get_fin_type() { return 2273; }

// 函数：构造处理
void create()
{
        set_name("苍穹之冠");
        set_picid_1(6542);
        set_picid_2(6542);

        set_level(115);
        set_value(11500);
        set_max_lasting(27899);
        set("ap", 0);
        set("dp", 82);
        set("cp", 0);
        set("pp", 139);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "苍穹之冠";
}
