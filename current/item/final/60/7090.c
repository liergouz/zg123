
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 7; }

// 函数：成品编号
int get_fin_type() { return 2053; }

// 函数：构造处理
void create()
{
        set_name("冥光袍");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(90);
        set_value(6500);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 149);
        set("cp", 0);
        set("pp", 239);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "冥光袍";
}
