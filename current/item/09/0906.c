
// 自动生成：/make/item/make09

#include <equip.h>
inherit FAMILY_EQUIP;

int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name("如意玉牌");
        set_picid_1(906);
        set_picid_2(906);
        set_unit("个");
        set_family_name("昆仑");      
        set_max_lasting(1099);
        set_lasting(1099);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);          

}

// 函数：获取描述
string get_desc() 
{ 
        return sprintf("门派信物 %d级",get_item_level()); 
}

string get_family_desc() 
{ 
	return "昆仑的门派信物，\n用天子赏赐的玉如意雕刻而成。\n右键点击使用可直接传送回昆仑山。\n冷却时间：1分钟\n每次使用花费50金。";
}