
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0202);
        set_name( "�м�֮��" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// ��������ȡ����
string get_desc() 
{
        return "���м�֮���ݷ������ƵĻ��������������������ߵ������������ÿ������1�������������\n";
}
