// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#define PF_START       "74240"
#define TIME_INTERVAL   15

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74240; }
// ��������ȡ��������
string get_name() { return "������"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 1; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 1; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��ʹ�ü���ʱ���ܴ�����������\n��Χ\n21��21�ڵĹ�ȥ�������ﱾ��������ȴ15�롣";
}
// ��������ȡָ������
int get_perform_type() { return ON_ME_P; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), TIME_INTERVAL, 0, get_name() );
}
//�Ƿ�Զ�̷���
int is_caster() { return 1; }

int perform_action_npc( object me, object who )
{
        int level, mp=50;

        if( ( !me->get_skill(get_id()) ) ) return 0;
	if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 0;
        if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
        if( me->get_mp() < mp )  return 0;
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        me->add_mp(-mp);
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        return 1;
}

int cast_done_npc( object me )
{
	int x,y,z,i,size;
	object who,*char,owner,*target;
	string arg;
	
        send_user( me->get_owner(), "%c%c%d%d%c%w", 0xA1,27,0,get_id(),0xff, 0 );
        me->set_perform( PF_START, time() );
	owner = me->get_owner();
	if( !inside_screen_2(me, owner) ) return 2;
//        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
//                2121, 1, OVER_BODY, 2121, 1, UNDER_FOOT, PF_ONCE );
        z = get_z(owner);  x = get_x(owner);  y = get_y(owner);
        char = get_range_object(z, x, y, 10, CHAR_TYPE) - ({ me });
	target = ({});
	for(i=0,size=sizeof(char);i<size;i++)
	{
		who = char[i];
        	if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
        	target += ({ who });
		who->set("2122", time());
		who->start_fight(me);
		who->set_enemy(me);
		who->follow_user();
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2122, 1, OVER_BODY, PF_ONCE );
	}
        return 2;    // ִ�гɹ�
}



