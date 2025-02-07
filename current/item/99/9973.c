
inherit GOOD;

// 函数：构造处理
void create()
{
        set_name( "漆器" );
        set_picid_1(9973);
        set_picid_2(9973);
        set_unit( "包" );
        set_buy_price(500);
        set_buy_range(300);
        set_sell_price(600);
        set_sell_range(900);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "燕国"; }

// 函数：获取描述
string get_desc()
{
        return "［商品］燕国特产";
}
