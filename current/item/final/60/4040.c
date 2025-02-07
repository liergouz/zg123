
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 1244; }

// 函数：构造处理
void create()
{
        set_name("鲤鱼行装");
        set_picid_1(6003);
        set_picid_2(6003);

        set_level(40);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 110);
        set("cp", 0);
        set("pp", 75);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "鲤鱼行装";
}
