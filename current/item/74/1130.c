
#include <equip.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("开天");
        set_picid_1(7423);
        set_picid_2(7423);
        set_unit("杆");

        set_level(130);
        set_value(57000);
        set_max_lasting(27599);
        set("ap", 286);
        set("!%", 20);
        set("spec.hp", 110);
        set("spec.hp*", 6);
        set("spec.mp*", 6);

        setup();

        set_weapon_type(SPEAR);
}

// 函数：获取武器级别
int get_weapon_level() { return 23; }

// 函数：获取描述
string get_desc()
{
        return "“枪法”装备";
}
