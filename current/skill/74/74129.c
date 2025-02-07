// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#define PF_START       "74129"
#define TIME_INTERVAL   2

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74129; }
// ��������ȡ��������
string get_name() { return "����"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 1; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 0; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��ʹ�ô˼����ڶԵ������\n�����˺���ͬʱ�����˺�ֵ5%����Ѫ��";
}
// ��������ȡָ������
int get_perform_type() { return ON_CHAR_P; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), TIME_INTERVAL, 0, get_name() );
}

//�����ٶ�
int get_attack_speed() { return 12; }

int perform_action_npc( object me, object who )
{
        int level, mp=15;

        if( ( !me->get_skill(get_id()) ) ) return 0;
        if( !inside_screen_2(me, who) ) return 0;
	if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 0;
	if( !who->can_be_fighted(me) || !me->can_fight(who) )	return 0;
        if( me->get_mp() < mp )  return 0;
	if( !CHAR_FIGHT_D->attack_action(me, who) ) return 0; 
        me->add_mp(-mp);
        me->set_perform( PF_START, time() );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( who->get_char_id());
        return 1;
}

int cast_done_npc( object me )
{
	int rate;
	object who;
	string arg;

        send_user( me->get_owner(), "%c%c%d%d%c%w", 0xA1,27,0,get_id(),0xff, 0 );
        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // ִ�гɹ�
	me->set_absorb_hp(5);
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                3252, 1, OVER_BODY, 3252, 1, UNDER_FOOT, PF_ONCE );
	CHAR_FIGHT_D->attack_done(me, who);
	me->set_absorb_hp(0);
        me->set_enemy_3(who);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 7);  
        return 1;
}
