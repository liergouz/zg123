
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit USABLE;

// 函数：图纸序号
int get_product_type() { return 31; }

// 函数：图纸要求技能
int get_product_skill() { return 620; }

// 函数：图纸要求类别
int get_product_sort() { return 5; }

// 函数：图纸要求等级
int get_product_level() { return 44; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }

int get_item_color() { return 0; }

// 函数：构造处理
void create()
{
        set_name("将军棍图纸");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(200);
}

// 函数：获取描述
string get_desc()
{
        return "学习制作将军棍。";
}

string get_product()
{
	return "/item/final/75/1040";
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
