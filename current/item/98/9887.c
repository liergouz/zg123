#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_siliao() { return 1;}

// 函数：构造处理
void create()
{
        set_name( "小鸡饲料" );
        set_picid_1(3204);
        set_picid_2(3204);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。用来喂小鸡咕咕的饲料。"; 
}