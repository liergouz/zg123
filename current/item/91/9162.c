
#include <effect.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1824; }

// ���������촦��
void create()
{
        set_name( "��ңɢ" );
        set_picid_1(9162);
        set_picid_2(9162);
        set_unit( "��" );
        set_value(50);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һСʱ������ 10% ��������";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */

        set_effect(me, EFFECT_USER_AP, 3600);
	me->set_save( "ap10#", 10 );
        USER_ENERGY_D->count_ap(me);

        return 1;
}
