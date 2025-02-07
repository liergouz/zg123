
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_number() {return 10001040 ;}

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "pp"; }

// 宝石打造的辩别标志
string get_diamond_index() {return "6";}

// 函数：构造处理
void create()
{
        set_name("水灵石");
        set_real_name("水晶石");
        set_picid_1(8985);
        set_picid_2(8985);
        set_unit("块");
        set_value(400);
        set_level(1);
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 17;
		break;	
	case 2:
		value = 22;
		break;	
	case 3:
		value = 27;
		break;	
	case 4:
		value = 32;
		break;					
	case 5:
		value = 37;
		break;
	case 6:
		value = 42;
		break;
	case 7:
		value = 47;
		break;				
	case 8:
		value = 52;
		break;				
	case 9:
		value = 57;
		break;				
	case 10:
		value = 62;
		break;				
	}
	return value;	
}

// 函数：获取描述
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "用来加强装备的特殊材料，增加的属性受到灵石的级别影响。同类同级灵石也可与同类同级晶石或者灵石相互合成进行升级。\n［精炼］ 法防\n［适用装备］ 衣服、腰带、项链、鞋子、帽子";
        return sprintf("用来加强装备的特殊材料，增加的属性受到灵石的级别影响。同类同级灵石也可与同类同级晶石或者灵石相互合成进行升级。\n［精炼］ 法防 %+d\n［适用装备］ 衣服、腰带、项链、鞋子、帽子", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "水灵石";
	return sprintf("%d级水灵石", me->get_level());
}