#include <ansi.h>
#include <item.h>
#include <task.h>

inherit ITEM;
inherit USABLE;
inherit LEGEND_ITEM;

int is_huowu() { return 1;}

// ���������촦��
void create()
{
        set_name( "Ǯ�ϾŵĻ���" );
        set_picid_1(4);
        set_picid_2(4);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ��Ǯ�Ͼű�������������Ѻ�Ļ��"; 
}
// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_legend(TASK_NEWBIE_03, 2)	|| ( !me->get_legend(TASK_NEWBIE_03, 1) && !me->get_legend(TASK_NEWBIE_03, 2)) )
		return 1;
}