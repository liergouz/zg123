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
int get_fin_type() { return 1760; }

// ���������촦��
void create()
{
        set_name("�ھ�");
        set_picid_1(3155);
        set_picid_2(3155);
        set_value(1500);
        set_amount(1);
	set("level", 80);
	set("add_hp", 0);	
	set("add_mp", 1890);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "�ǹŴ����ƣ���Դ���ӻ��壬14���ڻָ����1890�㷨��ֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }