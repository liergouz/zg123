
inherit GOOD;

// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(9941);
        set_picid_2(9941);
        set_unit( "��" );
        set_buy_price(100);
        set_buy_range(200);
        set_sell_price(120);
        set_sell_range(380);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// ��������ȡ����
string get_city_name() { return "κ��"; }

// ��������ȡ����
string get_desc()
{
        return "����Ʒ��κ���ز�";
}
