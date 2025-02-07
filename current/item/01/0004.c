
#include <equip.h>
inherit USABLE;
inherit ITEM;

// 函数：构造处理
void create()
{
        set_name("遗失的宝物");
        set_picid_1(4116);
        set_picid_2(4116);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc()
{
        return "任务物品，传说中遗失的秘宝。请速将此物送回本帮派的总管处。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_save_2("orgtask2.type")!=3 )
		return 1;
}