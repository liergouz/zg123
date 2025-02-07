
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
        set_name("女王的闷棍");
        set_picid_1(7523);
        set_picid_2(7523);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 454);
        set("dp+", 40);
        set("hp+", 100);
        set("double", 200);
        set("?%+", 200);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(STICK);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“棍法”装备";
}

//
string get_tail_desc()
{
	return "“女王的看家法宝，挥舞起来可以让目标偏体鳞伤”\n在攻击目标的同时有一定几率\n使被攻击目标产生恐惧感";		
}