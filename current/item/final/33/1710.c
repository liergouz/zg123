#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������������
int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_ALL; }

// ��������Ʒ���
int get_fin_type() { return 1710; }

// ���������촦��
void create()
{
        set_name("ˮ����Ϲ�");
        set_picid_1(3211);
        set_picid_2(3211);
        set_value(400);
        set_amount(1);
	set("level", 60);
	set("add_hp", 665);	
	set("add_mp", 1680);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "���Ϲϸ�ˮһ����14���ڻָ����1680�㷨��ֵ��665����Ѫֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }