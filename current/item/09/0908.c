
// 自动生成：/make/item/make09

#include <equip.h>
inherit FAMILY_EQUIP;

int get_item_color() { return 1; }
int is_newplayer() { return 1;}

// 函数：构造处理
void create()
{
        set_name("龙纹玉佩");
        set_picid_1(4950);
        set_picid_2(4950);
        set_unit("面");
        set_family_name("");      
        set_max_lasting(1099);
        set_lasting(1099);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);          

}

// 函数：获取描述
string get_desc() 
{ 
        return sprintf("新手信物 %d级",get_item_level()); 
}

string get_family_desc() 
{ 
	return "代表初学者的信物，\n右键点击使用可直接传送回新手村。\n冷却时间：1分钟";
}