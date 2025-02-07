
#include <item.h>

inherit ITEM;
inherit USABLE;

private int Potential;                  // Ǳ��

// ��������������
// int is_potential_item() { return 1; }

// ��������������
int get_item_type() { return ITEM_TYPE_POTENTIAL; }

// ��������ȡǱ������
int get_potential() { return Potential; }

// ����������Ǳ������
int set_potential( int point ) { return Potential = point; }

// ���������촦��
void create()
{
        set_name( "��ת��" );
        set_picid_1(9171);
        set_picid_2(9171);
        set_unit( "��" );
        set_value(1000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ܴ��� 1000 Ǳ��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        if( item->get_potential() < 1 )
        {
                if( me->get_potential() < 1000 )
                {
                        send_user(me, "%c%s", '!', "����һ�γ��� 1000 Ǳ�ܡ�");
                        return 0;
                }
                me->add_potential( -1000 );
                item->set_potential(1000);
                write_user(me, "�㽫 1000 Ǳ�ܳ���%s��", item->get_name() );
                send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

                return 0;    // ����ɾ��
        }
        else
        {
                me->add_potential(1000);
                return 1;
        }

        return 0;
}
