#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "�Ͼ�" );
        set_picid_1(3152);
        set_picid_2(3152);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������Ŵ�����ƣ������������µ��׾ƣ�����ǿ����֮��Ч��"; 
}