#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "�̲�" );
        set_picid_1(0003 );
        set_picid_2(0003 );
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������ȥ����Ҫ��·�ѡ�"; 
}

// ������ʹ��Ч��
int get_use_effect( object me )
{
	if ( !me->get_legend(7,9) )
		return 0;
	return 1;	
}