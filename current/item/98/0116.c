#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "��ӡ" );
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������Ϳ���ع�Ū���Ĺ�ӡ��"; 
}