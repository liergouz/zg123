#include <ansi.h>
#include <item.h>
#include <task.h>

inherit ITEM;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "��֥��" );
        set_picid_1(9032);
        set_picid_2(9032);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ����˵��������ͷ�۵�һ����ҩ�ġ�\n�һ�ʹ�ÿɴ�������"; 
}
// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_legend(TASK_49, 4) )
	{
		send_user( me, "%c%s",';',"����֥�ݽ������ִ嵱���ϰ壬�������κ�����ͷ�ۣ��������߶��ġ�");
		send_user( me, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
		send_user( me, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,115,"ͷ�۵�ë����3��" );
	}
}