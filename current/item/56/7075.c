
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit ARMOR;
//套装组件标志
int is_suit()	{ return 1;}	
//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 7; }
//套装名字
string get_suit_name() { return "灵鹿"; }	//属于某某套装
// 函数：构造处理
void create()
{
        set_name("灵鹿皮衣");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(75);
        set_value(10000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 149);
        set("cp+", 0);
        set("pp+", 260);
        set("sp+", 0);
        set("hp+", 105);
        set("mp+", 147);
	set_item_color(3);	//紫色
	set_bind(4);		//捡取绑定
	set_hide(0);		//已鉴定
        setup();
}

// 函数：获取描述
string get_desc()
{
        return "灵鹿皮衣";
}

// 函数：获取套装描述
string get_suit_desc()
{
        return "灵鹿套装其中之一,相传穿上全套就会拥有神秘的力量";
}

