
// ��������  TIPS:[PF_THROWING]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0222
#define THIS_PERFORM    02222
#define PF_START       "02222"
#define PF_NAME        "������"

#define SKILL_LEVEL     15
#define TIME_INTERVAL   10
#define SUB_MP          80

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������15��\n    ��ɽ���е����߷������ɱ����Լ���������ѣ��״̬���ڴ�Ч�����޷�����������\n    �ٴ�ʹ���������ɽ����Ч����\n";
        result = sprintf(HIC"%s\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ��ɽ���е����߷������ɱ����Լ���������ѣ��״̬���ڴ�Ч�����޷�����������\n    �ٴ�ʹ���������ɽ����Ч����\n", 
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL);
        return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me
	
	if ( me->get_perform("02222#"))
	{		
		me->set_perform(PF_START, time() );
		send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
		me->set_perform("02222#", 0);
        	send_user( me, "%c%w%w%c", 0x81, 2222, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2222, 0, EFFECT_GOOD );				
		printf( ECHO "��ȡ���ˡ�" PF_NAME "����" );
		return 1;		
	}
        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }


//        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        me->add_mp(-mp);
        set_effect(me, EFFECT_PROGRESS2, 4);
        me->set_progress_file(__FILE__);
        me->set_enemy(0);
        send_user(me, "%c", 0x01);
	send_user(me, "%c%c%w%s", 0x5a, 0, 3, "������ʩ���С���");
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int into_effect( object me , string arg)
{
        int z, x, y, pf, act;
        int level, rate;
        int interval, sub_effect;
	//ȡ���ȶ�����
        if ( me->get_perform("02221#"))
	{
		me->set_perform("02221#", 0);
        	send_user( me, "%c%w%w%c", 0x81, 2221, 0, EFFECT_GOOD );
        	send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2221, 0, EFFECT_GOOD );
	}
	send_user(me, "%c%c%c", 0x5a, 1, 1);        
	me->set_perform("02222#", time() );
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me),
                3292, 1, OVER_BODY, PF_ONCE );        
        send_user( me, "%c%w%w%c", 0x81, 2222, 30000, EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2222, 1, EFFECT_GOOD);	
        return 2;    // ִ�гɹ�
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        return PF_NAME "��\n���������Լ���������ѣ��״̬��\n";
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
	name = PF_NAME;
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
}

void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}
