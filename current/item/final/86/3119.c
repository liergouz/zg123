
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 3; }

// 函数：成品编号
int get_fin_type() { return 1441; }

// 函数：构造处理
void create()
{
        set_name("弑魂项链");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(119);
        set_value(20000);
        set_max_lasting(60099);
        set("ap", 151);
        set("dp", 0);
        set("cp", 0);
        set("pp", 113);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "弑魂项链";
}
