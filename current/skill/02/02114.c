
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02114
#define PF_START       "02114"
#define PF_NAME        "���������"

#define SKILL_LEVEL     34
#define TIME_INTERVAL   40 - (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/16*2
#define SUB_MP        	0
#define SUB_YUAN        4
#define ADD_AP          0
#define SUB_EFFECT	(30 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/16*20)
#define ADD_ENMITY	900 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/16*350 + ret

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
        	return HIR + PF_NAME +"\n��������34��\n    �������������ʹ������8�����޷�װ��ʹ���������Թ���ʹ���ܼ�����30������������";
        cur_level = (level - SKILL_LEVEL)/16 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nԪ�����ģ�%d��\n��ȴʱ�䣺%d��\n    �������������ʹ������8�����޷�װ��ʹ���������Թ���ʹ���ܼ�����%d������������\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ʹ����ȴʱ�������%d�롣�Թ���ʹ���ܼ�����%d������������", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, SUB_EFFECT, cur_level*16+SKILL_LEVEL, TIME_INTERVAL -2, SUB_EFFECT+20 );
	return result;   
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        int level, mp;

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
        if( me->get_gender()!=1 && !CHAR_FIGHT_D->attack_action(me, who, 1040) ) return 1;
        else
        if( me->get_gender()==1 && !CHAR_FIGHT_D->attack_action(me, who, 2040) ) return 1;
	me->add_yuan( -SUB_YUAN );
	set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2", 5);
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

//        if( !who->is_user() ) return 1;    // ֻ�������Ч

        if( me->get_gender()!=1 && !CHAR_FIGHT_D->attack_action(me, who, 1040) ) return 1;
        else
        if( me->get_gender()==1 && !CHAR_FIGHT_D->attack_action(me, who, 2040) ) return 1;

        me->add_mp(-mp);
        me->add_yuan( -SUB_YUAN );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 2;    // ִ�гɹ�
}

// ���������⼼����
int perform_done( object me, object who )
{
        object *user, item;
        int level, mp, ret, time;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� level

/*      if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }       */

/*      if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }       */

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

//        if( !who->is_user() ) return 1;    // ֻ�������Ч

        me->set_perform_file(0);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 21149, 1, OVER_BODY, PF_ONCE );

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);    // С��׼�� me

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);

        if( !who ) return 2;    // ִ�гɹ�
	if (who->is_anti_effect()) return 2;
        if( get_effect(who, EFFECT_NO_WEAPON) ) return 2;  
        if ( who->get_2("suit_effect.no_drop") ) return 2;  //��װ           
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21141, 1, OVER_BODY, PF_ONCE );    // ���ܳɹ�
        if( ret >0 )
        {                
                
                time = 8;
                set_effect(who, EFFECT_NO_WEAPON, time);  
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( who, "%c%w%w%c", 0x81, 2114, time, EFFECT_BAD );
                if (who->is_user())
                {
                	USER_ENERGY_D->count_all_prop(who);
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
                }
                else
                {
                	who->set("02114", SUB_EFFECT);
                	who->add_ap(-SUB_EFFECT);
                }
                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
        }
        return 2;    // ִ�гɹ�
}

// ���������⼼����
int cast_done( object me )
{
        object *user, item;
        int level, mp, ret, time;        
        object who;
        string arg;           

	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;

        me->set_perform_file(0);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 21149, 1, OVER_BODY, PF_ONCE );

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);    // С��׼�� me

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);

        if( !who ) return 2;    // ִ�гɹ�
	if (who->is_anti_effect()) return 2;
        if( get_effect(who, EFFECT_NO_WEAPON) ) return 2;  
        if ( who->get_2("suit_effect.no_drop") ) return 2;  //��װ           
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21141, 1, OVER_BODY, PF_ONCE );    // ���ܳɹ�
        if( ret >0 )
        {                
                
                time = 8;
                set_effect(who, EFFECT_NO_WEAPON, time);  
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( who, "%c%w%w%c", 0x81, 2114, time, EFFECT_BAD );
                if (who->is_user())
                {
                	USER_ENERGY_D->count_all_prop(who);
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
                }
                else
                {
                	who->set("02114", SUB_EFFECT);
                	who->add_ap(-SUB_EFFECT);
                }
                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
        }
        return 2;    // ִ�гɹ�
}

// �����������(����)
int perform_action_npc( object me, object who )
{
//        if( !who->is_user() ) return 0;    // ֻ�������Ч

        if( !CHAR_FIGHT_D->attack_action(me, who, 24) ) return 0;
        if ( who->get_2("suit_effect.no_drop") ) return 0;  //��װ
        set_heart_state(me, FIGHT_STAT);
        set_heart_count_2(me, 7);
        me->set_perform_file(__FILE__);

        return 1;    // ִ�гɹ�
}

// �����������
int perform_done_npc( object me, object who )
{
        object item;
        int level, ret, time;

//        if( !who->is_user() ) return 1;    // ֻ�������Ч

        me->set_perform_file(0);

        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21145, 1, OVER_BODY, PF_ONCE );

        level = me->get_skill(THIS_SKILL);

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);    // С��׼�� me

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,140);
        	
        if( !who ) return 2;    // ִ�гɹ�
        if (who->is_anti_effect()) return 2;
        if( get_effect(who, EFFECT_NO_WEAPON) ) return 2;                   

	if (ret>0)
        {
                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21141, 1, OVER_BODY, PF_ONCE );    // ���ܳɹ�
                time = 5;
                set_effect(who, EFFECT_NO_WEAPON, time);  
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( who, "%c%w%w%c", 0x81, 2114, time, EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 2114, 1, EFFECT_BAD );
                if (who->is_user())
                {
                	USER_ENERGY_D->count_all_prop(who);
                	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED );    
                }
                else
                {
                	who->set("02114", SUB_EFFECT);
                	who->add_ap(-SUB_EFFECT);
                }
        }
        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

// �������ܷ�ʹ���ؼ�
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
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/16+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
        if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 2, 40, 5, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 40, 5, 0);        
}

void into_effect( object me )
{
	if (me->is_user())
	{
		CHAR_CHAR_D->init_loop_perform(me);
        	USER_ENERGY_D->count_all_prop(me);
        	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w", 0x7c, getoid(me), me->get_weapon_code_2() );      
        	send_user( me, "%c%w%w%c", 0x81, 2114, 0, EFFECT_BAD );
        }
        else
        {                	
                me->add_ap(me->get("02114"));       
                me->set("02114", 0); 	
        }
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 2114, 0, EFFECT_BAD );
        
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "��\n����������ӡ״̬��\n" );
        else    return sprintf( PF_NAME "\n" );
}