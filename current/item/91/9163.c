
#include <effect.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1825; }

// ���������촦��
void create()
{
        set_name( "��ɣɢ" );
        set_picid_1(9163);
        set_picid_2(9163);
        set_unit( "��" );
        set_value(50);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һСʱ������ 12% ���������";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
	int time;
/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */
        time =  get_effect_3(me, EFFECT_USER_DP);
        if (time>0)
        {
        	send_user(me, "%c%s", '!', sprintf("������������ʣ%d��", time) );
        	return 0;
        }
	me->set_save("03291#", me->get_dp()*12/100);
        set_effect(me, EFFECT_USER_DP, 3600);
        USER_ENERGY_D->count_dp(me);

        return 1;
}
