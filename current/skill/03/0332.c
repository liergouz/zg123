
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0332);
        set_name( "强化飞仙剑法" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
//	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_cp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［强化飞仙剑法］提升使用剑的法术攻击力，每级提升3点";
}
