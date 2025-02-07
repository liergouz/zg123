
// 自动生成：/make/item/make49
#include <item.h>
inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可对目标使用的物品
int get_item_type_2() { return ITEM_TYPE_2_USABLE2; }

// 函数：构造处理
void create()
{
        set_name("乾坤绳");
        set_picid_1(8700);
        set_picid_2(8700);
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "能捕抓怪物的仙绳，在捕抓宠物时候的必须用品。";
}

// 函数：使用效果
int get_use_effect( object me, object who ) { return __FILE__ ->get_use_effect_callout(me, who); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object who )
{
        int damage;
        object user, owner, *char;      
        int z, x, y, i;  
        "/skill/00/00051"->main(me, who, 0, 0, "");
        return 0;
}