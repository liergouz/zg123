#include <ansi.h>
#include <item.h>

inherit ITEM;

//int get_item_type() { return ITEM_TYPE_SPECIAL; }
int is_brand() { return 1; }
// ���������촦��
void create()
{
        set_name( "��Ϧ��õ��" );
        set_picid_1(0052);
        set_picid_2(0052);
        set_value(0);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  
//        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "Ե�������˵�ҵ�������ͬ��������ԣ�Ȼ������ҵ����ϣ�\n�������ϵ�ָ���������������벻���ľ�ϲ��"; 
}