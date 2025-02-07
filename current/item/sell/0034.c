#include <item.h>
#include <ansi.h>

inherit ITEM;

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_number() {return 10001077 ;}

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

int is_specal_move() {return 1;}

// 函数：构造处理
void create()
{
        set_name("保底符");
        set_picid_1(3454);
        set_picid_2(3454);
        set_value(20);
}

string get_desc() 
{
	return "使用时需将符咒拖曳到锻造石之上才可发挥作用，\n被结附的锻造石如果锻造失败后，装备的星数不会降为零，只会减少一颗星。";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result;
	object item2;
	int p;
	if( equip->get_real_name()!="锻造石" )  return 0;
	if (equip->get_forge_index()!="3") 
	{
		notify( "只能结附在高级锻造石上" );
		return 1;
	}
	if (type==1)
	{		
		result = sprintf("将保底符结附在该锻造石之上吗？这样可以确保你的装备锻造失败后装备的属性只会减少一颗星。\n"
		        ESC "%c\n" ESC "\nmove ! %x# %d\n"
		        , 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);	
		return 1;
	}
		
	p = get_d(equip);
	result = sprintf("保底消失 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
	"/sys/user/cmd"->log_item(result);
	item->remove_from_user();
	destruct(item);
	item = equip;
	result = sprintf("保底消失 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
	"/sys/user/cmd"->log_item(result);
	item->remove_from_user();
	destruct(item);
	item2 = new ("/item/sell/3032");
	if( p = item2->move(me, p) )
	{
		item2->add_to_user(p);
	}		
	return 1;
}