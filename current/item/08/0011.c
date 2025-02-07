#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_type() { return ITEM_TYPE_SPECIAL; }

int is_mirror() {return 1;}

// 函数：构造处理
void create()
{
        set_name("白银鉴定镜");
        set_picid_1(3561);
        set_picid_2(3561);
        set_value(3000);
        set("level2", 60);
        set_amount(1);
}

int is_usable() {return 1;}

// 函数：获取描述
string get_desc() 
{		
	return "有法力的镜子，将镜子放置到要鉴定的装备处即可。\n可以鉴定60级以下的所有装备。";
}
