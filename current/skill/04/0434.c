
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0434);
        set_name( "�ر�ǿ��" );
}

int get_learn_money() {return 31000; }

// �������ؼ�����
void recount_char( object me ) { USER_ENERGY_D->count_dodge_rate(me); }

// ��������ȡ����
string get_desc() 
{
        return "�ۻر�ǿ���� �������⼼����������ҵĻر��ʣ�ÿ������1.5����\n";
}
