
inherit SKILL;
//ǿ�����ܱ�־
int is_enhance_skill() {return 1;}

// ���������촦��
void create() 
{ 
        set_number(0385);
        set_name( "ǿ�������ķ�" );
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_pp(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "��ǿ�������ķ����������װ������ʱ�ķ�����������ÿ������3��";
}
