
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit TALISMAN;

// ������ԭ������
int get_stuff_type() { return 504; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_HAMMER; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("���ƺ�����");
        set_picid_1(3410);
        set_picid_2(3410);
        set_value(20000);
        set_max_lasting(17599);
        set_lasting(17599);
        set_level(120);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��˵�еĹ���";
}
