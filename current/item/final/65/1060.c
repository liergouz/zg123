
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1291; }

// 函数：构造处理
void create()
{
        set_name("玉清盔");
        set_picid_1(6642);
        set_picid_2(6642);

        set_level(60);
        set_value(5000);
        set_max_lasting(13899);
        set("ap", 0);
        set("dp", 115);
        set("cp", 0);
        set("pp", 41);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "玉清盔";
}
