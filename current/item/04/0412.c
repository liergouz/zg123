#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;


//圣诞节物品
int is_christmas() { return 1;}

void reset()
{
        if( gone_time( get_drop_time() ) > 7200 )    // 2小时
        {
                remove_from_scene();
                destruct( this_object() );
        }
}
// 函数：构造处理
void create()
{
        set_name("长统袜");
        set_picid_1(9983);
        set_picid_2(9983);
        set_unit("条");
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	return "圣诞节时用来装礼物的袜子。\n可交给圣诞老人兑换礼物。";
}

