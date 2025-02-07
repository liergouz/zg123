
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
        set_name("人妻的情花");
        set_picid_1(7123);
        set_picid_2(7123);

        set_level(120);
        set_value(33000);
        set_max_lasting(36099);
        set("ap+", 610);
        set("dp+", 40);
        set("pp+", 100);
        set("!%+", 200);
        set("?%+", 200);
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
	return "“人妻的情花毒，杀人于无形”\n使你用情花毒的总共伤害几率提高";	
}