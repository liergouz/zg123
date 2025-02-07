
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0365);
        set_name( "唐门心法" );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }

// 函数：获取描述
string get_desc() 
{
        return "［唐门心法］提升暗器攻击的命中率，每级提升0.2％。提升暗器攻击的爆击率，每级提升0.1％。\n";
}
