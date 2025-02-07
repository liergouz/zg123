
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
//inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
//int get_item_type_2() { return ITEM_TYPE_2_PET; }

int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_item_number() {return 10001020 ;}
int get_item_color() {return 1 ;}

//宠物物品
int is_pet_item() { return 1;}
// 函数：构造处理
void create()
{
        set_name("玉灵液");
        set_picid_1(9991);
        set_picid_2(9991);
        set_unit("个");
        set_value(1000);
        set_amount(1);
}


// 函数：获取描述
string get_desc() 
{
	string desc;
	return desc = "对宠物使用的一种神水，能将宠物转换成０级初始状态。";
}