#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������������
int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_CON_HP; }

// ��������Ʒ���
int get_fin_type() { return 1713; }

// ���������촦��
void create()
{
        set_name("���ӽ�֭ţ��");
        set_picid_1(3310);
        set_picid_2(3310);
        set_value(600);
        set_amount(1);
	set("level", 80);
	set("add_hp", 1190);	
	set("add_mp", 0);	
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "��ݮ��֭���е���ζ��14���ڻָ����1190����Ѫֵ��";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"ʹ��Ҫ�� %d ��", get("level") ); 
	else
		return sprintf(desc+"\nʹ��Ҫ�� %d ��", get("level") ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }