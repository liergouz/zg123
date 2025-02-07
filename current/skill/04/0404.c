
inherit SKILL;

// 函数：基本技能
int is_basic_skill() { return 1; }

// 函数：构造处理
void create() 
{ 
        set_number(0404);
        set_name( "健身" );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_max_hp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［健身］强身健体之术，能大大提升修行者的气血上限。每级可提升1％的气血上限值。\n";
}
