
// ����Զ�̼���  TIPS:[PF_CAST_AREA]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0501
#define THIS_PERFORM    05012
#define PF_START       "05012"
#define PF_TIME        "05012#"
#define PF_NAME        "����ɶ�"

#define SKILL_LEVEL     10
#define TIME_INTERVAL   2
#define SUB_MP          ( 15 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 11 * 20 )
#define ADD_EFFECT      ( 20 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 11 * 20 )

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������10��\n    ���ý���̼�����������15�����ڿ������ѷ�20�㷨����������";
        cur_level = (level - SKILL_LEVEL)/11 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    ���ý���̼�����������15�����ڿ������ѷ�%d�㷨����������\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ���ý���̼�����������15�����ڿ������ѷ�%d�㷨����������",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*11+SKILL_LEVEL, ADD_EFFECT+20 );
	return result;
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_POWERUP2) )
                return sprintf( PF_NAME "��\n�������� %d �㷨����������\n", me->get_save("05012")+me->get("05012") );
        else    return sprintf( PF_NAME "\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z;
        int level, mp;
	object owner;
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
	        if (who!=me)
	        {
	        	if (who->is_user())
	        	{
		        	if (!me->get_leader()||me->get_leader()!=who->get_leader())
			        {
			                printf( ECHO "ֻ�ܶ��Լ����߶���ʹ��" PF_NAME );
			                return 1;
			        }
			}
			else
			{
				owner  = who->get_owner();
				if (owner!=me)
				{
			        	if (!owner || !me->get_leader()||me->get_leader()!=owner->get_leader())
				        {
				                printf( ECHO "ֻ�ܶ��Լ����߶���ʹ��" PF_NAME );
				                return 1;
				        }
				}			       			
			}		 
			if ("/sys/user/attack"->can_use_help(me, who)==0)
			{				
				printf( ECHO "���޷��ԶԷ�ʹ��" PF_NAME );
				return 1;				
			}			     
	        }
                z = get_z(who);  x = get_x(who);  y = get_y(who);
        }
        else
        {
                return 1;
        }
	if (who->is_anti_effect()) return 1;

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg(who->get_char_id());
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int cast_done( object me )
{
        object *char, who;
        string arg;
        int z, x, y;
        int level, level2, interval, effect, i, size;        

        if( !stringp( arg = me->get_cast_arg() ) || !objectp( who = find_char(arg) ) ) return 1;

        char = get_scene_object(z, x, y, USER_TYPE);
        send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 50119, 1, OVER_BODY, PF_ONCE );

        level = me->get_skill(THIS_SKILL);
        interval = 900;    // С��׼�� me
        effect = ADD_EFFECT;    // С��׼�� me
        level2 = who->get_level();
        if (level - 10 - level2>0) effect = effect - (level - 10 - level2)/11*20;
	
        if( get_effect(who, EFFECT_CHAR_POWERUP2) )
        {
        	if (who->is_user() && who->get_save("05012")>effect) return 1;
        	if (who->is_npc() && who->get("05012")>effect) return 1;
        }
        set_effect(who, EFFECT_CHAR_POWERUP2, interval);
        if (who->is_user() )
        {
		who->set_save("05012", effect);
		USER_ENERGY_D->count_cp(who);
	}
	else
        {
        	who->add_cp(-who->get("05012"));
		who->set("05012", effect);
		who->add_cp(effect);
	}	
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 50119, 1, OVER_BODY, PF_ONCE );                
        send_user( who, "%c%w%w%c", 0x81, 5012, get_effect_3(who, EFFECT_CHAR_POWERUP2), EFFECT_GOOD );
        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 5012, 1, EFFECT_GOOD );

	CHAR_FIGHT_D->set_enmity2(me,who,40);
        // Ч���� energy_d.c
        

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
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/11+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0,10, MAGIC_ACT_BEGIN, 0, 5, 0);
}
