
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0365);
        set_name( "�����ķ�" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }

// ��������ȡ����
string get_desc() 
{
        return "�������ķ����������������������ʣ�ÿ������0.2�����������������ı����ʣ�ÿ������0.1����\n";
}
