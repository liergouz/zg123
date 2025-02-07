
// �ٻ�����  TIPS:[PF_CALL]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0414
#define THIS_PERFORM    04147
#define PF_START       "04147"
#define PF_NAME        "������ʩ"

#define TIME_INTERVAL	2
#define SKILL_LEVEL     3
#define SUB_HP          ( 30 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 34 )


// ��������ȡ����Ч��
int get_cast_seal() { return 9103; }    // ��ֽ����

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������3��\n    ���Լ�30�����Ѫת��Ϊ45�㷨������";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d��)\n" NOR "��������%d��\n��Ѫ���ģ�%d��\n��ȴʱ�䣺%d��\n    ���Լ�%d�����Ѫת��Ϊ%d��ķ�������\n" HIC"��һ����\n"NOR"��������" HIR "%d��" NOR"\n    ���Լ�%d�����Ѫת��Ϊ%d��ķ�������",
        	PF_NAME, cur_level, 
        	SKILL_LEVEL, SUB_HP, 2, SUB_HP, SUB_HP*12/10,
        	cur_level*10+SKILL_LEVEL, SUB_HP + 34, (SUB_HP + 34)*12/10 );
	return result;
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
	object * user, soldier, * zombie;
	int flag = 0;
	int i, size, hp;
	if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;
        if( me->get_hp() < ( hp = SUB_HP ) )    // С��׼�� me
        {
                printf( ECHO "�����Ѫ���㣬�޷�ʹ�÷�����" PF_NAME "����" );
                return 1;
        }	
	
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // ���г��У������ʹ��
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), 4147, 1, OVER_BODY, PF_ONCE );
        me->add_hp(-hp);
        me->add_mp(hp*12/10);
	me->set_perform( PF_START, time() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
	CHAR_FIGHT_D->set_enmity1(me,20);
        return 1;
}

// ��������������
int cast_done( object me )
{
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

        interval = TIME_INTERVAL;    // С��׼�� me
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );

}
