
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
        set_name("乾坤无极棍");
        set_picid_1(6850);
        set_picid_2(6850);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 327);
        set("dp+", 20);
        set("hp+", 50);
        set("double", 100);
        set("?%+", 100);
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
	return "“墨家至宝，挥舞起来可以扭转乾坤”\n在攻击目标的同时有一定几率\n使被攻击目标产生2秒眩晕";		
}