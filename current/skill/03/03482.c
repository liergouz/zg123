
// ��������  TIPS:[PF_THROWING]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0348
#define THIS_PERFORM    03482
#define PF_START       "03482"
#define PF_NAME        "����"

#define SKILL_LEVEL     39
#define TIME_INTERVAL   10
#define SUB_MP          20
#define SUB_YUAN        3

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "��" PF_NAME "�ݵ���Զ�̼��ܣ��п���ʹĿ���ڳ���ʱ�����޷��ƶ������ķ�����%d������Ԫ����%d���ٴ�ʹ������ %d �룬%s%d ������\n",
                SUB_MP, SUB_YUAN, TIME_INTERVAL, level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "��\n�����޷��ƶ���\n" );
        else    return sprintf( PF_NAME "\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp, rate;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                x = get_x(who);  y = get_y(who);
        }
        else if( objectp( who = me->get_enemy_2() ) && inside_screen_2(me, who) )
        {
                x = get_x(who);  y = get_y(who);
        }
        else
        {
                return 1;
        }
        if (who->is_anti_effect()) return 2;
        
//      send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // Զ��Ŀ������

        pf = 50;    // ���� /sys/user/fight

        if( !( act = pf / 10 ) )    // pf: [�������][��Ӱ���]
        {
	        pf = 0;  act = 1 + random(3);    // ��ָ��������ţ����
	}

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), act, pf, get_d(me), getoid(who) );

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );


        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 34829, 1, UNDER_FOOT, PF_ONCE );
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 34821, 1, UNDER_FOOT, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�

        if( get_effect(who, EFFECT_CHAR_9145) ) return 2;    // ִ�гɹ�

        rate = range_value( 60 + level / 5, 0, 100 );
        if( get_effect(me, EFFECT_CHAR_BLIND) ) rate /= 2;    // ʧ��(���м���)

        if(    !get_effect(who, EFFECT_CHAR_SHUT)
        &&     !get_effect(who, EFFECT_CHAR_SHUT_0) )
        {
                if( random(100) < rate - who->get_immunity() ) 
                {
                        user = get_scene_object_2(who, USER_TYPE);
                        set_effect(who, EFFECT_CHAR_SHUT, 8);
                        send_user( who, "%c%w%w%c", 0x81, 3482, get_effect_3(who, EFFECT_CHAR_SHUT), EFFECT_BAD );
                        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3482, 1, EFFECT_BAD );
                        CHAR_CHAR_D->init_loop_perform(who);
                        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 34821, 1, UNDER_FOOT, PF_LOOP );

if( !is_player(me) ) tell_user( me, "R���� %d��", rate );
                }
else if( !is_player(me) ) tell_user( me, "R���� %d��", rate );
        }

        return 1;
}

// ��������������
int cast_done( object me )
{
        object *user, who;
        string arg;
        int z, x, y;
        int level, rate;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 34829, 1, UNDER_FOOT, PF_ONCE );
                send_user( get_scene_object(z, x, y, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x, y, 34821, 1, UNDER_FOOT, PF_ONCE );

                return 1;    // �򵽿յ�
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 34829, 1, UNDER_FOOT, PF_ONCE );
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 34821, 1, UNDER_FOOT, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�

        if( get_effect(who, EFFECT_CHAR_9145) ) return 2;    // ִ�гɹ�

        rate = range_value( 60 + level / 5, 0, 100 );
        if( get_effect(me, EFFECT_CHAR_BLIND) ) rate /= 2;    // ʧ��(���м���)

        if(    !get_effect(who, EFFECT_CHAR_SHUT)
        &&     !get_effect(who, EFFECT_CHAR_SHUT_0) )
        {
                if( random(100) < rate - who->get_immunity() ) 
                {
                        user = get_scene_object_2(who, USER_TYPE);
                        set_effect(who, EFFECT_CHAR_SHUT, 8);
                        send_user( who, "%c%w%w%c", 0x81, 3482, get_effect_3(who, EFFECT_CHAR_SHUT), EFFECT_BAD );
                        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3482, 1, EFFECT_BAD );
                        CHAR_CHAR_D->init_loop_perform(who);
                        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 34821, 1, UNDER_FOOT, PF_LOOP );

if( !is_player(me) ) tell_user( me, "R���� %d��", rate );
                }
else if( !is_player(me) ) tell_user( me, "R���� %d��", rate );
        }

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int level, interval, interval2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL;    // С��׼�� level
        interval2 = interval - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
}
