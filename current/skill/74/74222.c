// �����Զ����ɣ�/make/skill/makeski74

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// ���������＼��
int is_pet_skill() { return 1; }
// ��������ȡ����ID
int get_id() { return 74222; }
// ��������ȡ��������
string get_name() { return "����"; }
// ��������ȡ�������ͣ�0��������1��������
int get_type() { return 0; }
// ��������ȡ���ܵȼ���0����ͨ��1���߼���
int get_level() { return 1; }
// ��������ȡ����
string get_desc( object me )
{
	return HIC+get_name()+"\nӵ�д˼��ܵĳ��������ʱ���ܶ������ֱ��2���ڵ��������\n�˺����Խ����һ��������ɵ��˺�Ϊ���������˺���100%���Խ���\n�ڶ���������ɵ��˺�Ϊ���������˺���80%";
}
// ��������ȡָ������
int get_perform_type() { return 0; }

// �������ܷ�ʹ��ָ��
void can_perform( object me ,object pet)
{
        send_user( me, "%c%c%d%d%c%c%w%w%s", 0xA1,19,getoid(pet),get_id(),1, get_perform_type(), 1, 0, get_name() );
}
