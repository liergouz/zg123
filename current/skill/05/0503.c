
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0503);
        set_name( "������" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "05031"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 05031 );
}

// ��������ȡ����
string get_desc() 
{
        return "���������ݰ��䷽����ҩ��\n";
}
