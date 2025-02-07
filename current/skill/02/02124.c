
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <action.h>

#define THIS_SKILL      0212
#define THIS_PERFORM    02124
#define PF_START       "02124"
#define PF_NAME        "����"

#define SKILL_LEVEL     20
#define TIME_INTERVAL   4
#define SUB_MP        	0
#define SUB_YUAN        6

// ��������ȡ����
int get_sub_mp( object me ) 
{ 
        int level = me->get_skill(THIS_SKILL);
        return SUB_MP; 
}

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������20��\n    ��������100���ı����˺���";
        result = sprintf(HIC"%s\n" NOR "��������%d��\nԪ�����ģ�%d��\n��ȴʱ�䣺%d��\n    ��������100���ı����˺���", 
        	PF_NAME, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL);
        return result;		
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;
        object *user;
        int ret, rate,enmity;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 9, 0, get_d(me), getoid(who) );    // 9: ʩ������

        who = me->get_enemy();
        if (!who) return 1;
        if( !CHAR_FIGHT_D->attack_action(me, who, 1) ) return 1;  
        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );  
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2124, 1, OVER_BODY, PF_ONCE );    
        rate = me->get_double_rate();
        me->set_double_rate(10000);    
        ret = CHAR_FIGHT_D->attack_done(me, who);
        if ( who && !who->is_die() )
        {
        	enmity = 540 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/20*300 + ret;
        	CHAR_FIGHT_D->set_enmity(me,who,enmity);
        }
        me->set_double_rate(rate);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9); 
        me->add_2("go_count_count2",9);       
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );                      
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
        int interval;
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }       
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
				send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 1, 9, 0);
}
