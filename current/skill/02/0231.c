
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0231);
        set_name( "���ɽ���" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "02310"->can_perform(me);
        __DIR__ "02311"->can_perform(me);
        __DIR__ "02312"->can_perform(me);
        __DIR__ "02315"->can_perform(me);        
        __DIR__ "02313"->can_perform(me);                        
        __DIR__ "02314"->can_perform(me);
        __DIR__ "02316"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02311 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02312 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02313 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02314 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02315 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02316 );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_cp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "�۷��ɽ���������ʹ�ý��ķ�����������ÿ������ 2.5 �㡣\n";
}
