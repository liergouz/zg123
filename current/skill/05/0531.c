
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0531);
        set_name( "�Ի��" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "05310"->can_perform(me);
        __DIR__ "05311"->can_perform(me);
        __DIR__ "05312"->can_perform(me);
        __DIR__ "05313"->can_perform(me);
        __DIR__ "05314"->can_perform(me);        
        __DIR__ "05315"->can_perform(me);        
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 05310 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05311 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05312 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05313 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05314 );             
}

// ��������ȡ����
string get_desc() 
{
        return "���Ի��������������⼼�������Ի����Ϊ������á���ÿ����׷��0.05���ķ�������Ч����\n";
}
