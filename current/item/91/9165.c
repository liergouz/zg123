
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1827; }

// ���������촦��
void create()
{
        set_name( "��Ԫ��" );
        set_picid_1(9165);
        set_picid_2(9165);
        set_unit( "��" );
        set_value(50);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һСʱ������ 12% ����������";
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
	send_user( me, "%c%w%w%c", 0x81, 9165, 3600, EFFECT_GOOD );
        set_effect(me, EFFECT_ITEM_9165, 3600);
	me->set_save( "9165#", 12 );
        USER_ENERGY_D->count_pp(me);
        return 1;
}


void effect_done(object me)
{
        send_user( me, "%c%w%w%c", 0x81, 9165, 0, EFFECT_GOOD );

}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        return "һСʱ�����ӷ���������12����\n";
}