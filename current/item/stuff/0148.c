
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 148; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// 函数：原料颜色
int get_item_color() { return 0; }

// 函数：构造处理
void create()
{
        set_name("南瓜");
        set_picid_1(3211);
        set_picid_2(3211);
        set_value(20);
        set_amount(1);
        set("plant", 50);
        set("pvalue", 200);
}

// 函数：获取描述
string get_desc() 
{ 
        return "酒食生活技能所需材料";
}
