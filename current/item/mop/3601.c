#include <item.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("�ҽ���");
        set_picid_1(3601);
        set_picid_2(3601);
        set_amount(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);          
        set_value(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ܶһ�������ͭ�ơ�";
}