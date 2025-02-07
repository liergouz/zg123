#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

#define ITEM_USE_TIME	15 - me->get_skill(0436) - (me->get_vip()?5:0)

// ��������������
int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_ADD_HP; }

// ��������Ʒ���
int get_fin_type() { return 1800; }

// ���������촦��
void create()
{
        set_name( "���ݸ�" );
        set_picid_1(9074);
        set_picid_2(9074);
        set_value(100);
        set("level", 10);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��˵�����޲���ò�ĸ�ҩ���������е����ã����ϻָ�600��Ѫ������ȴʱ��15��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
	int type;
	object obj = this_object();
	if (get_item_type_2()== ITEM_TYPE_2_ADD_HP) type = EFFECT_USE_ITEM_1;
	else type = EFFECT_USE_ITEM_2 ;
        if (get_effect(me, type))
      	{
      		send_user( me, "%c%s", '!', sprintf("�����䶳ʱ�仹ʣ%d��", get_effect(me, type)) );
              	return 0;
      	}       
      	if (me->get_level()< obj->get("level"))
      	{
      		send_user( me, "%c%s", '!', sprintf("��ĵȼ�����%d", obj->get("level")) );
              	return 0;
      	}       	
      	set_effect(me, type, ITEM_USE_TIME);
	send_user( me, "%c%c%c%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME );    // ����ʹ�ü��
        me->add_hp( 600 * ( 100 + me->get_healing_rate() ) / 100 );        
        me->add_mp( 0 * ( 100 + me->get_healing_rate() ) / 100 );        
        if(type == EFFECT_USE_ITEM_1) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE );      
        else send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9156, 1, OVER_BODY, PF_ONCE );      
        return 1;
}
