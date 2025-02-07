
// ����Զ�̼���  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <action.h>

#define THIS_SKILL      0271
#define THIS_PERFORM    02712
#define PF_START       "02712"
#define PF_NAME        "������"

#define SKILL_LEVEL     25
#define TIME_INTERVAL   2
#define SUB_MP          ( 20 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 15 )
#define ADD_CP          ( 500 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 250 )


// ��������ȡ����Ч��
int get_cast_seal() { return 9103; }    // ��ֽ˳��

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������25��\n    �ٻ���ʦ���״�����ˡ�����6���ڶ���Χ5��5��Χ�����е�����ɷ���������Ϊ500�ķ����˺���";
        cur_level = (level - SKILL_LEVEL)/15 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    �ٻ���ʦ���״�����ˡ�����6���ڶ���Χ5��5��Χ�����е�����ɷ���������Ϊ%d�ķ����˺���\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����6���ڶ����Լ�Ϊ���ĵ�5��5��Χ�����е�����ɷ���������Ϊ%d�ķ����˺���", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_CP, cur_level*15+SKILL_LEVEL, ADD_CP + 250, );
        return result;  
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *user;
        int z;
        int level, mp;


        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );        
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_ONCE );

        me->add_mp(-mp);
        CHAR_FIGHT_D->set_enmity1(me,80);	

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        send_user(me, "%c", 0x01);
        me->set_cast_file(__FILE__);
        return 1;
}

// ��������������
int cast_done( object me )
{
        object *user, who;
        string arg;
        int z, x, y;
        int level, ret;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        set_effect_2(me, EFFECT_PROGRESS, 3, 2);
        me->set_progress_file(__FILE__);
        me->set_enemy(0);        
        send_user(me, "%c%c%w%s", 0x5a, 0, 6, "������ʩ���С���");
        return 2;    // ִ�гɹ�
}


void into_effect(object me, string arg)
{
        object *user, *char, who;
        int z, x, y;
        int level, mp, rate, i, size, count;
	int add, cp;
	add = ADD_CP;
	cp = me->get_cp();
	me->set_cp(add);
        z = get_z(me);  x = get_x(me);  y = get_y(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        char = get_range_object(z, x, y, 2, USER_TYPE) + get_range_object(z, x, y, 2, CHAR_TYPE) - ({ me });
        count = 0;
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
                if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
		count ++;
		if (count<=3)
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                        	25161, 2, OVER_BODY, 25162, 2, OVER_BODY, PF_ONCE );
                CHAR_FIGHT_D->cast_done(me, who);
        }	
	me->set_cp(cp);
	if( !get_effect_3(me, EFFECT_PROGRESS) ) 
	{
		send_user(me, "%c%c%c", 0x5a, 1, 1);
	}
}

void effect_break(object me, string arg)
{
	object who, owner;
	int add, time;
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect_2(me, EFFECT_PROGRESS, 0, 0);	
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
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 5, 0);
}
