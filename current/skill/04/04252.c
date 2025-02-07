
// ���ó�������  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0425
#define THIS_PERFORM    04252
#define PF_START       "04252"
#define PF_TIME        "04252#"
#define PF_NAME        "Ǭ��Ų��"

#define SKILL_LEVEL     10
//#define TIME_INTERVAL   me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 18, 5000)    // ���棺me ��׼����
#define TIME_INTERVAL   15
#define SUB_MP          20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/11*10
#define ADD_INTERVAL    300
#define ADD_EFFECT	100 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/11*200


// ��������ȡ����Ч��
// int get_cast_seal() { return 42100; }    // ��ֽ˳��

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������10��\n    �����������Ѽ������ܵ���100�㹥���˺�ת��Ϊ����������ģ�ÿ��ֹ�����˺����1�㷨����Ч������5���ӡ�";
        cur_level = (level - SKILL_LEVEL)/11 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    �����������Ѽ������ܵ���%d�㹥���˺�ת��Ϊ����������ģ�ÿ��ֹ�����˺����1�㷨����Ч������5���ӡ�\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    �����������Ѽ������ܵ���%d�㹥���˺�ת��Ϊ����������ġ�", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*11+SKILL_LEVEL, ADD_EFFECT + 200 );
        return result;	
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "��\n������������ %d ���˺�������ͬ�ȷ�����\n", me->get_save("pf.miss") );
        else    return sprintf( PF_NAME "\n�����˺�������˫��������\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int level, mp, interval;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

/*      if( !objectp( item = present("��ֽ", me, 1, MAX_CARRY) ) )
        {
                printf( ECHO "�����з�ֽ����ʹ�á�" PF_NAME "����" );
                return 1;
        }       */

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
//      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
//      item->add_amount(-1);
       	CHAR_FIGHT_D->set_enmity1(me,10);
        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // С��׼�� me

        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
//        if (get_effect(me, EFFECT_CHAR_MISS) ) return 2;
        set_effect(me, EFFECT_CHAR_MISS, interval);
        send_user( me, "%c%w%w%c", 0x81, 4252, get_effect_3(me, EFFECT_CHAR_MISS), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 4252, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                42511, 1, OVER_BODY, 42511, 1, OVER_BODY, PF_ONCE );
	me->set_save("pf.miss", ADD_EFFECT);

        return 1;
}

// ��������������
int cast_done( object me )
{
        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int level, interval, interval2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL;    // С��׼�� me
        interval2 = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
}
