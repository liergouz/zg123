
inherit GOOD;

// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(9921);
        set_picid_2(9921);
        set_unit( "��" );
        set_buy_price(50);
        set_buy_range(70);
        set_sell_price(70);
        set_sell_range(130);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// ��������ȡ����
string get_city_name() { return "����"; }

// ��������ȡ����
string get_desc()
{
        return "����Ʒ�ݺ����ز�";
}
