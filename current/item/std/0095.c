
#include <cmd.h>
#include <ansi.h>

inherit ITEM;

int get_item_color() { return 2; }
// 函数：构造处理
void create()
{
        set_name("王之号角");
        set_picid_1(0095);
        set_picid_2(0095);
        set_unit("只");
        set_value(1998);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "创立帮派的必备品";
}
