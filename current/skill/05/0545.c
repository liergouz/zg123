
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0545);
        set_name( "ǿ�����Ŷݼ�" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_pp(me); 
	USER_ENERGY_D->count_dp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ�����Ŷݼף����������������ÿ������2�㣻����������������ÿ������2��";
}
