#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;
int is_xiaomai() { return 1;}

// ���������촦��
void create()
{
        set_name( "С��" );
        set_picid_1(3202);
        set_picid_2(3202);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ��һ����Ƶ��ϵȲ��ϡ�"; 
}