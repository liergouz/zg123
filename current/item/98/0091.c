#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;


// ���������촦��
void create()
{
        set_name( "ֽǮ" );
        set_picid_1(3454);
        set_picid_2(3454);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������ר��Ǯ�ң���ľ��ե�����ɶ��ɣ�������а֮�á�"; 
}