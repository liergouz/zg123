
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0333);
        set_name( "强化混元真气" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_mp(me); 
	USER_ENERGY_D->count_pp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［强化混元真气］提升法力上限，每级提升2.5点；提升法术防御力上限，每级提升1.5点";
}
