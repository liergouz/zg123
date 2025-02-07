
inherit ITEM;
inherit COMBINED;

// 函数：构造处理
void create()
{
        set_name( "僵尸符" );
        set_picid_1(0413);
        set_picid_2(0413);
        set_unit( "张" );
        set_value(3500);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "专门用于召唤僵尸";
}
