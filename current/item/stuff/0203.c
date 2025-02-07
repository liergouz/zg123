
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 1; }

// 函数：原料类型
int get_stuff_type() { return 203; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// 函数：镶嵌识别
int get_item_type() { return ITEM_TYPE_SHIKE; }

// 函数：成品类型
int get_fin_type() { return 1614; }

// 函数：原料颜色
int get_item_color() { return 0; }
 
// 函数：构造处理
void create()
{
        set_name("瞄准构件");
        set_picid_1(4173);
        set_picid_2(4173);
        set_value(1500);
        set("double2", 100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "装置在武器上，提高1%爆击率";
}
