
// 自动生成：/make/item/make89b

inherit ITEM;

// 函数：宝石识别
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int is_diamond() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：宝石属性
string get_diamond_type() { return "ap%"; }

// 函数：构造处理
void create()
{
        set_name("完美玉白晶石");
        set_picid_1(8956);
        set_picid_2(8956);
        set_unit("块");
        set_value(50000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "［装备合成材料］增加攻击百分比"; 
}
