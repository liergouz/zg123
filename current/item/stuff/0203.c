
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 1; }

// ������ԭ������
int get_stuff_type() { return 203; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ��������Ƕʶ��
int get_item_type() { return ITEM_TYPE_SHIKE; }

// ��������Ʒ����
int get_fin_type() { return 1614; }

// ������ԭ����ɫ
int get_item_color() { return 0; }
 
// ���������촦��
void create()
{
        set_name("��׼����");
        set_picid_1(4173);
        set_picid_2(4173);
        set_value(1500);
        set("double2", 100);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "װ���������ϣ����1%������";
}
