
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0421);
        set_name( "��˵���" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "04211"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04211 );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_max_mp(me); 
        USER_ENERGY_D->count_cp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "�۴�˵����������������ޣ�ÿ������ 4 �㡣�������������ı����ʣ�ÿ������0.05����\n";
}
