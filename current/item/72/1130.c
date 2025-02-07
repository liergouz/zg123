
#include <equip.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("龙斩");
        set_picid_1(7223);
        set_picid_2(7223);
        set_unit("口");

        set_level(130);
        set_value(57000);
        set_max_lasting(27599);
        set("ap", 258);
        set("!%", 25);
        set("spec.hp", 176);
        set("spec.hp*", 5);
        set("spec.mp*", 5);

        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return 23; }

// 函数：获取描述
string get_desc()
{
        return "“刀法”装备";
}
