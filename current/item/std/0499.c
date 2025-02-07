
inherit ITEM;
inherit COMBINED;

// 函数：构造处理
void create()
{
        set_name( "回魂符" );
        set_picid_1(0409);
        set_picid_2(0409);
        set_unit( "张" );
        set_value(3000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "战场上使用，15 秒后自动复活";
}
