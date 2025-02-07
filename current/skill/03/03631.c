
// ���ó�������  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0363
#define THIS_PERFORM    03631
#define PF_START       "03631"
#define PF_TIME        "03631#"
#define PF_NAME        "����"

#define SKILL_LEVEL     22
#define TIME_INTERVAL   2
#define SUB_MP          20

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "��" PF_NAME "���ڳ���ʱ���ڣ������Լ����Σ�����Ǳ�У���Ӱ���ƶ��ٶȡ����ķ�����%d���ٴ�ʹ������ %d �룬%s%d ������\n",
                SUB_MP, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "��\n���������Լ���Ӱ������Ǳ�С�����ʱ���ƶ��ٶȼ��� 50����\n" );
        else    return sprintf( PF_NAME "\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = me->get_perform(PF_TIME) + TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

//        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);

        interval = 20 + level / 2 + random( level / 2 );

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2( me, EFFECT_CHAR_INVISIBLE, interval / 10 + 1, 10 );    // ÿʮ���Ѫ
        set_effect_count( me, EFFECT_CHAR_INVISIBLE, interval % 10 );
        send_user( me, "%c%w%w%c", 0x81, 3631, get_effect_3(me, EFFECT_CHAR_INVISIBLE), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3631, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 36311, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_LOOP );    // ��͸��

        set_invisible(me, 1);
        send_user( me, "%c%c%c", 0x3d, 241, 1 );    // ������·����

        return 1;
}

// ��������������
int cast_done( object me )
{
        object *user;
        int level, interval;

        level = me->get_skill(THIS_SKILL);
        interval = 20 + level / 2 + random( level / 2 );

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2( me, EFFECT_CHAR_INVISIBLE, interval / 10 + 1, 10 );    // ÿʮ���Ѫ
        set_effect_count( me, EFFECT_CHAR_INVISIBLE, interval % 10 );
        send_user( me, "%c%w%w%c", 0x81, 3631, get_effect_3(me, EFFECT_CHAR_INVISIBLE), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3631, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 36311, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_LOOP );    // ��͸��

        set_invisible(me, 1);
        send_user( me, "%c%c%c", 0x3d, 241, 1 );    // ������·����

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int interval;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = me->get_perform(PF_TIME) - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
}
