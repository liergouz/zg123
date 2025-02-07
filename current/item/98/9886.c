#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;
int is_huoyanshi() { return 1;}

// 函数：构造处理
void create()
{
        set_name( "火焰石" );
        set_picid_1(8904);
        set_picid_2(8904);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);
        set_amount(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。红色的像火焰的小石头。"; 
}