#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name( "修好的小木桶" );
        set_picid_1(3421);
        set_picid_2(3421);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。一只被赵国百姓弄坏，后来被公输班修好的木桶。"; 
}