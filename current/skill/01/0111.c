
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0111);
        set_name( "����ȭ��" );
}

// �������ܷ����⼼
void can_perform( object me )
{
}

// ������ɾ�����⼼
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 01111 );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_ap(me); }

// ��������ȡ����
string get_desc() 
{
        return "�ۻ���ȭ�ţ����ŵ�ȭ���书�������ӿ�����ս��������ÿ������1����ֵ�����������\n";
}
