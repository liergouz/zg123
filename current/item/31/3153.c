
// �Զ����ɣ�/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
    inherit COMBINED;
inherit USABLE;   

// ��������������
//  int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_MP; }

// ���������촦��
void create()
{
        set_name("�յ���");
        set_picid_1(3153);
        set_picid_2(3153);
        set_unit("̳");
        set_value(1300);
        set_amount(1);
	set("level", 70);
	set("add_mp", 1300);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "ũ�������һ���Ҿƣ�20���ڻָ����1300�㷨������";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }