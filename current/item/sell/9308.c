
// �Զ����ɣ�/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// ��������ʯʶ��
int is_diamond_2() { return 1; }

int get_item_value() {return 18 ;}
int get_item_value_2() {return 18 ;}
int get_item_number() {return 10001042 ;}

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// ��������ʯʶ��
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// ��������ʯ����
string get_diamond_type() { return "?%"; }

// ��ʯ����ı���־
string get_diamond_index() {return "8";}

// ���������촦��
void create()
{
        set_name("Ӱ��ʯ");
        set_real_name("Ӱ��ʯ");
        set_picid_1(8987);
        set_picid_2(8987);
        set_unit("��");
        set_value(600);
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
		value = 20;
		break;	
	case 2:
		value = 40;
		break;	
	case 3:
		value = 60;
		break;	
	case 4:
		value = 80;
		break;					
	case 5:
		value = 100;
		break;
	case 6:
		value = 120;
		break;
	case 7:
		value = 140;
		break;				
	case 8:
		value = 160;
		break;				
	case 9:
		value = 180;
		break;				
	case 10:
		value = 200;
		break;				
	}
	return value;	
}

// ��������ȡ����
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "������ǿװ����������ϣ����ӵ������ܵ���ʯ�ļ���Ӱ�졣ͬ��ͬ����ʯҲ����ͬ��ͬ����ʯ������ʯ�໥�ϳɽ���������\n�۾����� ����ر���\n������װ���� ������������Ь��";
        return sprintf("������ǿװ����������ϣ����ӵ������ܵ���ʯ�ļ���Ӱ�졣ͬ��ͬ����ʯҲ����ͬ��ͬ����ʯ������ʯ�໥�ϳɽ���������\n�۾����� ����ر��� %+.2f��\n������װ���� ������������Ь��", to_float(me->get_diamond_add())/100); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "Ӱ��ʯ";
	return sprintf("%d��Ӱ��ʯ", me->get_level());
}