
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0660);
        set_name( "�������⼼" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 660, 6601, 0, 0, 0, "��������" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "��������" );
}
