#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;   

// ��������Ʒ���
int get_fin_type() { return 2328; }

// ���������촦��
void create()
{
        set_name( "籲�����" );
        set_picid_1(7104);
        set_picid_2(7104);
        set_value(1000);
        set("bag", 6);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�Ӽ�����ʱ���õ�С������\n������ʹ����6��ı����ռ䡣\n����10�����Զ��𻵡�"; 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/cmd/std/bag" ->get_use_effect(me, this_object()); }
