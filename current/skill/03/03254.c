
// ���ó�������  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0325
#define THIS_PERFORM    03254
#define PF_START       "03254"
#define PF_TIME        "03254#"
#define PF_NAME        "����֮��"

#define SKILL_LEVEL     30
#define TIME_INTERVAL   60 - ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 3
#define SUB_MP          100 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 20
#define ADD_INTERVAL    12 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 3


// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������30��\n    ����������һ��ʱ���ڣ����л�ʹ�����Ѫֵ����1���µ��˺�������Ϊ�������Ѫֵ�½�Ϊ1��";
        cur_level = (level - SKILL_LEVEL)/15 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ����������%d���ڣ����л�ʹ�����Ѫֵ����1���µ��˺�������Ϊ�������Ѫֵ�½�Ϊ1��\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����֮��ĳ���Ч���ӳ���%d�룬ʹ����ȴʱ�������%d�롣", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_INTERVAL, cur_level*15+SKILL_LEVEL, ADD_INTERVAL + 3, TIME_INTERVAL - 3 );
        return result;    
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "��\n�����ܵ��������˺�������ʹ��Ѫ����1��\n" );
        else    return sprintf( PF_NAME "\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp;
        object *user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // С��׼�� me

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) 
        {
        	notify( "�㴦�ڷ�ӡ״̬�С�" );
        	return 1;
        }
        me->add_mp(-mp);
        CHAR_FIGHT_D->set_enmity1(me,20);
        
        interval = ADD_INTERVAL;    // С��׼�� me

        me->set_perform( PF_START, time() );
        me->set_perform( "03254#",interval);
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect_2(me, EFFECT_CHAR_IMMORTAL, 1, interval);
        send_user( me, "%c%w%w%c", 0x81, 3254, get_effect_3(me, EFFECT_CHAR_IMMORTAL), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3254, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32549, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32540, 1, OVER_BODY, PF_LOOP );

        return 1;
}

// ��������������
int cast_done( object me )
{
        object *user;
        int level, interval;
/*
        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // С��׼�� me

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, interval );

        user = get_scene_object_2(me, USER_TYPE);
        set_effect(me, EFFECT_CHAR_IMMORTAL, interval);
        send_user( me, "%c%w%w%c", 0x81, 3254, get_effect_3(me, EFFECT_CHAR_IMMORTAL), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3254, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32549, 1, OVER_BODY, PF_ONCE );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 32540, 1, OVER_BODY, PF_LOOP );

        // Ч���� energy_d.c
*/
        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/15+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}
