#include <item.h>
#include <ansi.h>

inherit ITEM;

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_number() {return 10001077 ;}

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

int is_specal_move() {return 1;}

// ���������촦��
void create()
{
        set_name("���׷�");
        set_picid_1(3454);
        set_picid_2(3454);
        set_value(20);
}

string get_desc() 
{
	return "ʹ��ʱ�轫������ҷ������ʯ֮�ϲſɷ������ã�\n���ḽ�Ķ���ʯ�������ʧ�ܺ�װ�����������ήΪ�㣬ֻ�����һ���ǡ�";
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
	if( equip->get_real_name()!="����ʯ" )  return 0;
	if (equip->get_forge_index()!="3") 
	{
		notify( "ֻ�ܽḽ�ڸ߼�����ʯ��" );
		return 1;
	}
	if (type==1)
	{		
		result = sprintf("�����׷��ḽ�ڸö���ʯ֮������������ȷ�����װ������ʧ�ܺ�װ��������ֻ�����һ���ǡ�\n"
		        ESC "%c\n" ESC "\nmove ! %x# %d\n"
		        , 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);	
		return 1;
	}
		
	p = get_d(equip);
	result = sprintf("������ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
	"/sys/user/cmd"->log_item(result);
	item->remove_from_user();
	destruct(item);
	item = equip;
	result = sprintf("������ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
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