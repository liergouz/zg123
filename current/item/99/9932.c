
inherit GOOD;

// ���������촦��
void create()
{
        set_name( "����" );
        set_picid_1(9932);
        set_picid_2(9932);
        set_unit( "��" );
        set_buy_price(400);
        set_buy_range(600);
        set_sell_price(400);
        set_sell_range(1600);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// ��������ȡ����
string get_city_name() { return "�Թ�"; }

// ��������ȡ����
string get_desc()
{
        return "����Ʒ���Թ��ز�";
}
