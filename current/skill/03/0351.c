
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0351);
        set_name( "ǿ������ǹ��" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
//	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_hit_rate(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ������ǹ�������ʹ��ǹ�����������У�ÿ������3������";
}
