
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0231
#define THIS_PERFORM    02311
#define PF_START       "02311"
#define PF_NAME        "����ָ·"

#define SKILL_LEVEL     1
#define TIME_INTERVAL   1
#define SUB_MP          ( 10 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 4 )
#define ADD_AP          ( 30 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 18 )

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

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
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������5��\n    �ͷŽ��������������������������߷�Χ��һ��Ŀ������˺���";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    �ͷŽ���������%d�㷨���������������߷�Χ��һ��Ŀ������˺���\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����ʱ����%d�㷨����������", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 18);
        return result;	
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( time() - me->get_perform(PF_START) < TIME_INTERVAL  ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }
        if( me->get_weapon_code() != SWORD ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ������" );
                return 1;
        }        
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) 
        {
        	notify( "�㴦�ڷ�ӡ״̬�С�" );
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
                        me->to_front_xy(x, y);
                        user = get_scene_object_2(me, USER_TYPE);
                        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), ATTACK_ACT );
//                      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);
//                      item->add_amount(-1);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 6);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );
			send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        		me->set_perform( PF_START, time() );
                        return 1;
                }
        }     
        me->set_enemy_2(who);    // Զ��Ŀ������

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        if (me->get_gender()==2) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 10, get_d(me), 0 );
        else send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 10, get_d(me), 0 );

        me->add_mp(-mp);
//      item->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 6);
          me->add_2("go_count.count2",6);
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

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 23121, 1, OVER_BODY, PF_ONCE );
        CHAR_FIGHT_D->cast_done(me, who, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,50);
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
				if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 10, 1, 10, 6, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 10, 2, 10, 6, 0);
}
