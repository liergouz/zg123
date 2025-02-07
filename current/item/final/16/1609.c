#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：成品编号
int get_fin_type() { return 1609; }

// 函数：构造处理
void create()
{
        set_name( "永动核心" );
        set_picid_1(4174);
        set_picid_2(4174);
        set_value(1000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "一些机关的基本部件";
}

