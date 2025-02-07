#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define RIDE_ID	3

// ���������촦��
void create()
{
        set_name( "���ҵ�" );
        set_picid_1(12);
        set_picid_2(12);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "�Թ�ר���������\nʹ��������ʹ����Ϊ�Թ���������Թ��ﵽһ�����Ѻöȡ�\n�õ���ʹ�ú�󶨡�\n";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
        return 0;
}
