
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("女王的蜡烛");
        set_picid_1(7423);
        set_picid_2(7423);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 656);
        set("dp+", 40);
        set("hp+", 100);
        set("!%+", 200);
        set("?%+", 200);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(SPEAR);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“枪法”装备";
}

//
string get_tail_desc()
{
	return "“女王所用的恐怖凶器，全身热如炽焰”\n攻击男人时有一定几率\n给目标产生燃烧效果";		
}