
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0333);
        set_name( "ǿ����Ԫ����" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_mp(me); 
	USER_ENERGY_D->count_pp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ����Ԫ�����������������ޣ�ÿ������2.5�㣻�����������������ޣ�ÿ������1.5��";
}
