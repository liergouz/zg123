
#include <ansi.h>
#include <skill.h>

#define JOB_SCHOLAR_D   "/inh/job/scholar"

#define THIS_PERFORM    00402
#define PF_NAME        "ռ��"

// ��������ȡ����
string get_desc( object me ) 
{ 
        return "��" PF_NAME "��\nʹ�Է���Ѫ����������\n"; 
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        if( !arg || arg == "" ) 
                JOB_SCHOLAR_D->do_augur(me, "?");
        else    JOB_SCHOLAR_D->do_augur(me, arg);

        return 1;
}

// ��������ȡָ������
int get_perform_type() { return ON_ME_7; }

// �������ܷ�ʹ��ָ��
void can_perform( object me )
{
        if( me->is_scholar() ) 
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
}
