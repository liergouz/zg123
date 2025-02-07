#include <effect.h>
#include <ansi.h>
#include <equip.h>

inherit COMBINED;
inherit "/inh/item/poison2";

// 函数：构造处理
void create()
{
        set_name( "萤光粉" );
        set_picid_1(9135);
        set_picid_2(9135);
        set_unit( "包" );
        set_value(2000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "由萤光石炼制而成,让隐藏在暗处的敌人马上现形，冷却时间30秒";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        object *char;
        object who;
        int i, size;
	char = get_range_object_2(me, 6, USER_TYPE) + get_range_object_2(me, 6, CHAR_TYPE) - ({ me });
        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] )
                {
                	if (get_effect(who, EFFECT_CHAR_INVISIBLE))
                	{
                		set_effect_2(who, EFFECT_CHAR_INVISIBLE, 1, 1 );
                	}
                }
	return 1;
}
