
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("竹筒");
        set_picid_1(4901);
        set_picid_2(4901);
        set_unit("个");
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "高山寒竹的竹节制作而成"; 
}
