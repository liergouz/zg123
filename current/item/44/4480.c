
#include <item.h>
#include <ansi.h>
inherit ITEM;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
//int get_item_type_2() { return ITEM_TYPE_2_PET; }
//宠物物品
int is_pet_item() { return 1;}
// 函数：构造处理
void create()
{
        set_name("吸魂珠");
        set_picid_1(9125);
        set_picid_2(9125);
        set_value(1000);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}

string get_desc() 
{
	string desc;
	return desc = "宠物精炼的配方，可以提炼出宠物的一种技能。";
}