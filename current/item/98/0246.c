#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_sacred_clothes() { return 1;}

// ���������촦��
void create()
{
        set_name( "�ƽ�ʥ��" );
        set_picid_1(6062);
        set_picid_2(6062);
        set_value(1);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  
//        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "���Ϻ��ܱ�ɻƽ�ʥ��ʿ������ս�¡�"; 
}

