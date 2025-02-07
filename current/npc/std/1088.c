
#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller_2() { return 1; }

// ���������촦��
void create()
{
        object me = this_object();

        set_name("��ҩ��");
        NPC_EQUIP_D->init_figure( this_object(), FARMER, MALE, 20 );
        set_city_name("���ִ�");

        set_2( "good", ([
                "01" : "/item/91/9120",    // �ȼ���
                "02" : "/item/91/9121",    // ���ĵ�
                "03" : "/item/91/9125",    // ������
                "04" : "/item/91/9140",    // �ٶ�ɢ
        ]) );
        set_2( "list", ([
                "01" : 20,
                "02" : 20,
                "03" : 10,
                "04" : 20,
        ]) );

        setup();

        set( "birthday", time() );

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // �������
        set_heart_loop(me, 600);    // ѭ��������������
        me->heart_beat();
        set_heart_beat(1);
}

// �������Ի�����
void do_look( object who )
{
        LIST_CMD->main( who, sprintf( "%x#", getoid( this_object() ) ) );
}

// -------------------------------------------------------------

// ��������������
void heart_beat() { }

private static int HeartSec = 0;        // ������ʱ

// ��������ȡ������ʱ
int get_heart_sec() { return HeartSec; }

// ����������������ʱ
int set_heart_sec( int point ) { return HeartSec = point; }

// ����������������ʱ
int add_heart_sec( int point ) { return set_heart_sec(HeartSec + point); }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ���ִ���
{
        object who;
        mapping good;

        if( me->add_heart_sec(1) > 5 )    // ���ֺ�������
        {
                me->remove_from_scene();
                destruct(me);
                return;
        }

        if( mapp( good = me->get_2("good") ) && !sizeof( keys(good) ) )
        {
                me->remove_from_scene();
                destruct(me);
                return;
        }
}
