
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 6; }

// 函数：成品编号
int get_fin_type() { return 1248; }

// 函数：构造处理
void create()
{
        set_name("宣明袍");
        set_picid_1(6015);
        set_picid_2(6015);

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 70);
        set("cp", 0);
        set("pp", 110);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "宣明袍";
}
