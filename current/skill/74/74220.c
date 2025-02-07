// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74220; }
// ��������ȡ��������
string get_name() { return "Ѫ���⻷"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 0; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 1; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ�����䱻�ٻ�����ʱ����������Ѫ������5%��\n���˳��ﱻ�ջػ�����ʱ����������Ѫ���޻ָ�������";
}
// ��������ȡָ������
int get_perform_type() { return 0; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), 1, 0, get_name() );
}
//���ܵ�Ӱ��(�ٻ�)
void show_effect(object pet,object owner)
{
	int point;
	point = owner->get_max_hp()/20;
	pet->set("sk74220",point);
	USER_ENERGY_D->count_max_hp(owner);
}
//ɾ�����ܵ�Ӱ��(�ջ�)
void remove_show_effect(object pet,object owner)
{
	int point;
	point = pet->get("sk74220");
	if ( point )
	{
		pet->delete("sk74220");
		USER_ENERGY_D->count_max_hp(owner);
	}
}
//���ܵ�Ӱ��
void skill_effect(object pet,object owner)
{
	if ( pet->get("show") )
		show_effect(pet,owner);
}
//ɾ�����ܵ�Ӱ��
void remove_skill_effect(object pet,object owner)
{
	if ( pet->get("show") )
		remove_show_effect(pet,owner);
}