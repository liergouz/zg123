
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0251);
        set_name( "��ħ����" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "02510"->can_perform(me);
	__DIR__ "02514"->can_perform(me);
	__DIR__ "02513"->can_perform(me);
	__DIR__ "02516"->can_perform(me);
	__DIR__ "02517"->can_perform(me);
	__DIR__ "02512"->can_perform(me);
	__DIR__ "02515"->can_perform(me);   
}

// ������ɾ�����⼼
void remove_perform( object me )
{
//        send_user( me, "%c%w%w", 0x50, 0xffff, 02511 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02512 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02513 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02514 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02515 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02516 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02517 );
}

// �������ؼ�����
void recount_char( object me ) { }

// ��������ȡ����
string get_desc() 
{
        return "�۷�ħ�����ݽ������������⼼��\n";
}
