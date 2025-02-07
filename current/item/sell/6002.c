#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;   

int get_item_value() {return 99 ;}
int get_item_value_2() {return 99 ;}
int get_item_number() {return 10001071 ;}
int get_item_color() {return 2 ;}

// 函数：构造处理
void create()
{
        set_name( "余静（制作）" );
        set_picid_1(9601);
        set_picid_2(9601);
        set_value(100000000);
        set("bag", 24);
        set("lasting", 1);	// 永久可用
}

// 函数：获取描述
string get_desc() 
{ 
        return "千年修练的余静，可以让你瞬间变富，而且可以增加使用者24格的背包空间。\n永久可用。"; 
}

string get_short()
{
	return "可永久增加24格背包空间。";
}

// 函数：使用效果
int get_use_effect( object me ) { return "/cmd/std/bag" ->get_use_effect(me, this_object()); }
