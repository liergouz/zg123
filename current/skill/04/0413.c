
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0413);
        set_name( "������ͨ" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "04130"->can_perform(me);
        __DIR__ "04131"->can_perform(me);
        __DIR__ "04132"->can_perform(me);
//        __DIR__ "04133"->can_perform(me);
        __DIR__ "04134"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
	send_user( me, "%c%w%w", 0x50, 0xffff, 04130 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04131 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04132 );
//        send_user( me, "%c%w%w", 0x50, 0xffff, 04133 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04134 );
}

// ��������ȡ����
string get_desc() 
{
        return "�۵�����ͨ��ʹ�÷�ֽ�ٻ����䡢������񽫡���ʬЭ��ս����\n";
}
