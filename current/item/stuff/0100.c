
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 1; }

// ������ԭ������
int get_stuff_type() { return 100; }

int get_rate_2() { return 40; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_DIAMOND; }

// ������ԭ����ɫ
int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("��������ʯ");
        set_picid_1(8973);
        set_picid_2(8973);
        set_value(1000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����������Ʒ��ֵ�������ʵĵ��ߣ�����40%�ĳɹ���";
}
