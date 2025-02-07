
// ����������  TIPS:[PF_CAST_HIT]  ����

#include <ansi.h>
#include <action.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0363
#define THIS_PERFORM    03637
#define PF_START       "03637"
#define PF_NAME        "����ɢ��"

#define SKILL_LEVEL     22
#define TIME_INTERVAL   2
#define SUB_MP        	( 40 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/9 * 3 ) 
#define ADD_EFFECT     	( 20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/9 * 10 ) 

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������22��\n    ׷��20�㶾�ԡ����Լ�Ϊ���ĵ�7��7��Χ�ͷŶ���˲���Ⱦ�÷�Χ�����еĵж�Ŀ�꣬�ұ���Ⱦ�ĵ��˻������ӻ�״̬��";
        cur_level = (level - SKILL_LEVEL)/9 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nn�������ģ�%d��\n��ȴʱ�䣺%d��\n    ׷��%d�㶾�ԡ����Լ�Ϊ���ĵ�7��7��Χ�ͷŶ���˲���Ⱦ�÷�Χ�����еĵж�Ŀ�꣬�ұ���Ⱦ�ĵ��˻������ӻ�״̬��\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ׷�Ӷ���%d�㡣", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*9+SKILL_LEVEL, ADD_EFFECT + 10);     	
        return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, i, size, d, x0, y0, poison;
        int level, mp, ret;
        object *char, item,item1;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }
        if( !objectp( item = me->get_equip(HAND_TYPE) ) || !item->is_poison() ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ�����" );
                return 1;
        }
	poison = item->get_poison() + ADD_EFFECT;
        me->add_mp(-mp);
        item->add_amount(-1);
        if( objectp( item1 = me->get_equip(WEAPON_TYPE) ) && item1->get_name()=="�̻��»�" ) 
        	poison += 1000;
	CHAR_FIGHT_D->set_enmity1(me,40);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 3637, 1, OVER_BODY, PF_ONCE );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        z = get_z(me);
        x = get_x(me);
        y = get_y(me);
        char = get_range_object(z, x, y, 3, USER_TYPE) + get_range_object(z, x, y, 3, CHAR_TYPE) - ({ me });
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] )
        {	        
        	if (who->is_anti_effect()) continue;
                if ( random(100) < who->get_anti_poison() ) continue;
		if( who->can_be_fighted(me) && me->can_fight(who) ) 
		{						
                        who->set_poison( poison / 10 );
                        set_effect_2(who, EFFECT_CHAR_POISON, 10, 2);
                        send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD );
                        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
		        if ( who->get("anti_slow") ) continue;
		        if(     get_effect(who, EFFECT_CHAR_SLOW)
		        ||      get_effect(who, EFFECT_CHAR_SLOW_0) ) continue;
	                set_effect(who, EFFECT_CHAR_SLOW, 6);
	                set_effect(who, EFFECT_CHAR_SLOW_0, 8);
	                send_user( who, "%c%w%w%c", 0x81, 9012, get_effect_3(who, EFFECT_CHAR_SLOW), EFFECT_BAD );
	                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9012, 1, EFFECT_BAD );
	                send_user(who, "%c%c%c", 0x3d, 241, 1);    // ������·����                        
		}        	
        }        
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 7);
        me->add_2("go_count.count2",7);

        return 1;
}

// ���������⼼����
int cast_done( object me )
{
	object who;
        int level, mp, rate;

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

        interval = TIME_INTERVAL;    // С��׼�� level
        interval2 = interval - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 7, 0);
}

int perform_action_npc( object me, object who)
{
        int x,y,z, i, size, d, x0, y0, poison;
        int level, mp, ret;
        object *char;

	poison = ADD_EFFECT;
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 3637, 1, OVER_BODY, PF_ONCE );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        z = get_z(me);
        x = get_x(me);
        y = get_y(me);
        char = get_range_object(z, x, y, 10, USER_TYPE) + get_range_object(z, x, y, 10, CHAR_TYPE) - ({ me });
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] )
        {	        
        	if (who->is_anti_effect()) continue;
                if ( random(100) < who->get_anti_poison() ) continue;
		if( who->can_be_fighted(me) && me->can_fight(who) ) 
		{						
                        who->set_poison( poison / 10 );
                        set_effect_2(who, EFFECT_CHAR_POISON, 10, 2);
                        send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD );
                        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
		        if ( who->get("anti_slow") ) continue;
		        if(     get_effect(who, EFFECT_CHAR_SLOW)
		        ||      get_effect(who, EFFECT_CHAR_SLOW_0) ) continue;
	                set_effect(who, EFFECT_CHAR_SLOW, 6);
	                set_effect(who, EFFECT_CHAR_SLOW_0, 8);
	                send_user( who, "%c%w%w%c", 0x81, 9012, get_effect_3(who, EFFECT_CHAR_SLOW), EFFECT_BAD );
	                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9012, 1, EFFECT_BAD );
	                send_user(who, "%c%c%c", 0x3d, 241, 1);    // ������·����                        
		}        	
        }        
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 7);

        return 1;
}

int cast_done_npc( object me )
{
	object who;
        int level, mp, rate;

        return 2;    // ִ�гɹ�
}