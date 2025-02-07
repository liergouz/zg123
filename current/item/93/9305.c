
// �Զ����ɣ�/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// ��������ʯʶ��
int is_diamond_2() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// ��������ʯʶ��
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// ��������ʯ����
string get_diamond_type() { return "cp"; }

// ��ʯ����ı���־
string get_diamond_index() {return "5";}

// ���������촦��
void create()
{
        set_name("��ʯ");
        set_real_name("��ʯ");
        set_picid_1(8984);
        set_picid_2(8984);
        set_unit("��");
        set_value(60000);
        set_level(1);
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 17;
		break;	
	case 2:
		value = 22;
		break;	
	case 3:
		value = 27;
		break;	
	case 4:
		value = 32;
		break;					
	case 5:
		value = 37;
		break;
	case 6:
		value = 42;
		break;
	case 7:
		value = 47;
		break;				
	case 8:
		value = 52;
		break;				
	case 9:
		value = 57;
		break;				
	case 10:
		value = 62;
		break;				
	}
	return value;	
}

// ��������ȡ����
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "�۾����� ����\n������װ���� ����������";
        return sprintf("�۾����� ���� %+d\n������װ���� ����������", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "��ʯ";
	return sprintf("%d����ʯ", me->get_level());
}