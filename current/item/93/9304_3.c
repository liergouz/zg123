
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

int get_item_value() {return 18 ;}
int get_item_value_2() {return 18 ;}
int get_item_number() {return 10001039 ;}
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "dp"; }

// 宝石打造的辩别标志
string get_diamond_index() {return "4";}

// 函数：构造处理
void create()
{
        set_name("金晶石");
        set_real_name("金晶石");
        set_picid_1(8983);
        set_picid_2(8983);
        set_unit("块");
        set_value(40000);
        set_level(5);
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 15;
		break;	
	case 2:
		value = 20;
		break;	
	case 3:
		value = 25;
		break;	
	case 4:
		value = 30;
		break;					
	case 5:
		value = 35;
		break;
	case 6:
		value = 40;
		break;
	case 7:
		value = 45;
		break;				
	case 8:
		value = 50;
		break;				
	case 9:
		value = 55;
		break;				
	case 10:
		value = 60;
		break;				
	}
	return value;	
}

// 函数：获取描述
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "［精炼］ 物防\n［适用装备］ 衣服、腰带、项链、鞋子、帽子";
        return sprintf("［精炼］ 物防 %+d\n［适用装备］ 衣服、腰带、项链、鞋子、帽子", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "5级金晶石";
	return sprintf("%d级金晶石", me->get_level());
}