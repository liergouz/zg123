
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 81; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("��챦ʯ");
        set_picid_1(8954);
        set_picid_2(8954);
        set_value(2000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��װ���ֽ�����ı�ʯ��ʯ�̡����������ء��÷�����Ĳ���";
}
