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

int get_item_color() {return 2 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "forge"; }

// 宝石锻造的辩别标志
string get_forge_index() {return "2";}

int is_specal_move() {return 1;}

// 函数：构造处理
void create()
{
        set_name("中级锻造石");
        set_real_name("锻造石");
        set_picid_1(4272);
        set_picid_2(4272);
        set_unit("块");
        set_value(50);
        set_level(1);
}

string get_desc() 
{
	return "只能锻造在2星或3星的装备上，可加强该装备的属性。\n两个中级锻造石可合成一个高级锻造石。";
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
	if (equip->get_real_name()=="锻造石" && item->get_forge_index()!=equip->get_forge_index())
	{
		notify( "级别不同的锻造石无法进行合成。" );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (i>0)
	{
		if (level!=2&&level!=3)
		{
			notify( "中级锻造石只能锻造在2星或3星的装备上。" );
			return 1;
		}
	}
	rate = 100;
	if (type==1)
	{
		if (i==0 )
		{
			result = sprintf("你确定要将两个中级锻造石合成为一个高级锻造石吗？\n"
			        ESC "%c\n" ESC "\nmix2 0# %x# %x#\n"
			        , 1, getoid(item), getoid(equip) );
			send_user(me, "%c%c%s", 0x59, 1, result);
		}
		else
		{
			result = sprintf("装备锻造失败后加成的星便会清0，\n当前装备的锻造成功率为"HIR" %d％"NOR"，\n你确定要锻造%s吗？\n"
				ESC "确定\nmix3 0# %x# %x#\n"
				ESC "取消",
			        rate, equip->get_name(), getoid(equip), getoid(item) );

			send_user(me, "%c%c%w%s", ':', 3, 0, result);
		}		       			
		return 1;
	}		
	return 1;
}