
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0329);
        set_name( "������ת" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "03291"->can_perform(me);
        __DIR__ "03292"->can_perform(me);
        __DIR__ "03293"->can_perform(me);
        __DIR__ "03294"->can_perform(me);
        __DIR__ "03295"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 03291 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03292 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03293 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03294 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_max_hp(me); }

// ��������ȡ����
string get_desc() 
{
        return "��������ת��������Ѫ���ޣ�ÿ������ 4 ��\n";
}
