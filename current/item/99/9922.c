
inherit GOOD;

// 函数：构造处理
void create()
{
        set_name( "水果" );
        set_picid_1(9922);
        set_picid_2(9922);
        set_unit( "包" );
        set_buy_price(100);
        set_buy_range(50);
        set_sell_price(80);
        set_sell_range(120);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "韩国"; }

// 函数：获取描述
string get_desc()
{
        return "［商品］韩国特产";
}
