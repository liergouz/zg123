
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0161);
        set_name( "����Ͷ��" );
}

// �������ܷ����⼼
void can_perform( object me )
{
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 01611 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 01612 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_ap(me); }

// ��������ȡ����
string get_desc() 
{
        return "�۰���Ͷ��ݰ������У�������ʹ�ð���ʱ�����ս������ÿ������1.5�İ�������������\n";
}
