
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0385);
        set_name( "强化唐门心法" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_pp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［强化唐门心法］提升玩家装备暗器时的法术防御力，每级提升3点";
}
