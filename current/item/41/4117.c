
// �Զ����ɣ�/make/item/make30
#include <item.h>
inherit ITEM;
    inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 29; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ���������촦��
void create()
{
        set_name("��֮��");
        set_picid_1(3450);
        set_picid_2(3450);
        set_unit("��");
        set_value(150);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���Ǿ�������Ļ��Ǿ���"; 
}
