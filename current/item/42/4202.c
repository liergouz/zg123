
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数，蓝色物品
int is_grey() {return 2;}

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 195; }

// 函数：构造处理
void create()
{
        set_name("熊皮");
        set_picid_1(3553);
        set_picid_2(3553);
        set_unit("块");
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "熊身上御寒防护之体肤"; 
}
