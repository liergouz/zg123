
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 8; }

// 函数：成品编号
int get_fin_type() { return 2357; }

// 函数：构造处理
void create()
{
        set_name("神威圣袍");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(86);
        set_value(1000);
        set_max_lasting(19899);
        set("ap", 0);
        set("dp", 130);
        set("cp", 0);
        set("pp", 227);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "神威圣袍";
}
