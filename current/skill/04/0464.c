
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}
// ���������촦��
void create() 
{ 
        set_number(0464);
        set_name( "ǿ��˳�취��" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_hp(me); 
//	USER_ENERGY_D->count_dp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ��˳�취���������Ѫ���ޣ�ÿ������4��";
}
