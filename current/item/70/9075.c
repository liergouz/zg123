
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("英杰拳刃");
        set_picid_1(6833);
        set_picid_2(6833);

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

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "“拳法”装备";
}

//
string get_tail_desc()
{
	return "“历代英杰所流传至今之武器”\n当你在被攻击后有一定\n的几率给予自己一个灵气甲";	
}