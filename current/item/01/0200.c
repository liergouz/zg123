#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int is_box() {return 1;}

// 函数：构造处理
void create()
{
        set_name("红木宝盒");
        set_picid_1(6702);
        set_picid_2(6702);
        set_level(1);
        set_value(50);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "周王为藏匿宝藏特请能工巧匠精制而成，\n右键点击宝盒，其处于放大状态（可用"HIR"红木钥匙"NOR"开启）。";
}

int get_use_effect( object me ) 
{
	return "/item/01/0200"->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if (who->get_2("openbox.item")) return 0;
	if (who->get_online_rate()<100)
	{
		send_user(who, "%c%s", ';', "非健康时间不能打开宝箱！");
		return 0;
	}	
	send_user( who, "%c%c%c%d", 0x91, 1, item->get_level(), getoid(item) );
	return 0;
}