
// ��������  TIPS:[PF_THROWING]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0261
#define THIS_PERFORM    02615
#define PF_START       "02615"
#define PF_NAME        "�ٲ�����"

#define SKILL_LEVEL     20
#define TIME_INTERVAL   6
#define SUB_MP          10 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 2
#define ADD_DAMAGE     	50 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 40
#define ADD_RATE     	1000 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*100

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������20��\n    ��׼Ŀ�꣬Ͷ������һ�������ж��ֵ�ͬʱ׷��50���˺�������10�������ʡ�";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ��׼Ŀ�꣬Ͷ������һ�������ж��ֵ�ͬʱ׷��%d���˺�������%d�������ʡ�\n" HIC"��һ����\n"NOR"��������"HIR"%d��\n" NOR "    ���ж��ֵ�ͬʱ׷��%d���˺�������%d�������ʡ�", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_DAMAGE, (ADD_RATE)/100, cur_level*10+SKILL_LEVEL, ADD_DAMAGE + 40, (ADD_RATE)/100 + 1);
        return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if( me->get_weapon_code() != THROWING ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��������" );
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
                z = get_z(me);

                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) 
                {
//                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
                        me->set_time( "pf", time() );

	                pf = 64;    // ���� /sys/user/fight

                	if( !( act = pf / 10 ) )    // pf: [�������][��Ӱ���]
                	{
		                pf = 0;  act = 1 + random(3);    // ��ָ��������ţ����
	                }

                        me->to_front_xy(x, y);
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 30, get_d(me), 0 );

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 9);
                        me->add_2("go_count.count2",9);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }
        }

//        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // Զ��Ŀ������

        me->add_mp(-mp);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->add_2("go_count.count2",9);
        set_effect(me, EFFECT_PROGRESS2, 3);
        me->set_progress_file(__FILE__);
        me->set_progress_arg( who->get_char_id());
        me->set_enemy(0);
        send_user(me, "%c", 0x01);
	send_user(me, "%c%c%w%s", 0x5a, 0, 3, "�ٲ�����ʩ���С���");
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int into_effect( object me , string arg)
{
        object who;
        int z, x, y, pf, act;
        int level, rate;
        int interval, sub_effect;
	send_user(me, "%c%c%c", 0x5a, 1, 1);        

        if( !objectp( who = find_char(arg) ) ) return 1;

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 30, get_d(me), getoid(who) );
        
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 26159, 1, OVER_BODY, PF_ONCE );
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 26151, 1, OVER_BODY, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�

	me->set("add_damage", ADD_DAMAGE);
	rate = me->get_double_rate();
	me->set_double_rate(rate+ADD_RATE);
        CHAR_FIGHT_D->throwing_done(me, who, HIT_NONE);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);	

        me->set("add_damage", 0);
        me->set_double_rate(rate);
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
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 9, 0);
}

void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}
