
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0422);
        set_name( "��������" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "04221"->can_perform(me);
        __DIR__ "04222"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04221 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04222 );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_cp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "���������У�����������������ÿ������ 2 �㡣\n";
}
