
#include <effect.h>
#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_value() {return 250 ;}
int get_item_value_2() {return 200 ;}
int get_item_number() {return 10001011 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name( "�˲�" );
        set_picid_1(4010);
        set_picid_2(4010);
        set_unit( "��" );
        set_value(180);
        set_amount(1);
        set_record(1);
        // -- ��ԭװ��������Ӱ�����
        set_no_give(1);
        set_no_sell(1);
        //        
        set("effect", 600);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ʮ�������ҩ�ģ���˵��ǿ����֮�á�����1Сʱ�ڿ��������600����Ѫ���ޡ�";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me,this_object()); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me,object item )
{
/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */

	if ( get_effect(me, EFFECT_RENSHEN) )
	{
		if (me->get_save("rs_hp")==0 || me->get_save("rs_hp")==600)
			send_user( me, "%c%c%w%s", ':', 3, 0,sprintf("�������Ѿ���һ���˲��ڲ������ã���ȷ��Ҫ��������Ч����\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(item))); 
		else
			send_user( me, "%c%c%w%s", ':', 3, 0,sprintf("�������Ѿ���һ���˲����ڲ������ã���ȷ��Ҫ��������Ч����\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(item))); 
		return 0;
	}
        set_effect(me, EFFECT_RENSHEN, 3600);
        me->set_save("rs_hp", item->get("effect"));
        USER_ENERGY_D->count_max_hp(me);
	send_user( me, "%c%w%w%c", 0x81, 6, 3600, EFFECT_GOOD );
	send_user( me, "%c%w%s", 0x82, 6, CHAR_CHAR_D->get_loop_desc(me, 6) );
        return 1;
}

string get_loop_desc(object me)
{
	if (me->get_save("rs_hp")==0 || me->get_save("rs_hp")==600)
		return "�˲Σ�\n    ����1Сʱ�ڿ��������600����Ѫ���ޡ�";
	else
		return "�˲�����\n    ����1Сʱ�ڿ��������2000����Ѫ���ޡ�";
}

void into_effect(object me)
{
	USER_ENERGY_D->count_max_hp(me);
	send_user( me, "%c%w%w%c", 0x81, 6, 0, EFFECT_GOOD );
}

// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object me, object item )
{
	set_effect(me, EFFECT_RENSHEN, 3600);
	me->set_save("rs_hp", item->get("effect"));
        USER_ENERGY_D->count_max_hp(me);
	send_user( me, "%c%w%w%c", 0x81, 6, 3600, EFFECT_GOOD );
	send_user( me, "%c%w%s", 0x82, 6, CHAR_CHAR_D->get_loop_desc(me, 6) );
        return 1;
}