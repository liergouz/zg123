
inherit GOOD;

// ���������촦��
void create()
{
        set_name( "ʯ��" );
        set_picid_1(9952);
        set_picid_2(9952);
        set_unit( "��" );
        set_buy_price(500);
        set_buy_range(500);
        set_sell_price(500);
        set_sell_range(1000);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// ��������ȡ����
string get_city_name() { return "�ع�"; }

// ��������ȡ����
string get_desc()
{
        return "����Ʒ���ع��ز�";
}
