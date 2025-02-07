#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：成品编号
int get_fin_type() { return 1600; }

// 函数：构造处理
void create()
{
        set_name( "铜制机关构件" );
        set_picid_1(4206);
        set_picid_2(4206);
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "一些机关的基本部件";
}

