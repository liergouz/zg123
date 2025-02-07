
// 自动生成：/make/item/make09

#include <equip.h>
inherit FAMILY_EQUIP;

int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name("云门旗");
        set_picid_1(907);
        set_picid_2(907);
        set_unit("面");
        set_family_name("云梦泽");      
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
	return "云梦泽的门派信物，\n云梦祖师施本门法术所用之旗。\n右键点击使用可直接传送回云梦泽。\n冷却时间：1分钟\n每次使用花费50金。";
}