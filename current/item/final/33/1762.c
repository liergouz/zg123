#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������������
int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_MP; }

// ��������Ʒ���
int get_fin_type() { return 1762; }

// ���������촦��
void create()
{
        set_name("Ů����");
        set_picid_1(3150);
        set_picid_2(3150);
        set_value(2000);
        set_amount(1);
	set("level", 70);
	set("add_hp", 0);	
	set("add_mp", 2380);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "Ů�����Ϊ��ʱ������Ů��Ů�ر�֮�14���ڻָ����2380�㷨��ֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }