
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1412; }

// 函数：构造处理
void create()
{
        set_name("戮魂项链");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(100);
        set_value(20000);
        set_max_lasting(40099);
        set("ap", 125);
        set("dp", 0);
        set("cp", 0);
        set("pp", 104);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "戮魂项链";
}
