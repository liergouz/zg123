
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0121);
        set_name( "��������" );
}

// �������ܷ����⼼
void can_perform( object me )
{
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 01211 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_ap(me); }

// ��������ȡ����
string get_desc() 
{
        return "�ۻ������������ŵ����������ӳֵ�ʱ�����ս������ÿ������1�㵶������������\n";
}
