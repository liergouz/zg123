#include <ansi.h>
#include <skill.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_number() {return 10001069 ;}
int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "天元丹" );
        set_picid_1(4116);
        set_picid_2(4116);
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "传说为王爷私藏的珍稀丹药，使用后每2秒自动回复1点元气，\n持续5分钟。冷却时间2秒。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        if( get_effect_3(me, EFFECT_RECOVER_YUAN)>=298 ) 
        {
                return 0;
        }
	if ( get_effect_3(me, EFFECT_RECOVER_YUAN) )
	{
		send_user( me, "%c%c%s", 0x59, 1, sprintf("你身上已经有一颗天元丹在产生作用，你确定要覆盖它的效果吗？\n"
                        ESC "%c\n"ESC"use ! %x#\n"
			, 1, getoid(item) ) );		
		return 0;
	}
        set_effect_2(me, EFFECT_RECOVER_YUAN, 150, 2 );
        send_user( me, "%c%w%w%c", 0x81, 298, get_effect_3(me, EFFECT_RECOVER_YUAN), EFFECT_GOOD );
        return 1;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
        set_effect_2(who, EFFECT_RECOVER_YUAN, 150, 2 );
        send_user( who, "%c%w%w%c", 0x81, 298, get_effect_3(who, EFFECT_RECOVER_YUAN), EFFECT_GOOD );
	return 1;
}

void into_effect(object me)
{
	me->add_yuan(1);
}

string get_loop_desc(object me)
{
	return "天元丹：\n    每2秒可回复1点元气。";
}