
inherit SKILL;

// ��������������
int is_basic_skill() { return 1; }

// ���������촦��
void create() 
{ 
        set_number(0401);
        set_name( "����ѧ˵" );
}

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_max_mp(me); }

// ��������ȡ����
string get_desc() 
{
        return "�۵���ѧ˵���̺��ḻ�����ѧ˵�������������ߵķ��������ޡ�ÿ������5�㷨�����ޡ�\n";
}
