#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;


// 函数：构造处理
void create()
{
        set_name( "石炭" );
        set_picid_1(8913);
        set_picid_2(8913);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。王铁匠需要收集的一种炭。"; 
}