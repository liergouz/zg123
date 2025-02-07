
inherit GOOD;

// 函数：构造处理
void create()
{
        set_name( "油漆" );
        set_picid_1(9942);
        set_picid_2(9942);
        set_unit( "包" );
        set_buy_price(500);
        set_buy_range(300);
        set_sell_price(450);
        set_sell_range(850);

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "魏国"; }

// 函数：获取描述
string get_desc()
{
        return "［商品］魏国特产";
}
