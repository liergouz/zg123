
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 233; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("�Ͼ�");
        set_picid_1(3152);
        set_picid_2(3152);
        set_value(1150);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ũ�������һ�ְ׾ƣ�20���ڻָ����1000�㷨������";
}
