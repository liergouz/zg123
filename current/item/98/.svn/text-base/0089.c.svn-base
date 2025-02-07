#include <ansi.h>
#include <item.h>
#include <task.h>

inherit ITEM;
inherit LEGEND_ITEM;


// 函数：构造处理
void create()
{
        set_name( "宝剑" );
        set_picid_1(7315);
        set_picid_2(7315);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。赵姬送给吕不韦的礼物。"; 
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	if ( !me->get_legend(TASK_19, 26) ||  me->get_legend(TASK_19, 30) )
		return 1;
}