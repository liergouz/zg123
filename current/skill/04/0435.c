
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0435);
        set_name( "����ǿ��" );
}

int get_learn_money() {return 30000; }

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }

// ��������ȡ����
string get_desc() 
{
        return "�۱���ǿ���� �������⼼����������ҵı����ʣ�ÿ������1����\n";
}
