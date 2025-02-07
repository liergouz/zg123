
// 自动生成：/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
    inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_CON_HP; }

// 函数：构造处理
void create()
{
        set_name("冰糖葫芦");
        set_picid_1(3325);
        set_picid_2(3325);
        set_unit("串");
        set_value(300);
        set_amount(1);
	set("level", 10);
	set("add_hp", 250);	
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	desc = "用山楂串制而成的一种食品，20秒内恢复玩家250点气血值。";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"使用要求 %d 级", get("level") ); 
	else
		return sprintf(desc+"\n使用要求 %d 级", get("level") ); 
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }