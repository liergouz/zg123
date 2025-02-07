
// ����������  TIPS:[PF_CAST_HIT]  ����

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02117
#define PF_START       "02117"
#define PF_NAME        "����ȭ"

#define SKILL_LEVEL     9
#define TIME_INTERVAL   6
#define SUB_MP        	0
#define SUB_YUAN        2
#define ADD_AP          0

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������9��\n    ʩ�������������߷�Χ��һ��Ŀ�꣬��ͬʱʹ������2����ӻ�״̬��";
        result = sprintf(HIC"%s\n" NOR "��������%d��\nԪ�����ģ�%d��\n��ȴʱ�䣺%d��\n    ʩ�������������߷�Χ��һ��Ŀ�꣬��ͬʱʹ������2����ӻ�״̬��", 
        	PF_NAME, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL);
        return result;	
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int z, d, x0, y0;
        int level, mp, ret,enmity;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

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
	z = get_z(me);
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
		return 1;
	if (get_z(who)!=z) return;
	x0 = get_x(me);
	y0 = get_y(me);
        if( !from_to(z, x0, y0, x - x0, y - y0, MAP_BLOCK ) ) return 0;

        me->set_enemy_2(who);    // Զ��Ŀ������

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );

//      set_heart_state(me, MAGIC_STAT);
//      set_heart_count_2(me, 9);

	if (me->get_gender()==2)
	{
        	if( !CHAR_FIGHT_D->attack_action(me, who, 3070, 10) ) return 1;
        }
        else
	{
        	if( !CHAR_FIGHT_D->attack_action(me, who, 1070, 10) ) return 1;
        }
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );      
        me->set_perform( PF_START, time() );
        

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%d%w%w%d%w%c%c%w%c%c", 0x8a, getoid(me), time2(),
                get_x(me), get_y(me), getoid(who), 21175, 1, OVER_BODY  );
        

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21171, 1, OVER_BODY, PF_ONCE );

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP, 0, 0, 0, 10);    // С��׼�� me

        if ( who && !who->is_die() )
        {
        	enmity = 320 + (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10*120 + ret ;
        	CHAR_FIGHT_D->set_enmity(me,who,enmity);
        }

        me->set_enemy_3(who);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2", 5);
        if (!who) return 1;
        if (who->is_anti_effect()) return 1;
        if ( !who->get("anti_slow") &&  ret>0)
        {
	        if(     get_effect(who, EFFECT_CHAR_SLOW)
	        ||      get_effect(who, EFFECT_CHAR_SLOW_0) ) return 2;    // ִ�гɹ�
                set_effect(who, EFFECT_CHAR_SLOW, 2);
                send_user( who, "%c%w%w%c", 0x81, 9012, get_effect_3(who, EFFECT_CHAR_SLOW), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9012, 1, EFFECT_BAD );
                send_user(who, "%c%c%c", 0x3d, 241, 1);    // ������·����
        }        

        return 1;
}

// ���������⼼����
int cast_done( object me )
{
	object who;
        int level, mp, rate;        
/*
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );      
        me->set_perform( PF_START, time() );
        
        who = me->get_enemy_3();
        if (!who) return 1;
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%d%w%w%d%w%c%c%w%c%c", 0x8a, getoid(me), time2(),
                get_x(me), get_y(me), getoid(who), 21175, 1, OVER_BODY  );
        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;


        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        me->set_perform_file(0);
//      send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21171, 1, OVER_BODY, PF_ONCE );

//      if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�

        CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP, 0, 0, 0, 10);    // С��׼�� me
*/
        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

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
        if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 10, 1, 70, 5, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 10, 3, 70, 5, 0);                
}

int perform_action_npc(object me, object who)
{
        int z, d, x0, y0;
        int level, mp, ret,enmity;

        me->set_enemy_2(who);    // Զ��Ŀ������

        if( !CHAR_FIGHT_D->attack_action(me, who, 3070, 10) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%d%w%w%d%w%c%c%w%c%c", 0x8a, getoid(me), time2(),
                get_x(me), get_y(me), getoid(who), 21175, 1, OVER_BODY  );
        
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21171, 1, OVER_BODY, PF_ONCE );

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP, 0, 0, 0, 10);    // С��׼�� me

        if ( who && !who->is_die() )
        {
        	enmity = 100 + (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10*10 ;
        	CHAR_FIGHT_D->set_enmity(me,who,enmity);
        }
        me->set_enemy_3(who);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        if (!who) return 1;
        if (who->is_anti_effect()) return 1;
        if ( !who->get("anti_slow") &&  ret>0)
        {
	        if(     get_effect(who, EFFECT_CHAR_SLOW)
	        ||      get_effect(who, EFFECT_CHAR_SLOW_0) ) return 2;    // ִ�гɹ�
                set_effect(who, EFFECT_CHAR_SLOW, 2);
                send_user( who, "%c%w%w%c", 0x81, 9012, get_effect_3(who, EFFECT_CHAR_SLOW), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9012, 1, EFFECT_BAD );
                send_user(who, "%c%c%c", 0x3d, 241, 1);    // ������·����
        }        

        return 1;
}