
// �Զ����ɣ�/make/item/make30
#include <item.h>

inherit ITEM;
    inherit COMBINED;
// ������ԭ������
int get_stuff_type() { return 217; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(4105);
        set_picid_2(4105);
        set_unit("ֻ");
        set_value(200);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "������֫���һ����"; 
}
