
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0418);
        set_name( "��ѧ����" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "04181"->can_perform(me);
        __DIR__ "04182"->can_perform(me);
        __DIR__ "04183"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04181 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04182 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04183 );
}
// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_mp(me); 
	USER_ENERGY_D->count_pp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "����ѧ�����������������ޣ�ÿ������ 4 �㣻����������������ÿ������ 2 ��\n";
}
