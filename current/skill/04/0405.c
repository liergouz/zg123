
inherit SKILL;

// 函数：基本技能
int is_basic_skill() { return 1; }

// 函数：构造处理
void create() 
{ 
        set_number(0405);
        set_name( "冥思" );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_max_mp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［冥思］ 精神修炼之法，能大大提升修行者的法术力上限。每级可提升1％的法术力上限值。\n";
}
