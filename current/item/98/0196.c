#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;


// 函数：构造处理
void create()
{
        set_name( "号角" );
        set_picid_1(100);
        set_picid_2(100);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。唯一一种能加工成王之号角的普通号角，用金色牛角制成。"; 
}