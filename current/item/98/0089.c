#include <ansi.h>
#include <item.h>
#include <task.h>

inherit ITEM;
inherit LEGEND_ITEM;


// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(7315);
        set_picid_2(7315);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ���Լ��͸�����Τ�����"; 
}
// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	if ( !me->get_legend(TASK_19, 26) ||  me->get_legend(TASK_19, 30) )
		return 1;
}