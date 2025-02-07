
#include <ansi.h>
#include <npc.h>
#include <skill.h>
#include <effect.h>

inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 60; }

// ��������Чʱ��
int get_time_interval() { return 180; }

// ����������ʶ��
int get_talisman_type() { return 7; }

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9561);
        set_picid_2(9561);
        set_unit( "��" );

        set_level(1);
        set_value(5000);
        set_max_lasting(1099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "ѹ�ƶԷ�������ʹ����һ��ʱ����ʧȥЧ��";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ��������״����Ч��
void effect_suppress_done( object me )    // ˳������(����)
{
        object *user;

        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%w%w%c", 0x81, 9561, 0, EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 9561, 0, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 9561, 1, OVER_BODY, PF_STOP );
}

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9561" ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// ������ʹ�÷���Ч��(���߸���)
int get_use_effect_2_callout( object me, object who, object item, string arg )
{
        object *user;

        if( !objectp(who) ) return 1;

        if( !who->is_user() ) return 1;    // ���������

        if( who->get_login_flag() < 3 ) return 1;    // û��׼������

        if( who->is_die() || who->is_store_open() || who->get_no_fight() ) return 1;    // ��������̯����ȫ��

        if( me == who ) return 1;    // �������Լ�

        item->add_lasting(-1);    // ʹ�ü����;�

        me->set_char_type( PK_TYPE );    // �����У�״̬
        set_effect(me, EFFECT_USER_PK, 120);

        if( get_effect(who, EFFECT_CHAR_SUPPRESS) ) return 1;    // �ѱ�ѹ��

        if( random(100) < item->get_active_rate() )    // �ɹ���
        {
                user = get_scene_object_2(who, USER_TYPE);
                set_effect( who, EFFECT_CHAR_SUPPRESS, item->get_time_interval() );
                send_user( who, "%c%w%w%c", 0x81, 9561, get_effect_3(who, EFFECT_CHAR_SUPPRESS), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9561, 1, EFFECT_BAD );
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9569, 1, OVER_BODY, PF_ONCE );
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9561, 1, OVER_BODY, PF_LOOP );

                write_user( me, ECHO "%s�ķ���������" HIY "����" ECHO "�����ˣ������춯��", who->get_name() );
                write_user( who, ECHO "���ķ�����%s��" HIY "����" ECHO "�����ˣ������춯��", me->get_name() );
        }
        else    write_user( me, ECHO "����%sʹ��" HIY "����" ECHO "ʧ���ˡ�", who->get_name() );

        return 1;
}
