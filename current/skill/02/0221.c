
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0221);
        set_name( "���޵���" );
}

// �������ܷ����⼼
void can_perform( object me )
{
	__DIR__ "02210"->can_perform(me);
        __DIR__ "02211"->can_perform(me);
        __DIR__ "02212"->can_perform(me);
        __DIR__ "02213"->can_perform(me);
        __DIR__ "02214"->can_perform(me);
        __DIR__ "02215"->can_perform(me);
        __DIR__ "02216"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
	send_user( me, "%c%w%w", 0x50, 0xffff, 02210 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02211 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02212 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02213 );
//        send_user( me, "%c%w%w", 0x50, 0xffff, 02214 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02215 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02216 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_ap(me); }

// ��������ȡ����
string get_desc() 
{
        return "�����޵���������ʹ�õ��Ĺ�������ÿ������ 2.5 �㹥����\n";
}
