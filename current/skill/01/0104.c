
inherit SKILL;

// 函数：基本技能
int is_basic_skill() { return 1; }

// 函数：构造处理
void create() 
{ 
        set_number(0104);
        set_name( "腾挪躲闪" );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_dodge_rate(me); }

// 函数：获取描述
string get_desc() 
{
        return "［腾挪躲闪］轻功心法，能提升修炼者的回避能力。每级增加0.15％的回避率。\n";
}
