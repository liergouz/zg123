
// �Զ����ɣ�/make/item/make90
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE; 

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 230; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_MP; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("�׾�");
        set_picid_1(3150);
        set_picid_2(3150);
        set_value(650);
        set_amount(1);
	set("level", 10);               
	set("add_mp", 350);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "�������Ƶ�һ��ˮ��,20���ڻָ����350�㷨������";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }