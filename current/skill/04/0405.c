
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0405);
        set_name( "ڤ˼" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_max_mp(me); }

// ��������ȡ����
string get_desc() 
{
        return "��ڤ˼�� ��������֮�����ܴ�����������ߵķ��������ޡ�ÿ��������1���ķ���������ֵ��\n";
}
