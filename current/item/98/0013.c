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
        set_name( "����" );
        set_picid_1(6134);
        set_picid_2(6134);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ���ഫ���߲���ë���ƶ��ɵ����¡�"; 
}