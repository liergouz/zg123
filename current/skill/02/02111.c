
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02111
#define PF_START       "02111"
#define PF_NAME        "��׳ɽ��"

#define SKILL_LEVEL     5
#define TIME_INTERVAL   6
#define SUB_MP        	0
#define ADD_AP          20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*8
#define ADD_ENMITY	80*yuan + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*30 + ret

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
        	return HIR + PF_NAME +"\n�����������\n    ʩ��ȫ��Ԫ��������֣�ÿ����һ��Ԫ������������20�㡣";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nԪ�����ģ�ȫ��\n��ȴʱ�䣺%d��\n    ʩ��ȫ��Ԫ��������֣�ÿ����һ��Ԫ������������%d�㡣\n" HIC"��һ����\n"NOR"��������"HIR"%d��\n" NOR "    ÿ����һ��Ԫ������%d������������", 
        	PF_NAME, cur_level, SKILL_LEVEL, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 8);
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

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }
        if( me->get_gender()!=1 && !CHAR_FIGHT_D->attack_action(me, who, 1010) ) return 1;
        else
        if( me->get_gender()==1 && !CHAR_FIGHT_D->attack_action(me, who, 2010) ) return 1;
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

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        if( me->get_gender()!=1 && !CHAR_FIGHT_D->attack_action(me, who, 1010) ) return 1;
        else
        if( me->get_gender()==1 && !CHAR_FIGHT_D->attack_action(me, who, 2010) ) return 1;

        me->add_mp(-mp);
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );

        return 2;    // ִ�гɹ�
}

// ���������⼼����
int perform_done( object me, object who )
{
        int level, mp, yuan, rate, ret;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

/*      if( me->get_mp() < ( mp = SUB_MP ) )    // С��׼�� level
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", mp );
                return 1;
        }       */

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        me->set_perform_file(0);
	send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21111, 1, UNDER_FOOT, PF_ONCE );

        yuan = me->get_yuan();
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, (ADD_AP)*yuan );    // С��׼�� me
        me->add_yuan( -yuan );

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);

        return 2;    // ִ�гɹ�
}

// ���������⼼����
int cast_done( object me )
{
        int level, mp, yuan, rate, ret;   
        object who;
        string arg;     

	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;	
        
	send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21111, 1, UNDER_FOOT, PF_ONCE );

        yuan = me->get_yuan();
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, (ADD_AP)*yuan );    // С��׼�� me
        me->add_yuan( -yuan );

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);

        return 2;    // ִ�гɹ�
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_CHAR; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        int interval;
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, PF_NAME );
        if( me->get_gender()==1)
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 2, 10, 5, 0);
        else
        	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 1, 1, 1, 10, 5, 0);
}
