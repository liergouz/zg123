
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0402);
        set_name( "�о�" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_cp(me); }

// ��������ȡ����
string get_desc() 
{
        return "���о����ж����ģ�ʹ�����ߵľ��񾳽����һ��¥��������������������ÿ������1�㷨����������\n";
}
