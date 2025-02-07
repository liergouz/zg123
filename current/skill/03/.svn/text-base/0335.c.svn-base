
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0335);
        set_name( "强化刀剑格挡" );
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
        return "［强化刀剑格挡］提升使用刀和剑的防御力，每级提升 1.5 点；提升爆击率，每级提升0.08％";
}
