
inherit ITEM;
inherit COMBINED;

// ��������ʯʶ��
int is_diamond_3() { return 1; }

// ���������촦��
void create()
{
        set_name( "��ʯ��Ƭ" );
        set_picid_1(8900);
        set_picid_2(8900);
        set_unit( "��" );
        set_value(30000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�۱�ʯ�ϳɲ��ϣݷ��õ���ȱ��ʯ���ܺϳ�������ʯ";
}
