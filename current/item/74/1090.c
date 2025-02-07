
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("金环枪");
        set_picid_1(7417);
        set_picid_2(7417);

        set_level(90);
        set_value(37000);
        set_max_lasting(21599);
        set("ap", 207);
        set("dp", 0);
        set("cp", 0);
        set("sp", -38);

        setup();

        set_weapon_type(SPEAR);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_11; }

// 函数：获取描述
string get_desc()
{
        return "“枪法”装备";
}
