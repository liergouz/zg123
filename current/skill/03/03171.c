
// ��������  TIPS:[PF_NONE]

#include <ansi.h>
#include <skill.h>

#define THIS_SKILL      0317
#define THIS_PERFORM    03171
#define PF_START       "03171"
#define PF_NAME        "����"

#define SKILL_LEVEL     5

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// ��������ȡ����
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "��" PF_NAME "�ݱ������ܣ��ۻ��㹻���������˺�֮���Զ�����һ����Ԫ������%s%d ������\n",
                level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        return 1;
}

// ��������ȡ�ؼ�����
int get_perform_type() { return ON_ME; }

// �������ܷ�ʹ���ؼ�
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
}
