
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
//套装组件标志
int is_suit()	{ return 1;}	
//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 4; }
//套装名字
string get_suit_name() { return "猎豹"; }	//属于某某套装
// 函数：构造处理
void create()
{
        set_name("猎豹头巾");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(65);
        set_value(15000);
        set_max_lasting(16099);
        set("ap+", 0);
        set("dp+", 93);
        set("cp+", 0);
        set("pp+", 68);
        set("sp+", 33);
        set("hp+", 60);
        set("mp+", 0);
	set_item_color(3);	//紫色
	set_bind(4);		//捡取绑定
	set_hide(0);		//已鉴定
        setup();
}

// 函数：获取描述
string get_desc()
{
        return "猎豹头巾";
}

// 函数：获取套装描述
string get_suit_desc()
{
        return "猎豹套装其中之一,相传穿上\n全套就会拥有神秘的力量";
}

