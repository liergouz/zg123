
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit USABLE;

// 函数：图纸序号
int get_product_type() { return 491; }

// 函数：图纸要求技能
int get_product_skill() { return 640; }

// 函数：图纸要求类别
int get_product_sort() { return 0; }

// 函数：图纸要求等级
int get_product_level() { return 110; }

// 函数：图纸要求熟练度
int get_product_exp() { return 117; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("衾天战袍图纸");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(500);
}

// 函数：获取描述
string get_desc()
{
        return "学习制造衾天战袍";
}

string get_product()
{
	return "/item/final/60/7120";
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
