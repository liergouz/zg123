
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 229; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// 函数：原料颜色
int get_item_color() { return 0; }

// 函数：构造处理
void create()
{
        set_name("桃子");
        set_picid_1(3285);
        set_picid_2(3285);
        set_value(1050);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "猴子们的最爱，20秒内恢复玩家1000点气血值。";
}
