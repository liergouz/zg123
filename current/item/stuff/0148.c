
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 148; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("�Ϲ�");
        set_picid_1(3211);
        set_picid_2(3211);
        set_value(20);
        set_amount(1);
        set("plant", 50);
        set("pvalue", 200);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ʳ������������";
}
