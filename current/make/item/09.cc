
// �Զ����ɣ�/make/item/make09

#include <equip.h>
inherit FAMILY_EQUIP;

int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_family_name("%s");      
        set_max_lasting(1099);
        set_lasting(1099);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);          

}

// ��������ȡ����
string get_desc() 
{ 
        return sprintf("�������� %s��",get_item_level()); 
}
