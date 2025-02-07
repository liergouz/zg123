#include <effect.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 1; }

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("红球");
        set_picid_1(3567);
        set_picid_2(3567);
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "用红色与黑色丝线编织的球，可用来兑奖"; 
}
