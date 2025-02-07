// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#define PF_START       "74136"
#define TIME_INTERVAL   2

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74136; }
// ��������ȡ��������
string get_name() { return "ȼ��"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 1; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 0; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��ʹ�ô˼��ܹ����Է�ʱ��15%�ļ���ʹ�Է�\n���ڷ���״̬20�룬ÿ2���н�����Ѫ10�㣬����Ч�������ӡ�";
}
// ��������ȡָ������
int get_perform_type() { return ON_CHAR_P; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), TIME_INTERVAL, 0, get_name() );
}
//�Ƿ�Զ�̷���
int is_caster() { return 1; }

int perform_action_npc( object me, object who )
{
        int level, mp=15;

        if( ( !me->get_skill(get_id()) ) ) return 0;
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
	if( !inside_screen_2(me, who) ) return 0;
	if( !who->can_be_fighted(me) || !me->can_fight(who) )	return 0;
	if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 2;
        if( me->get_mp() < mp )  return 0;
        me->to_front_xy(get_x(who), get_y(who));
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        me->add_mp(-mp);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( who->get_char_id());
        return 1;
}

int cast_done_npc( object me )
{
	int rate;
	object who,*user;
	string arg;
	
        send_user( me->get_owner(), "%c%c%d%d%c%w", 0xA1,27,0,get_id(),0xff, 0 );
        me->set_perform( PF_START, time() );
        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�
	user = get_scene_object_2(who, USER_TYPE);
	if( get_effect_3(who, EFFECT_USER_BURN) && who->get_save("pf.burn")>=10 ) 
		return 2;
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9026, 1, OVER_BODY, PF_ONCE );	        
        rate = 15;
        rate -= who->get_immunity();
        if( get_effect(me, EFFECT_CHAR_BLIND) ) rate /= 2;    // ʧ��(���м���)
	if ( random(100) > rate )
		return 2;
	who->set_save("pf.burn",10);
        set_effect_2(who, EFFECT_USER_BURN, 10, 2);    
        CHAR_CHAR_D->init_loop_perform(who);
        send_user( who, "%c%w%w%c", 0x81, 9026, get_effect_3(who, EFFECT_USER_BURN), EFFECT_BAD );
        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9026, 1, EFFECT_BAD );
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9026, 1, OVER_BODY, PF_LOOP );	        
        return 2;    // ִ�гɹ�
}

