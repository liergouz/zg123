
// ������  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02110
#define PF_START       "02110"
#define PF_NAME        "�ڻ�����"

#define SKILL_LEVEL     1
#define TIME_INTERVAL   1
#define SUB_MP          0
#define SUB_YUAN        1
#define ADD_AP          20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*8
#define ADD_ENMITY	240 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*80 + ret

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// ��������ȡ����
int get_sub_mp( object me ) { return SUB_MP; }

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n�����������\n    ����ȭ������������������������";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\nԪ�����ģ�%d��\n��ȴʱ�䣺%d��\n    ����ȭ����������������%d�㹥������\n" HIC"��һ����\n"NOR"��������"HIR"%d��\n" NOR "    ������%d�㹥������", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*10+SKILL_LEVEL, ADD_AP + 8);
        return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN);
                return 1;
        }        
        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }
	if( !CHAR_FIGHT_D->attack_action(me, who, 19) ) return 1;
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
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", SUB_MP );
                return 1;
        }
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN);
                return 1;
        }
        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        if( !CHAR_FIGHT_D->attack_action(me, who, 19) ) return 1;        

        me->add_mp( -SUB_MP );
	me->add_yuan( -SUB_YUAN );
	me->set_perform( PF_START, time() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        return 2;    // ִ�гɹ�
}

// ���������⼼����
int perform_done( object me, object who )
{
        int level, ret;        

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

/*      if( me->get_mp() < SUB_MP ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d �㷨����", SUB_MP );
                return 1;
        }       */

        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "ʹ�á�" PF_NAME "����װ��ȭ�ס�" );
                return 1;
        }

        me->set_perform_file(0);
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);    // С��׼�� me
        
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);        

        return 2;    // ִ�гɹ�
}


// ���������⼼����
int cast_done( object me )
{
        int level, ret;     
        object who;
        string arg;   
	if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if( !objectp( who = find_char(arg) ) ) return 1;
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP );    // ɾ������

        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, ADD_AP);    // С��׼�� me
        
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
        send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 1, 9, 5, 0);
}
