
// �Զ����ɣ�/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
    inherit COMBINED;
inherit USABLE;   

// ��������������
//  int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_HP; }

// ������ԭ������
int get_stuff_type() { return 226; }

// ���������촦��
void create()
{
        set_name("�㽶");
        set_picid_1(3281);
        set_picid_2(3281);
        set_unit("��");
        set_value(900);
        set_amount(1);
	set("level", 40);
	set("add_hp", 800);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "�ڸ��㻬��һ���ȴ�ˮ����20���ڻָ����800����Ѫֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }