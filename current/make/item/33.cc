
// �Զ����ɣ�/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
%s  inherit COMBINED;
inherit USABLE;   

// ��������������
%s  int get_max_combined() { return %d; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_HP; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_value(%d);
%s      set_amount(1);
	set("level", %d);
	set("add_hp", %d);	
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