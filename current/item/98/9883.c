#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_tieqiu() { return 1;}

// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(3401);
        set_picid_2(3401);
        set_unit( "��" );
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ����ũ��ʱ�����һ�ֹ��ߡ�"; 
}