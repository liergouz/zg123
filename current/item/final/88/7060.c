
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 7; }

// 函数：成品编号
int get_fin_type() { return 1298; }

// 函数：构造处理
void create()
{
        set_name("彻云鞋");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(60);
        set_value(5000);
        set_max_lasting(13899);
        set("ap", 0);
        set("dp", 26);
        set("cp", 0);
        set("pp", 0);
        set("sp", 30);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "彻云鞋";
}
