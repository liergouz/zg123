#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit "/inh/item/diamond";
inherit COMBINED;

// ��������ʹ����Ʒ
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int get_item_type_2() { return ITEM_TYPE_DIAMOND_4; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// ������ԭ������
int get_stuff_type() { return 323; }

// ���������촦��
void create()
{
        set_name("ŷұ��ʯ");
        set_picid_1(8969);
        set_picid_2(8969);
        set_value(100);
        set_amount(1);
}

string get_loop_desc(object me)
{
	return "";
}

// ��������ȡ����
string get_desc() 
{
	return "��˵ŷұ�Ӵ�������ʱ��ʹ�õı�ʯ��";
}

