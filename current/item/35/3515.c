
// �Զ����ɣ�/make/item/make35a
#include <item.h>
inherit ITEM;
    inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 31; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_COOK; }

// ���������촦��
void create()
{
        set_name("���ʯ");
        set_picid_1(3515);
        set_picid_2(3515);
        set_unit("��");
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�໥������Ħ�����𻨵�ʯͷ"; 
}
