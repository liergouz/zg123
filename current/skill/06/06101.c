
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0610);
        set_name( "��ʳ���⼼" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 610, 6101, 0, 0, 0, "��ʳ����" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "��ʳ����" );
}
