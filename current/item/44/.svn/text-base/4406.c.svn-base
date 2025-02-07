
// 自动生成：/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PET; }
//宠物物品
int is_pet_item() { return 1;}
// 函数：构造处理
void create()
{
        set_name("高级宠物食物");
        set_picid_1(9974);
        set_picid_2(9974);
        set_unit("个");
        set_value(400);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	return desc = "增加宠物忠诚的一种口粮，每食用一次，忠诚度增加20。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	object owner;
	if ( !me->is_pet() )
		return 0;
	owner = me->get_owner();
	if ( me->get_faith() >= 100 )
	{
		send_user(owner,"%c%s",'!',"你的宠物"+me->get_name()+"的忠诚度已经到达上限100");
		return 0;	
	}
	tell_user(owner,"你的"+me->get_name()+"忠诚增加20点");
	me->add_faith(20);
	return 1;	
}