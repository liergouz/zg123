
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0445);
        set_name( "ǿ����˵���" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_max_mp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ����˵����������������ޣ�ÿ������6�㣻������������Ѫ���ޣ�ÿ������1.5��";
}
