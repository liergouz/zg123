#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;


// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// ������ԭ������
int get_stuff_type() { return 171; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(3251);
        set_picid_2(3251);
        set_unit("��");
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ʳ������������"; 
}
