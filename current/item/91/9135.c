#include <effect.h>
#include <ansi.h>
#include <equip.h>

inherit COMBINED;
inherit "/inh/item/poison2";

// ���������촦��
void create()
{
        set_name( "ө���" );
        set_picid_1(9135);
        set_picid_2(9135);
        set_unit( "��" );
        set_value(2000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ө��ʯ���ƶ���,�������ڰ����ĵ����������Σ���ȴʱ��30��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        object *char;
        object who;
        int i, size;
	char = get_range_object_2(me, 6, USER_TYPE) + get_range_object_2(me, 6, CHAR_TYPE) - ({ me });
        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] )
                {
                	if (get_effect(who, EFFECT_CHAR_INVISIBLE))
                	{
                		set_effect_2(who, EFFECT_CHAR_INVISIBLE, 1, 1 );
                	}
                }
	return 1;
}
