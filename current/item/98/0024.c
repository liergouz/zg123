#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "Ů����" );
        set_picid_1(3156);
        set_picid_2(3156);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ�������������������͸��������һ�־ơ�"; 
}