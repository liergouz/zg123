
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("碧火寒月环");
        set_picid_1(7813);
        set_picid_2(7813);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 305);
        set("dp+", 20);
        set("pp+", 50);
        set("!%+", 100);
        set("?%+", 100);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(THROWING);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“暗器”装备";
}

//
string get_tail_desc()
{
	return "“暗杀者至宝，杀人于无形”\n使你用毒的总共伤害提高100点";	
}