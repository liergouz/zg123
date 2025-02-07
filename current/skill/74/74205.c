// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74205; }
// ��������ȡ��������
string get_name() { return "�߼�ǿ��"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 0; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 1; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��������䵱ǰ����������20%��";
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
	if ( pet->get_skill(74114) )
		pet->remove_skill_effect(74114);
	point = pet->get_ap()/5;
	pet->set("sk74205",point);
	NPC_PET_D->count_ap(pet);
}
//ɾ�����ܵ�Ӱ��
void remove_skill_effect(object pet,object owner)
{
	int ap;
	ap = pet->get("sk74205");
	if ( ap )
	{
		pet->delete("sk74205");
		NPC_PET_D->count_ap(pet);
	}
	if ( pet->get_skill(74114) )
		pet->skill_effect(74114);	
}