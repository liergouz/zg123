#include <time.h>
#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_item_number() {return 10001080 ;}   
int get_item_color() { return 2;};

inherit "/inh/equip/equip";

#define RIDE_ID	7

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(16);
        set_picid_2(16);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// ��������ȡ����
string get_desc() 
{ 
	object item = this_object();
	if (item->get_lock_time()==0) item->set_lock_time(time()+31*24*3600);	
        return "�ר����豿����\n�õ���ʹ�ú�󶨡�\n";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;
	if (item->get_lock_time()==0) item->set_lock_time(time()+31*24*3600);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "�����ѹ���");
		return 0;		
	}	
	if (me->get_fam_name()==""||!me->get_fam_name())
	{
		send_user(me, "%c%s", '!', "��Ҫ�������ɺ����ʹ��������ߡ�");
		return 0;
	}	
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
