
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 6; }

// 函数：成品编号
int get_fin_type() { return 1348; }

// 函数：构造处理
void create()
{
        set_name("炎阳项链");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(50);
        set_value(20000);
        set_max_lasting(8099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 105);
        set("pp", 68);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "炎阳项链";
}
