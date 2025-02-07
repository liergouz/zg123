
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0381);
        set_name( "强化漫天花雨" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
//	USER_ENERGY_D->count_max_hp(me); 
	USER_ENERGY_D->count_ap(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［强化漫天花雨］提升使用暗器的攻击力，每级提升2点攻击力";
}
