
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 1105; }

// 函数：构造处理
void create()
{
        set_name("飞蝗石");
        set_picid_1(7116);
        set_picid_2(7116);

        set_level(35);
        set_value(3500);
        set_max_lasting(3599);
        set("ap", 82);
        set("dp", -4);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_04; }

// 函数：获取描述
string get_desc()
{
        return "“暗器”装备";
}
