
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit USABLE;

// 函数：图纸序号
int get_product_type() { return 517; }

// 函数：图纸要求技能
int get_product_skill() { return 650; }

// 函数：图纸要求类别
int get_product_sort() { return 2; }

// 函数：图纸要求等级
int get_product_level() { return 45; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("水纹项链图纸");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(200);
}

// 函数：获取描述
string get_desc()
{
        return "学习制作水纹项链。";
}

string get_product()
{
	return "/item/final/86/4045";
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
