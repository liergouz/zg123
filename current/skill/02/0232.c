
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0232);
        set_name( "������" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "02321"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02321 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// ��������ȡ����
string get_desc() 
{
        return "�۽����񵲣�����ʹ�ý��ķ�������ÿ������ 1.2 ��\n";
}
