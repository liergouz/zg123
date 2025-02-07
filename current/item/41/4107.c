
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("石炭");
        set_picid_1(9004);
        set_picid_2(9004);
        set_unit("块");
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "受地质影响而形成的矿物类"; 
}
