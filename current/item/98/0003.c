#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;

int is_xuantieshi() { return 1;}

// 函数：构造处理
void create()
{
        set_name( "铸剑石" );
        set_picid_1(8955);
        set_picid_2(8955);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。"; 
}