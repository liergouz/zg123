
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0591);
        set_name( "���Ŷݼ�" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "05911"->can_perform(me);
        __DIR__ "05912"->can_perform(me);
        __DIR__ "05913"->can_perform(me);
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 05911 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05912 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 05913 );
}

// ��������ȡ����
string get_desc() 
{
        return "�����Ŷݼףݿ�ѧϰ�ֿ��˺��ļ��������ס���ʹ�����첼��\n";
}
