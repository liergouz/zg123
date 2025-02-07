
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 9; }

// 函数：构造处理
void create()
{
        set_name("女人们的愤怒");
        set_picid_1(7323);
        set_picid_2(7323);

        set_level(120);
        set_value(57000);
        set_max_lasting(27599);
        set("ap+", 380);
        set("cp+", 760);
        set("dp+", 50);
        set("hp+", 100);
        set("double", 200);
        set("?%+", 200);
	set_item_color(3);	//紫色
        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "“剑法”装备";
}

//
string get_tail_desc()
{
	return "“女人们的愤怒”\n增加对坏男人们所造成的相爱效果\n和撒娇效果，最多300点";		
}