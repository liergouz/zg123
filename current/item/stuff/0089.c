
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 89; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// 函数：原料颜色
int get_item_color() { return 0; }

// 函数：构造处理
void create()
{
        set_name("红宝石");
        set_picid_1(8962);
        set_picid_2(8962);
        set_value(2000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "从装备分解出来的宝石，石刻、铁匠、机关、裁缝所需的材料";
}
