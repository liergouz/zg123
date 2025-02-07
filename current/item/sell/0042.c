#include <ansi.h>
#include <skill.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_number() {return 10001069 ;}
int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name( "��Ԫ��" );
        set_picid_1(4116);
        set_picid_2(4116);
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��˵Ϊ��ү˽�ص���ϡ��ҩ��ʹ�ú�ÿ2���Զ��ظ�1��Ԫ����\n����5���ӡ���ȴʱ��2�롣";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        if( get_effect_3(me, EFFECT_RECOVER_YUAN)>=298 ) 
        {
                return 0;
        }
	if ( get_effect_3(me, EFFECT_RECOVER_YUAN) )
	{
		send_user( me, "%c%c%s", 0x59, 1, sprintf("�������Ѿ���һ����Ԫ���ڲ������ã���ȷ��Ҫ��������Ч����\n"
                        ESC "%c\n"ESC"use ! %x#\n"
			, 1, getoid(item) ) );		
		return 0;
	}
        set_effect_2(me, EFFECT_RECOVER_YUAN, 150, 2 );
        send_user( me, "%c%w%w%c", 0x81, 298, get_effect_3(me, EFFECT_RECOVER_YUAN), EFFECT_GOOD );
        return 1;
}

// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object who, object item )
{
        set_effect_2(who, EFFECT_RECOVER_YUAN, 150, 2 );
        send_user( who, "%c%w%w%c", 0x81, 298, get_effect_3(who, EFFECT_RECOVER_YUAN), EFFECT_GOOD );
	return 1;
}

void into_effect(object me)
{
	me->add_yuan(1);
}

string get_loop_desc(object me)
{
	return "��Ԫ����\n    ÿ2��ɻظ�1��Ԫ����";
}