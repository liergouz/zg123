
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0349);
        set_name( "ĥ��" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_ap(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ĥ����������Ѫ���ޣ�ÿ������ 5 �㣬������������ÿ������ 3 ��";
}
