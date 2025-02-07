
// ���ؼ���  TIPS:[PF_SWITCH]
#include <effect.h>
#include <ansi.h>
#include <skill.h>

#define THIS_SKILL      0319
#define THIS_PERFORM    03192
#define PF_FLAG        "03192"
#define PF_NAME        "���"

#define SKILL_LEVEL     30
#define SUB_YUAN        12
#define TIME_INTERVAL   2

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n��������30��\n    �ٻ���Ȼ����������壬�Լ��������״̬������35��������������������������������½�50��������״̬�£��޷������κ�װ����";
        result = sprintf(HIC"%s\n" NOR "��������%d��\nԪ�����ģ�%d��\n��ȴʱ�䣺%d��\n    �ٻ���Ȼ����������壬�Լ��������״̬������35��������������������������������½�50��������״̬�£��޷������κ�װ����\n    �ٴ�ʹ�ü��ܿɻ�ԭΪ����״̬��\n", 
        	PF_NAME, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL);
        return result;
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_FLAG) )
                return sprintf( "��գ�\n��������35������������������������������½�50����\n" );
        else    return sprintf( "���\n" );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{	
	int enmity;
	if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;
        if( me->get_perform(PF_FLAG) )    // �ر�
        {
        	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 0, get_d(me), 0 );
	        set_effect(me, EFFECT_PROGRESS2, 10);
	        me->set_progress_file(__FILE__);
		send_user(me, "%c%c%w%s", 0x5a, 0, 10, "��չر��С���");        	
		return 1;
        }        
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "ʹ�á�" PF_NAME "����Ҫ %d ��Ԫ����", SUB_YUAN );
                return 1;
        }        
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 0, get_d(me), 0 );
	me->add_yuan( -SUB_YUAN );
	set_effect(me, EFFECT_PROGRESS2, 10);
	me->set_progress_file(__FILE__);
	send_user(me, "%c%c%w%s", 0x5a, 0, 10, "����ͷ��С���");        	
	enmity = 60 + (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/30*50 ;
	CHAR_FIGHT_D->set_enmity1(me,enmity); 
	return 1;	
}

// ��������������
int into_effect( object me , string arg)
{
	if( me->get_perform(PF_FLAG) )    // �ر�
	{
		me->delete_perform(PF_FLAG);
		send_user(me, "%c%c%c", 0x5a, 1, 1);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_dp(me);
	        send_user( me, "%c%w%w%c", 0x81, 3192, 0, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3192, 0, EFFECT_GOOD );
		
	}
	else
	{
		me->set_perform(PF_FLAG, 1);
		me->set_perform("03191", 0);
		send_user(me, "%c%c%c", 0x5a, 1, 1);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_dp(me);	
	        send_user( me, "%c%w%w%c", 0x81, 3192, 30000, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3192, 1, EFFECT_GOOD );		
	        send_user( me, "%c%w%w%c", 0x81, 3191, 0, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3191, 0, EFFECT_GOOD );
	        
	}
}

void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, TIME_INTERVAL, 0, PF_NAME );
                return;
        }	
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
}
