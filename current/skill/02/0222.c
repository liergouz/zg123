
inherit SKILL;

// ���������촦��
void create() 
{ 
        set_number(0222);
        set_name( "������" );
}

// �������ܷ����⼼
void can_perform( object me )
{
        __DIR__ "02221"->can_perform(me);
        __DIR__ "02222"->can_perform(me);
}

// �������ؼ�����
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_dp(me); 
	USER_ENERGY_D->count_hit_rate(me); 
}

// ��������ȡ����
string get_desc() 
{
        return "�۵����񵲣�����ʹ�õ��ͽ��ķ�������ÿ������ 1.1 �㡣���������ʣ�ÿ������0.05��\n";
}
