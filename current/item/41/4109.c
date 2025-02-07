
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 320; }

// 函数：构造处理
void create()
{
        set_name("蓝魔之泪");
        set_picid_1(8915);
        set_picid_2(8915);
        set_unit("个");
        set_value(400);
        set_amount(1);
}

// 函数：获取描述
int get_item_value() {return 1 ;}
int get_item_value_2() {return 1 ;}
string get_desc() 
{ 
        return "相传是由蓝色精灵流下的怨泪结晶体"; 
}
