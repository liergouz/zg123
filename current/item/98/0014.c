#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

int iOwner;
int who_can_get() { return iOwner; }
int set_owner(int i) { return iOwner=i; }

// ���������촦��
void create()
{
        set_name( "����鴮" );
        set_picid_1(8657);
        set_picid_2(8657);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ����������һ�ֱ��顣"; 
}