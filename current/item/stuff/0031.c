
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 31; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_COOK; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("���ʯ");
        set_picid_1(3515);
        set_picid_2(3515);
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
int get_item_value() {return 1 ;}
int get_item_value_2() {return 1 ;}
string get_desc() 
{ 
        return "�໥������Ħ�����𻨵�ʯͷ";
}
