#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name( "遗产的宝箱" );
        set_picid_1(0080);
        set_picid_2(0080);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。丁鹤年祖父的遗产，内有藏宝山洞指示图。"; 
}