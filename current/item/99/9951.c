
inherit GOOD;

// ���������촦��
void create()
{
        set_name( "��ɰ��" );
        set_picid_1(9951);
        set_picid_2(9951);
        set_unit( "��" );
        set_buy_price(200);
        set_buy_range(300);
        set_sell_price(150);
        set_sell_range(650);

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
