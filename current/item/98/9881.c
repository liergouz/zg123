#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_huodan() { return 1;}

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(3854);
        set_picid_2(3854);
        set_unit( "��" );
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ���ӻ����ϰ峣�õ��ż㣬������¼���������"; 
}