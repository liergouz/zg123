
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
//inherit USABLE;   

// ��������������
//  int get_max_combined() { return 30; }

int get_item_color() { return 1; }
// ��������ʹ����Ʒ
//int get_item_type_2() { return ITEM_TYPE_2_PET; }
//������Ʒ
int is_pet_item() { return 1;}
// ���������촦��
void create()
{
        set_name("����Һ");
        set_picid_1(9991);
        set_picid_2(9991);
        set_unit("��");
        set_value(250000);
        set_amount(1);
}


// ��������ȡ����
string get_desc() 
{
	string desc;
	return desc = "�Գ���ʹ�õ�һ����ˮ���ܽ�����ת���ɣ�����ʼ״̬��";
}