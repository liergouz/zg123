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
int get_fin_type() { return 1766; }

// ���������촦��
void create()
{
        set_name("ţ�⳴����");
        set_picid_1(3310);
        set_picid_2(3310);
        set_value(600);
        set_amount(1);
	set("level", 60);
	set("add_hp", 1330);	
	set("add_mp", 665);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "ţ��ͼ����Ļ�ϳ���14���ڻָ����1330����Ѫֵ,665�㷨��ֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }