
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0414);
        set_name( "���취��" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "04147"->can_perform(me);
	__DIR__ "04143"->can_perform(me);
	__DIR__ "04144"->can_perform(me);
	__DIR__ "04145"->can_perform(me);
	__DIR__ "04148"->can_perform(me);	
	__DIR__ "04141"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04143 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04144 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04145 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04147 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04148 );
}

// ��������ȡ����
string get_desc() 
{
        return "�����취�������а�����������˺�������֡�\n";
}
