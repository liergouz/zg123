
// ����Զ�̼���  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0414
#define THIS_PERFORM    04141
#define PF_START       "04141"
#define PF_TIME        "04141#"
#define PF_NAME        "������"

#define SKILL_LEVEL     50
#define TIME_INTERVAL   60
#define SUB_MP          ( 50 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 20 )
#define ADD_INTERVAL    ( 15 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 2 )

// ��������ȡ����Ч��
int get_cast_seal() { return 9103; }    // ��ֽ����

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������50��\    ���ֵľ����������״������15����ʹ�õ����м����뷨�������ļӱ���";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ���ֵľ����������״������%d����ʹ�õ����м����뷨�������ļӱ���\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����%d����Ŀ��ʹ�õ����м����뷨�������ļӱ���",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_INTERVAL, cur_level*10+SKILL_LEVEL, ADD_INTERVAL + 2 );
	return result;
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( get_effect(me, EFFECT_DOUBLE_USE ) )
                return sprintf( PF_NAME "��\n����ʹ�õ����м����뷨�������ļӱ���" );
        else    return sprintf( PF_NAME "\n" );
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
                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
                        me->set_time( "pf", time() );

                        me->to_front_xy(x, y);
                        user = get_scene_object_2(me, USER_TYPE);
                        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
                        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 5);
                          me->add_2("go_count.count2",5);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );

                        return 1;
                }
        }

        if( me == who )
        {
                printf( ECHO "���ܶ��Լ�ʹ�á�" PF_NAME "����" );
                return 1;
        }
        if( who->is_npc() )
        {
                printf( ECHO "���ܶ�NPCʹ�á�" PF_NAME "����" );
                return 1;
        }        
        if( !who->can_be_fighted(me) || !me->can_fight(who) )
        {
                printf( ECHO "ֻ�ܶԵз�ʹ�á�" PF_NAME "����" );
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // Զ��Ŀ������

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
         me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );

        return 1;
}

// ��������������
int cast_done( object me )
{
        object *user, who;
        string arg;
        int z, x, y;
        int level, ret, flag=0;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                send_user( get_scene_object(z, x, y, USER_TYPE), "%c%w%w%w%c%c%w%c%c%c", 0x4f, x, y, 
                        41451, 1, OVER_BODY, 41452, 1, OVER_BODY, PF_ONCE );

                return 1;    // �򵽿յ�
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                4148, 1, OVER_BODY, 4148, 1, OVER_BODY, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ����Ϊ����Ч����

        if( get_effect(who, EFFECT_DOUBLE_USE) ) 
        {   	
        	return 2;   
        }
        
        if (who->get("pf.double")>level) 
        {  	
        	return 2;
        }
	ret = CHAR_FIGHT_D->cast_done(me, who, 0, -100); 
	if (!who) return 2;
	if (who->is_anti_effect()) return 2;
	if (who->get("anti_curse")) return 2;
        if( ret > 0 )
        {
                level = me->get_skill(THIS_SKILL);
                who->set("pf.double", level);    // С��׼�� me
                if (who->is_user()) who->set_save_2("pf.double", level);
                set_effect(who, EFFECT_DOUBLE_USE, ADD_INTERVAL);    // С��׼�� me
                send_user( who, "%c%w%w%c", 0x81, 4141, get_effect_3(who, EFFECT_DOUBLE_USE), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 4141, 1, EFFECT_BAD );
        }

        return 2;    // ִ�гɹ�
}

void into_effect( object me ) 
{
        send_user( me, "%c%w%w%c", 0x81, 4141, 0, EFFECT_BAD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 4141, 0, EFFECT_BAD );
        me->set("pf.double", 0);
        me->set_save_2("pf.double", 0);
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
