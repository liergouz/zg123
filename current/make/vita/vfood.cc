#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������������
int get_max_combined() { return %d; }

// ��������ʹ����Ʒ
int get_item_type_2() { return %s; }

// ��������Ʒ���
int get_fin_type() { return %d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_value(%d);
        set_amount(1);
	set("level", %d);
	set("add_hp", %d);	
	set("add_mp", %d);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "%s";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %%d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %%d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }