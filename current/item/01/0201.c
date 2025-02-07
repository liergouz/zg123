#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int is_box() {return 1;}

// 函数：构造处理
void create()
{
        set_name("青铜宝盒");
        set_picid_1(6704);
        set_picid_2(6704);
        set_level(2);
        set_value(50);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "周王为藏匿宝藏特请能工巧匠精制而成，\n右键点击宝盒，其处于放大状态（可用"HIR"青铜钥匙"NOR"开启）。";
}

int get_use_effect( object me ) 
{
	return "/item/01/0200"->get_use_effect_callout(me,this_object());	
}
