
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0271
#define THIS_PERFORM    02711
#define PF_START       "02711"
#define PF_NAME        "��ħ��"

#define SKILL_LEVEL     3
#define TIME_INTERVAL   1
#define SUB_MP          ( 10 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 4 )
#define ADD_AP		( 35 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 15 )


// ��������ȡ����
int get_sub_mp( object me ) 
{ 
        int level = me->get_skill(THIS_SKILL);
        return SUB_MP;    // С��׼�� level
}

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������3��\n    ��ħ֮��������35�㷨������������һ�����߷�Χ��һ��Ŀ������˺���";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ��ħ֮��������%d�㷨������������һ�����߷�Χ��һ��Ŀ������˺���\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ʩ��ʱ����%d�㷨����������", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 15 );
	return result;   
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;
        object * user;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }
        if (!who) return 1;
        me->to_front_xy(get_x(who), get_y(who)); //����me����������.
        user = get_scene_object_2(me, USER_TYPE);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        me->add_mp(-mp);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int cast_done( object me )
{
        object who;
        string arg;
        int z, x, y;
        int level;        
        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                return 1;    // �򵽿յ�
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 27112, 1, OVER_BODY, PF_ONCE );
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�
        CHAR_FIGHT_D->cast_done(me, who, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,40);	

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

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
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 5, 0);

}

int perform_action_npc(object me, object who)
{
	int level;
	object *user;
	
        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if (!who) return 1;
        me->to_front_xy(get_x(who), get_y(who));
        user = get_scene_object_2(me, USER_TYPE);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
        return 1;
}

// ��������������
int cast_done_npc( object me )
{
        object who;
        string arg;
        int z, x, y;
        int level;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 27112, 1, OVER_BODY, PF_ONCE );
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�
        CHAR_FIGHT_D->cast_done(me, who, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,40);	

        return 2;    // ִ�гɹ�
}