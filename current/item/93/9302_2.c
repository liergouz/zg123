
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "mp"; }

// 宝石打造的辩别标志
string get_diamond_index() {return "2";}

// 函数：构造处理
void create()
{
        set_name("月晶石");
        set_real_name("月晶石");
        set_picid_1(8981);
        set_picid_2(8981);
        set_unit("块");
        set_value(30000);
        set_level(2);
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 60;
		break;	
	case 2:
		value = 75;
		break;	
	case 3:
		value = 90;
		break;	
	case 4:
		value = 105;
		break;					
	case 5:
		value = 120;
		break;
	case 6:
		value = 135;
		break;
	case 7:
		value = 150;
		break;				
	case 8:
		value = 165;
		break;				
	case 9:
		value = 180;
		break;				
	case 10:
		value = 195;
		break;				
	}
	return value;	
}

// 函数：获取描述
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "［精炼］ 法力\n［适用装备］ 衣服、腰带、项链、鞋子、帽子";
        return sprintf("［精炼］ 法力 %+d\n［适用装备］ 衣服、腰带、项链、鞋子、帽子", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "月晶石";
	return sprintf("%d级月晶石", me->get_level());
}