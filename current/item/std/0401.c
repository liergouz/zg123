
inherit ITEM;
inherit COMBINED;

// ��������Ʒ��������
int get_max_combined() { return 999; }

// ���������촦��
void create()
{
        set_name( "��ֽ" );
        set_picid_1(0401);
        set_picid_2(0401);
        set_unit( "��" );
        set_value(10);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ʹ�÷����ı���Ʒ";
}
