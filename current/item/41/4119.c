
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("寒铁");
        set_picid_1(3512);
        set_picid_2(3512);
        set_unit("块");
        set_value(2500);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "铁矿石通过吸收千年之精华而形成的稀有金属"; 
}
