
// 自动生成：/make/weapon/make73b

#include <equip.h>

inherit WEAPON;

// 函数：构造处理
void create()
{
        set_name("%s");
        set_picid_1(%04d);
        set_picid_2(%04d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap", %d);
        set("!%%", %d);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return %d; }

// 函数：获取描述
string get_desc()
{
        return "“剑法”装备";
}
