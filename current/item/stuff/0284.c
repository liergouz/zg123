
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 284; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("��Ƭ");
        set_picid_1(1043);
        set_picid_2(1043);
        set_value(520);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������м��Ʒ";
}
