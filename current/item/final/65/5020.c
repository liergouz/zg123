
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 5; }

// 函数：成品编号
int get_fin_type() { return 1209; }

// 函数：构造处理
void create()
{
        set_name("古藤冠");
        set_picid_1(6678);
        set_picid_2(6678);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 25);
        set("cp", 0);
        set("pp", 35);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "古藤冠";
}
