
// ����Զ�̼���  TIPS:[PF_CAST]  ����

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0231
#define THIS_PERFORM    02316
#define PF_START       "02316"
#define PF_NAME        "��������"

#define SKILL_LEVEL     45
#define TIME_INTERVAL   6
#define SUB_MP          70 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 10
#define ADD_CP		70 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 15 * 10

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level, size;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������45��\n    �û�Ϊ��������Ӱ������70�㷨����������ͬʱ�����߷�Χ��4��Ŀ������˺���";
        cur_level = (level - SKILL_LEVEL)/15 + 1;
        size = 9 + (level/ 80 )*7;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n�������ģ�%d��\n��ȴʱ�䣺%d��\n    �û�Ϊ��������Ӱ������%d�㷨����������ͬʱ�����߷�Χ��%d��Ŀ������˺���\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ����%d�㷨������������ͬʱ��%d��Ŀ������˺��� ", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_CP, size, cur_level*15+SKILL_LEVEL, ADD_CP + 10,  9 + ((cur_level*15+SKILL_LEVEL)/ 80 )*7 );
        return result;	}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *char, *char2;
        int z, x0, y0, d;
        int level, mp;
        int f1, f2, f3, f4, act, pf;
        int i, size, size2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // С��׼�� me

        if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� me
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) 
        {
        	notify( "�㴦�ڷ�ӡ״̬�С�" );
        	return 1;
        }
        if( me->get_weapon_code() != SWORD ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ������" );
                return 1;
        }

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if (me->get_gender()==2) send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 60, get_d(me), 0 );
        else send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 60, get_d(me), 0 );
        
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 23169, 1, OVER_BODY, PF_ONCE );

        me->add_mp(-mp);

        size = 9 + (level/ 80 )*7;
        size2 = size;

        char = get_range_object(z, x0, y0, 8, USER_TYPE) + get_range_object(z, x0, y0, 8, CHAR_TYPE);    // 7 x 7 ���

        char = char - ({ me }) ;
        char2 = copy(char);
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] )
        {
        	if( !who->can_be_fighted(me) || !me->can_fight(who) )
        		char2 -= ({ who });
        }
	size = sizeof(char2);
	if (size>size2)
	{
		size = size - size2;
		for( i = 0; i < size; i ++ ) char2 -= ({ char2[ random( sizeof(char2) ) ] });
	}

        me->set("pf.02316", char2);
        f1 = me->get_armor_code();  f2 = me->get_head_code();  f3 = me->get_weapon_code_2();  f4 = me->get_reincarnation();
        act = 1;

        for( i = 0, size = sizeof(char2); i < size; i ++ ) if( who = char2[i] )
        {
                x = get_x(who);  y = get_y(who);  d = get_front_xy(x0, y0, x, y);
		send_user( get_scene_object_2(who, USER_TYPE), "%c%w%w%d%w%w%c%d%w%c%c%c", 0x88, x0, y0, time2(), x, y, d, f1, f3, act, f4, 1 );
        }

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
          me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// ��������������
int cast_done( object me )
{
        object *char, who;
        string arg;
        int level, i, size;        

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%d", level) != 1 ) return 1;

        if( !arrayp( char = me->get("pf.02316") ) ) return 2;    // ִ�гɹ�

        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] ) 
                {
                	CHAR_FIGHT_D->cast_done(me, who, ADD_CP);
                        if ( who && !who->is_die() )
        			CHAR_FIGHT_D->set_enmity(me,who,100);	
                }

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
	name = sprintf("%s(%d��)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/15+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
				if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 1, 60, 5, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 2, 60, 5, 0);
}
