
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0430);
        set_name( "伤害强化" );
}

int get_learn_money() {return 26000; }

// 函数：重计属性
//void recount_char( object me ) { USER_ENERGY_D->count_max_mp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［伤害强化］ 帮派特殊技，可增加玩家用物理攻击对目标造成的伤害。\n";
}
