
inherit GOOD;

// 函数：构造处理
void create()
{
        set_name( "玳瑁" );
        set_picid_1(9962);
        set_picid_2(9962);
        set_unit( "包" );
        set_buy_price(1000);
        set_buy_range(500);
        set_sell_price(1100);
        set_sell_range(900);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "楚国"; }

// 函数：获取描述
string get_desc()
{
        return "［商品］楚国特产";
}
