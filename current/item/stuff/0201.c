
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 201; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ����ɫ
int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("�������ع���");
        set_picid_1(4211);
        set_picid_2(4211);
        set_value(1000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������������";
}
