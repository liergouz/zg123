
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0403);
        set_name( "����" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_pp(me); }

// ��������ȡ����
string get_desc() 
{
        return "�������ݾ�������֮����ʹ�����߸��õصֿ���������ɵ��˺���ÿ������1�㷨����������\n";
}
