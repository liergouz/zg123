
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("金环刀");
        set_picid_1(7221);
        set_picid_2(7221);

        set_level(50);
        set_value(17000);
        set_max_lasting(16099);
        set("ap", 120);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_06; }

// 函数：获取描述
string get_desc()
{
        return "“刀法”装备";
}
