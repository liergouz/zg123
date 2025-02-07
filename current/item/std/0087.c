
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
        set_name( "���쵤" );
        set_picid_1(9172);
        set_picid_2(9172);
        set_unit( "��" );
        set_value(2000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ܴ��� 2000 Ǳ��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        if( item->get_potential() < 1 )
        {
                if( me->get_potential() < 2000 )
                {
                        send_user(me, "%c%s", '!', "����һ�γ��� 2000 Ǳ�ܡ�");
                        return 0;
                }
                me->add_potential( -2000 );
                item->set_potential(2000);
                write_user(me, "�㽫 2000 Ǳ�ܳ���%s��", item->get_name() );
                send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

                return 0;    // ����ɾ��
        }
        else
        {
                me->add_potential(2000);
                return 1;
        }

        return 0;
}
