
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit TALISMAN;

// ������ԭ������
int get_stuff_type() { return 512; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_NEEDLE; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("����֯����");
        set_picid_1(4170);
        set_picid_2(4170);
        set_value(7000);
        set_max_lasting(12599);
        set_lasting(12599);
        set_level(90);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�߼��÷�ʹ�õĹ���";
}
