
#include <equip.h>
#include <effect.h>

inherit TALISMAN;

// ����������ʶ��
int get_talisman_type() { return 10; }

// ���������촦��
void create()
{
        object me = this_object();

        set_name( "��������" );
        set_picid_1(9591);
        set_picid_2(9591);
        set_unit( "��" );

        set_level(3);
        set_value(20000);
        set_max_lasting(18099);

        setup();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 150);    // ѭ����������������
        me->heart_beat();
        set_heart_beat(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�Զ��ظ���Ѫ������";
}

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ�����봦��
{
        object owner;

        if( objectp( owner = me->get_owner() ) || objectp( owner = environment() ) )
        {
                if( !get_effect(owner, EFFECT_CHAR_SUPPRESS) && owner->get_equip(HAND_TYPE) == me )
                {
                        if( !owner->is_die() ) 
                        {
                                owner->add_hp( owner->get_max_hp() * 3 / 100 );
                                owner->add_mp( owner->get_max_mp() * 3 / 100 );
                        }
                }
        }
}
