#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "forge"; }

// 宝石锻造的辩别标志
string get_forge_index() {return "3";}

int is_specal_move() {return 1;}

// 函数：构造处理
void create()
{
        set_name("高级锻造石");
        set_real_name("锻造石");
        set_picid_1(4273);
        set_picid_2(4273);
        set_unit("块");
        set_value(50);
        set_level(1);
}

string get_desc() 
{
	return "只能锻造4星或更高的装备，可加强该装备的属性加成。\n锻造失败，装备会还原为未锻造任何锻造石的状态。\n装备会随着锻造的次数越高，成功率会越低。";
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
	string result, forge;
	object item2;
	int i, p, level, rate;	
	if( equip->is_equip()==0 && equip->get_real_name()!="锻造石" )  return 0;
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}
	if (equip->get_real_name()=="锻造石" )
	{
		if (item->get_forge_index()!=equip->get_forge_index())
			notify( "级别不同的锻造石无法进行合成。" );
		else
			notify( "高级锻造石不需要进行合成。" );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (level<4)
	{
		notify( "高级锻造石只能锻造4星或更高的装备。" );
		return 1;
	}	
	rate = 10000;		
	for (i=4;i<=level;i++)
	{
		rate = rate * 3 / 5; 
	}
	rate /= 100;
	if ( me->get_vip() && !me->get_save_2("vip_package.trial") )
		rate += 5;
	if (rate>100) rate = 100;	
	if (type==1)
	{
		result = sprintf("装备锻造失败后加成的星便会清0，\n当前装备的锻造成功率为"HIR" %d％"NOR"，\n你确定要锻造%s吗？\n"
			ESC "确定\nmix3 0# %x# %x#\n"
			ESC "取消",
			rate, equip->get_name(), getoid(equip), getoid(item) );
		send_user(me, "%c%c%w%s", ':', 3, 0, result);			       			
		return 1;
	}		
	return 1;
}