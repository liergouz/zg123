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
int get_fin_type() { return 1775; }

// ���������촦��
void create()
{
        set_name("�����ϻ���");
        set_picid_1(9973);
        set_picid_2(9973);
        set_value(700);
        set_amount(1);
	set("level", 80);
	set("add_hp", 2590);	
	set("add_mp", 2590);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "���ص������ȵ�ʱ��ζ��ǧ��ٹ֣�14���ڻָ����2590����Ѫ�뷨��ֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }