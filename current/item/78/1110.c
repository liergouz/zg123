
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("幽魂");
        set_picid_1(7619);
        set_picid_2(7619);

        set_level(110);
        set_value(60000);
        set_max_lasting(9599);
        set("ap", 220);
        set("dp", 0);
        set("cp", 345);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_13; }

// 函数：获取描述
string get_desc()
{
        return "“剑法”装备";
}
