
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
        set_name("真君炽焰枪");
        set_picid_1(6892);
        set_picid_2(6892);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 328);
        set("dp+", 20);
        set("hp+", 50);
        set("!%+", 100);
        set("?%+", 100);
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
	return "“二郎真君之神兵，枪身热如炽焰”\n攻击目标时有一定几率\n给目标产生破甲效果";		
}