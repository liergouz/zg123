
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ���������촦��
void create()
{
        set_name( "���絤" );
        set_picid_1(9172);
        set_picid_2(9172);
        set_unit( "��" );
        set_value(50);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�������� 16 ����������";
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

        if( me->get_mascot("ap") == 0 )
        {
                me->add_mascot("ap", 1);
                USER_ENERGY_D->count_ap(me);
                return 1;
        }
        else 
        {
                send_user(me, "%c%s", '!', get_name() + "һ��ֻ��ʹ�� 5 �Ρ�" );
                return 0;
        }
}
