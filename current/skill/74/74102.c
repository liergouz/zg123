// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74102; }
// ��������ȡ��������
string get_name() { return "����"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 0; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 0; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ�������䵱ǰ����������5%��";
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
	int pp;
	if ( pet->get_skill(74202) )
		return ;
	pp = pet->get_pp()/20;
	pet->set("sk74102",pp);
	NPC_PET_D->count_pp(pet);
}
//ɾ�����ܵ�Ӱ��
void remove_skill_effect(object pet,object owner)
{
	int pp;
	pp = pet->get("sk74102");
	if ( pp )
	{
		pet->delete("sk74102");
		NPC_PET_D->count_pp(pet);
	}
}