
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0371);
        set_name( "ǿ��̫����ȭ" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
//	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_ap(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ��̫����ȭ����������ʱ�Ĺ�������ÿ������4�㹥����";
}
