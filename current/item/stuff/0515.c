
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit TALISMAN;

// ������ԭ������
int get_stuff_type() { return 515; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_GRAVER; }

// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("�۶۵ĵ�̵�");
        set_picid_1(4907);
        set_picid_2(4907);
        set_value(1000);
        set_max_lasting(5099);
        set_lasting(5099);
        set_level(0);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ͨʯ��ʦʹ�õĹ���";
}
