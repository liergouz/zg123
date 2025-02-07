
#include <equip.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 8; }

// 函数：构造处理
void create()
{
        set_name("石雕拳刃");
        set_picid_1(6822);
        set_picid_2(6822);

        set_level(75);
        set_value(4000);
        set_max_lasting(1099);
        set("ap+", 10);
	set_item_color(3);	//紫色
        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“拳法”装备";
}

//
string get_tail_desc()
{
	return "神秘的拳刃，似乎藏有某些秘密";		
}