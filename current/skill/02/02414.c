
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <cmd.h>

#define THIS_SKILL      0241
#define THIS_PERFORM    02414
#define PF_START       "02414"
#define PF_NAME        "ֱ������"

#define SKILL_LEVEL     17
#define TIME_INTERVAL   2
#define SUB_MP          0
#define SUB_YUAN        2
#define ADD_TIME        6 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 2
#define ADD_AP		30 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10 * 25


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
        	return HIR + PF_NAME +"\n��������17��\n    ����һ��������30�㹥������˲�䴩�̵��ˣ�����ʹ��������6��ĸ���״̬��";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nԪ�����ģ�%d\n��ȴʱ�䣺%d��\n    ����һ��������%d�㹥������˲�䴩�̵��ˣ�����ʹ��������%d��ĸ���״̬��\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ������%d�㹥�������Ҹ��˵ĳ���ʱ���ӳ���%d�롣", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, ADD_TIME, cur_level*10+SKILL_LEVEL, ADD_AP + 25, ADD_TIME + 2 );
        return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ǹ��" );
                return 1;
        }
	if( !CHAR_FIGHT_D->attack_action(me, who, 1040) ) return 1;
	me->add_yuan( -SUB_YUAN );
	set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
         me->add_2("go_count.count2",5);        
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s", who->get_char_id() ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );	
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP );

        return 1;
}

// ���������⼼����(����)
int perform_action( object me, object who )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }

        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }

        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ǹ��" );
                return 1;
        }

        if( !CHAR_FIGHT_D->attack_action(me, who, 1040) ) return 1;

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 2;    // ִ�гɹ�
}

// ���������⼼����
int perform_done( object me, object who )
{
        object *user;
        int z0, x0, y0, x, y, d;
        int level, mp, ret;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

/*      if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }       */

/*      if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }       */

        if( me->get_weapon_code() != SPEAR ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ǹ��" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

//      send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 24111, 1, OVER_BODY, PF_ONCE );

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        switch( d = me->to_front_xy( get_x(who), get_y(who) ) )    // ��͸����
        {
       case 1 : x = x0 + 2;  y = y0;      break;
       case 2 : x = x0 + 2;  y = y0 - 2;  break;
      default : x = x0;      y = y0 - 2;  break;
       case 4 : x = x0 - 2;  y = y0 - 2;  break;
       case 5 : x = x0 - 2;  y = y0;      break;
       case 6 : x = x0 - 2;  y = y0 + 2;  break;
       case 7 : x = x0;      y = y0 + 2;  break;
       case 8 : x = x0 + 2;  y = y0 + 2;  break;
        }
/*
        if( inside_map(z0, x, y) && !( get_block(z0, x, y) & IS_CHAR_BLOCK ) )    // ����Ϸ������Դ�͸
        {
                GO_CMD->main_fly(me, x, y, d, 1);
        }
*/        
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2414, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_SPEAR, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);	

        if( !who ) return 2;    // ִ�гɹ�
	if (who->is_anti_effect()) return 2;
        if (who->get("anti_wound")) return 2;
        if(     get_effect(who, EFFECT_CHAR_WOUND)
        ||      get_effect(who, EFFECT_CHAR_WOUND_0) ) return 2;    // ִ�гɹ�

        if( ret > 0 ) 
        {
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_WOUND, ADD_TIME);
                send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9020, 1, EFFECT_BAD );
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9020, 1, OVER_BODY, PF_LOOP );
		if (who->is_user())
		{
	                USER_ENERGY_D->count_ap(who);
        	        USER_ENERGY_D->count_dp(who);
		}        	       
        }
        return 2;    // ִ�гɹ�
}

// ���������⼼����
int cast_done( object me )
{
        object *user;
        int z0, x0, y0, x, y, d;
        int level, mp, ret;        
        object who;
        string arg;     

	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

//      send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 24111, 1, OVER_BODY, PF_ONCE );

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        switch( d = me->to_front_xy( get_x(who), get_y(who) ) )    // ��͸����
        {
       case 1 : x = x0 + 2;  y = y0;      break;
       case 2 : x = x0 + 2;  y = y0 - 2;  break;
      default : x = x0;      y = y0 - 2;  break;
       case 4 : x = x0 - 2;  y = y0 - 2;  break;
       case 5 : x = x0 - 2;  y = y0;      break;
       case 6 : x = x0 - 2;  y = y0 + 2;  break;
       case 7 : x = x0;      y = y0 + 2;  break;
       case 8 : x = x0 + 2;  y = y0 + 2;  break;
        }
/*
        if( inside_map(z0, x, y) && !( get_block(z0, x, y) & IS_CHAR_BLOCK ) )    // ����Ϸ������Դ�͸
        {
                GO_CMD->main_fly(me, x, y, d, 1);
        }
*/        
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2414, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_SPEAR, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);	

        if( !who ) return 2;    // ִ�гɹ�
	if (who->is_anti_effect()) return 2;
        if (who->get("anti_wound")) return 2;
        if(     get_effect(who, EFFECT_CHAR_WOUND)
        ||      get_effect(who, EFFECT_CHAR_WOUND_0) ) return 2;    // ִ�гɹ�

        if( ret > 0 ) 
        {
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_WOUND, ADD_TIME);
                send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9020, 1, EFFECT_BAD );
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9020, 1, OVER_BODY, PF_LOOP );
		if (who->is_user())
		{
	                USER_ENERGY_D->count_ap(who);
        	        USER_ENERGY_D->count_dp(who);
		}        	       
        }
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
				send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 40, 5, 0);
}

// �����������
int perform_action_npc( object me, object who )
{
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        me->set_perform_enable_time( time() );
        USER_SKILL_D->cancel_enabled_perform( me, __FILE__ );
        me->set_perform_file(__FILE__);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP );
        if( !CHAR_FIGHT_D->attack_action(me, who, 1040) ) return 1;
        return 1;
}

// ���������⼼����
int perform_done_npc( object me, object who )
{
        object *user;
        int z0, x0, y0, x, y, d;
        int level, mp, ret;

        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        switch( d = me->to_front_xy( get_x(who), get_y(who) ) )    // ��͸����
        {
       case 1 : x = x0 + 2;  y = y0;      break;
       case 2 : x = x0 + 2;  y = y0 - 2;  break;
      default : x = x0;      y = y0 - 2;  break;
       case 4 : x = x0 - 2;  y = y0 - 2;  break;
       case 5 : x = x0 - 2;  y = y0;      break;
       case 6 : x = x0 - 2;  y = y0 + 2;  break;
       case 7 : x = x0;      y = y0 + 2;  break;
       case 8 : x = x0 + 2;  y = y0 + 2;  break;
        }

	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2414, 1, OVER_BODY, PF_ONCE );
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_SPEAR, ADD_AP);    // С��׼�� me
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);	
        if( !who ) return 2;    // ִ�гɹ�
	if (who->is_anti_effect()) return 2;
        if (who->get("anti_wound")) return 2;
        if(     get_effect(who, EFFECT_CHAR_WOUND)
        ||      get_effect(who, EFFECT_CHAR_WOUND_0) ) return 2;    // ִ�гɹ�

        if( ret > 0 ) 
        {
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_WOUND, ADD_TIME);
                send_user( who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9020, 1, EFFECT_BAD );
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9020, 1, OVER_BODY, PF_LOOP );
		if (who->is_user())
		{
	                USER_ENERGY_D->count_ap(who);
        	        USER_ENERGY_D->count_dp(who);
		}        	       
        }
        return 2;    // ִ�гɹ�
}