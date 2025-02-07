
// ���ؼ���  TIPS:[PF_SWITCH]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0251
#define THIS_PERFORM    02514
#define PF_FLAG        "02514"
#define PF_NAME        "��ɨǧ��"

#define SKILL_LEVEL     6
#define TIME_INTERVAL   1
#define SUB_MP          0
#define SUB_YUAN        3
#define ADD_AP		20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 10

int perform_done( object me, object who );

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������6��\n    ��ɨ��Χ�˸���������20�㹥������ͬʱ�Ը÷�Χ�����е�������˺���";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nԪ�����ģ�%d\n��ȴʱ�䣺%d��\n    ��ɨ��Χ�˸���������%d�㹥������ͬʱ�Ը÷�Χ�����е�������˺�����ħ�����ﵽ61����ʹ�ú�ɨǧ����ͬʱ������Χ25��Ŀ�ꡣ\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����%d�㹥������", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 10  );
        return result;	
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;
        if( gone_time( me->get_perform(PF_FLAG) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != STICK ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ������" );
                return 1;
        }
	me->set_perform( PF_FLAG, time() );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        
        me->add_yuan( -SUB_YUAN );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 40, get_d(me), 0 );
	perform_done(me, 0);
        return 1;
}

// ���������⼼����
int perform_done( object me, object who )
{
        object *char;
        int mp, i, size;

	if (me->get_skill(THIS_SKILL)>=61)
        	char = get_range_object_2(me, 2, USER_TYPE) + get_range_object_2(me, 2, CHAR_TYPE) - ({ me });
        else
        	char = get_range_object_2(me, 1, USER_TYPE) + get_range_object_2(me, 1, CHAR_TYPE) - ({ me });

        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] ) 
                {
                	if (!who->can_be_fighted(me) || !me->can_fight(who)) continue;
                	CHAR_FIGHT_D->attack_done(me, who, HIT_STICK, ADD_AP);
		        if ( who && !who->is_die() )
		        	CHAR_FIGHT_D->set_enmity(me,who,80);                	
                }
        return 2;    // ִ�гɹ�
}

// �����������(����)
int perform_action_npc( object me, object who )
{
        if( !CHAR_FIGHT_D->attack_action(me, who, 2040) ) return 0;

        set_heart_state(me, FIGHT_STAT);
        set_heart_count_2(me, 7);
        me->set_perform_2_file(__FILE__);

        return 1;    // ִ�гɹ�
}

// �����������
int perform_done_npc( object me, object who )
{
        object *char;
        int i, size;

        if( distance_between(me, who) > 1 ) return 0;

        me->set_perform_2_file(0);

        char = get_range_object_2(me, 1, USER_TYPE) - ({ me });    // + get_range_object_2(me, 1, CHAR_TYPE)

        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] ) 
                {
                	CHAR_FIGHT_D->attack_done(me, who, HIT_STICK);
		        if ( who && !who->is_die() )
		        	CHAR_FIGHT_D->set_enmity(me,who,80);	
                }
	me->delete_perform(PF_FLAG);
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
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 2, 40, 7, 0);
}
