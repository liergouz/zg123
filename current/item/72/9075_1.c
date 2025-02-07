
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("御姐的爱好");
        set_picid_1(7223);
        set_picid_2(7223);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 640);
        set("hp+", 100);
        set("!%+", 200);
        set("?%+", 200);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“刀法”装备";
}

//
string get_tail_desc()
{
	return "“御姐的爱好”\n攻击目标时有一定的几率\n对目标产生300点的吃嫩草的伤害";		
}