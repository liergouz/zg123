#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;   

// ���������촦��
void create()
{
        set_name( "Ǭ����" );
        set_picid_1(9601);
        set_picid_2(9601);
        set_value(5000);
        set("bag", 24);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�����С�ڴ��������ƺ����������޵Ŀռ䣬\n������ʹ����24��ı����ռ䡣\nǬ����30�����Զ��𻵡�"; 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/cmd/std/bag" ->get_use_effect(me, this_object()); }
