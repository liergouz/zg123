#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_siliao() { return 1;}

// ���������촦��
void create()
{
        set_name( "С������" );
        set_picid_1(3204);
        set_picid_2(3204);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������ιС�����������ϡ�"; 
}