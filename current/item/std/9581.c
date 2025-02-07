
#include <ansi.h>
#include <equip.h>
#include <action.h>
#include <effect.h>

inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 100; }

// �������ָ�����
int get_revive_rete() { return 20; }

// ������׼��ʱ��
int get_time_interval() { return 1200; }

// ����������ʶ��
int get_talisman_type() { return 9; }

// ���������촦��
void create()
{
        object me = this_object();

        set_name( "�л��" );
        set_picid_1(9581);
        set_picid_2(9581);
        set_unit( "��" );

        set_level(1);
        set_value(5000);
        set_max_lasting(599);

        setup();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 100);    // ѭ����������������
        me->heart_beat();
        set_heart_beat(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�������൱���Լ���������ҾȻ�";
}

private static int HeartSec = 0;        // ������ʱ

// ��������ȡ������ʱ
int get_heart_sec() { return HeartSec; }

// ����������������ʱ
int set_heart_sec( int point ) 
{ 
        object who;

        point = range_value( point, 0, get_time_interval() ); 

        if(     HeartSec != point
        &&    ( objectp( who = get_owner() ) || objectp( who = environment() ) ) )
                send_user( who, "%c%d%c", 0x31, getoid( this_object() ), 0 );    // ��������

        return HeartSec = point; 
}

// ����������������ʱ
int add_heart_sec( int point ) { return set_heart_sec(HeartSec + point); }

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ�����봦��
{
        object owner;

        if( objectp( owner = me->get_owner() ) || objectp( owner = environment() ) )    // ��ȡ���˶���
        {
                if( !get_effect(owner, EFFECT_CHAR_SUPPRESS) && owner->get_equip(HAND_TYPE) == me )    // ����װ��֮��
                {
                        if( me->add_heart_sec(10) >= me->get_time_interval() )    // ������Ч״̬
                        {
                                if( owner->is_die() )    // random(100) < me->get_active_rate()
                                {
                                        set_effect(owner, EFFECT_USER_DIE, 0);
                                        owner->set_die(0);
                                        owner->set_hp( owner->get_max_hp() * me->get_revive_rete() / 100 );

                                        write_user( owner, ECHO HIY "�л��" ECHO "��������������" );

                                        owner->set_login_flag(2);    // ��ת����
                                        set_invisible(owner, 1);
                                        set_effect(owner, EFFECT_USER_LOGIN, 2);

                                        me->add_lasting(-1);    // ʹ�ü����;�
                                        me->set_heart_sec(0);    // ��ʼ��ʱ��(׼��״̬)
                                }
                        }
                }
        }
}
