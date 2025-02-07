
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("萝莉的温柔");
        set_picid_1(7023);
        set_picid_2(7023);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 610);
        set("dp+", 40);
        set("pp+", 100);
        set("!%+", 200);
        set("?%+", 200);
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
	return "“萝莉的温柔所产生的武器”\n当谁被温柔攻击之后有一定\n的几率给予他人一个爱的护盾";	
}