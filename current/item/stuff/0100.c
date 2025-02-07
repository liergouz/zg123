
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 1; }

// 函数：原料类型
int get_stuff_type() { return 100; }

int get_rate_2() { return 40; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_DIAMOND; }

// 函数：原料颜色
int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("完美补天石");
        set_picid_1(8973);
        set_picid_2(8973);
        set_value(1000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "增加制造物品数值提升几率的道具，增加40%的成功率";
}
