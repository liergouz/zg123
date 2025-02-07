#include <ansi.h>
#include <item.h>
#include <task.h>

inherit ITEM;
inherit USABLE;
inherit LEGEND_ITEM;

int is_huowu() { return 1;}

// 函数：构造处理
void create()
{
        set_name( "钱老九的货物" );
        set_picid_1(4);
        set_picid_2(4);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "任务物品。钱老九被楚方城守卫扣押的货物。"; 
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_legend(TASK_NEWBIE_03, 2)	|| ( !me->get_legend(TASK_NEWBIE_03, 1) && !me->get_legend(TASK_NEWBIE_03, 2)) )
		return 1;
}