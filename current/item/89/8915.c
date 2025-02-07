
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_2; }

// 函数：宝石属性
string get_diamond_type() { return "-*%"; }

// 函数：构造处理
void create()
{
        set_name("残缺蓝晶石");
        set_picid_1(8915);
        set_picid_2(8915);
        set_unit("块");
        set_value(20000);
        set_bonus_value(8000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "［宝石合成材料］减少伤害百分比"; 
}

// 函数：生成宝石文件
string get_diamond_file()
{
        return __DIR__ "8965";
}
