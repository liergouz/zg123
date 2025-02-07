// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74206; }
// ��������ȡ��������
string get_name() { return "�߼�����"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 0; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 1; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��������䵱ǰ������������20%��";
}
// ��������ȡָ������
int get_perform_type() { return 0; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), 1, 0, get_name() );
}
//���ܵ�Ӱ��
void skill_effect(object pet,object owner)
{
	int point;
	if ( pet->get_skill(74115) )
		pet->remove_skill_effect(74115);
	point = pet->get_cp()/5;
	pet->set("sk74206",point);
	NPC_PET_D->count_cp(pet);
}
//ɾ�����ܵ�Ӱ��
void remove_skill_effect(object pet,object owner)
{
	int cp;
	cp = pet->get("sk74206");
	if ( cp )
	{
		pet->delete("sk74206");
		NPC_PET_D->count_cp(pet);
	}
	if ( pet->get_skill(74115) )
		pet->skill_effect(74115);
}
