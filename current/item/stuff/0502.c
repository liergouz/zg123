
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit TALISMAN;

// ������ԭ������
int get_stuff_type() { return 502; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_HAMMER; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(3410);
        set_picid_2(3410);
        set_value(7000);
        set_max_lasting(12599);
        set_lasting(12599);
        set_level(90);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�߼�����ʹ�õĹ���";
}
