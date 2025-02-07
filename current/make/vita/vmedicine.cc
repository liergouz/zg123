#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

#define ITEM_USE_TIME	30

// ��������������
int get_max_combined() { return %d; }

// ��������ʹ����Ʒ
int get_item_type_2() { return %s; }

// ��������Ʒ���
int get_fin_type() { return %d; }

// ���������촦��
void create()
{
        set_name( "%s" );
        set_picid_1(%d);
        set_picid_2(%d);
        set_value(%d);
        set("level", %d);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "%s";
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
      		send_user( me, "%%c%%s", '!', sprintf("�����䶳ʱ�仹ʣ%%d��", get_effect(me, type)) );
              	return 0;
      	}       
      	if (me->get_level()< obj->get("level"))
      	{
      		send_user( me, "%%c%%s", '!', sprintf("��ĵȼ�����%%d", obj->get("level")) );
              	return 0;
      	}       	
      	set_effect(me, type, ITEM_USE_TIME);
	send_user( me, "%%c%%c%%c%%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME );    // ����ʹ�ü��
        me->add_hp( %d * ( 100 + me->get_healing_rate() ) / 100 );        
        me->add_mp( %d * ( 100 + me->get_healing_rate() ) / 100 );        
        if(type == EFFECT_USE_ITEM_1) send_user( get_scene_user_2(me), "%%c%%d%%w%%c%%c%%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE );      
        else send_user( get_scene_user_2(me), "%%c%%d%%w%%c%%c%%c", 0x6f, getoid(me), 9156, 1, OVER_BODY, PF_ONCE );      
        return 1;
}
