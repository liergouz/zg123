
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("铁矿石");
        set_picid_1(4906);
        set_picid_2(4906);
        set_unit("块");
        set_value(400);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "含有丰富的铁元素的矿石"; 
}
