
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0222);
        set_name( "刀剑格挡" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "02221"->can_perform(me);
        __DIR__ "02222"->can_perform(me);
}

// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_dp(me); 
	USER_ENERGY_D->count_hit_rate(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［刀剑格挡］提升使用刀和剑的防御力，每级提升 1.1 点。提升爆击率，每级提升0.05％\n";
}
