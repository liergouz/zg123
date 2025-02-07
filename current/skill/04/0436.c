
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0436);
        set_name( "药物强化" );
}

int get_learn_money() {return 20000; }

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_other(me); }

// 函数：获取描述
string get_desc() 
{
        return "［药物强化］ 帮派特殊技，提升玩家使用药物恢复的效果，每级增加4％；减少使用药物后冷却时间，每级减少1秒。\n";
}
